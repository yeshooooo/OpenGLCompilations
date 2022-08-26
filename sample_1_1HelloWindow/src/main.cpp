#include <glad/glad.h>
#include <glfw3.h>
#include <iostream>

void processInput(GLFWwindow* window);





int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__ 
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	// ��������
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	//GLFW�����ڵ�����������Ϊ��ǰ�̵߳�������
	glfwMakeContextCurrent(window);

	//GLAD
	// glad: ��������OpenGL����ָ��
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	// ��Ⱦѭ��
	while (!glfwWindowShouldClose(window)) {
		processInput(window); // ����esc���˳�����
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //״̬����
		glClear(GL_COLOR_BUFFER_BIT); //״̬ʹ��
		// glfw: ��������������ѯIO�¼�����������/�ͷš�����ƶ��ȣ�
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	// glfw: ����ǰ������GLFW�ȹ���Դ. 
	glfwTerminate();
	return 0;
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}

}