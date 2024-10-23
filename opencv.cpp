#include <opencv2/opencv.hpp>
#include <stdio.h>

int main() {
    // Open the default camera (usually camera index 0)
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        printf("Error: Could not open the camera.\n");
        return -1;
    }

    cv::Mat frame;

    // Capture a single frame
    cap >> frame;

    // Check if the frame is empty
    if (frame.empty()) {
        printf("Error: Could not capture an image.\n");
        return -1;
    }

    // Save the captured image
    if (cv::imwrite("captured_image.jpg", frame)) {
        printf("Image captured and saved as captured_image.jpg\n");
    } else {
        printf("Error: Could not save the image.\n");
    }

    // Release the camera
    cap.release();
    return 0;
}

