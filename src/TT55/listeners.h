namespace TT55::Listeners {

    void processInputListener(GLFWwindow* window) {
        
        // close window if `ESCAPE_KEY` is pressed
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
            static int timeout = 10;

            if (TT55::Window.wireframe_toggle_time > timeout) {
                if (!TT55::Window.wireframe) {
                    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                    std::cout << "Wireframe -> on" << std::endl;
                    TT55::Window.wireframe = true;
                    TT55::Window.wireframe_toggle_time = 0;
                } else {
                    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                    std::cout << "Wireframe -> off" << std::endl;
                    TT55::Window.wireframe = false;
                    TT55::Window.wireframe_toggle_time = 0;
                }
            }
        }

        if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
            static int timeout = 6;
            static int current = 0;

            if (current > timeout) {
                TT55::Window.shader = Shader("src/shaders/default.vert", "src/shaders/default.frag");
                std::cout << "Reloaded Shaders" << std::endl;
                current = 0;
            } else current++;
        }
    }

    
} // namespace TT55::Listeners
