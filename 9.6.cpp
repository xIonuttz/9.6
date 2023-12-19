// Square.h (Square class)
#pragma once

class Square {
private:
    double side;

public:
    Square(double side) : side(side) {}

    double computeArea() const {
        return side * side;
    }
};

// Test.h (Test class for unit testing)
#pragma once
#include "Square.h"  // Include the header file with the Square class

class Test {
public:
    static bool isSquareAreaValid(double size, double expectedArea);
};

// Test.cpp (Implementation of Test class)
#include "Test.h"

bool Test::isSquareAreaValid(double size, double expectedArea) {
    if (size < 0) {
        // Negative size is invalid
        return false;
    }

    // Instantiate the Square class
    Square square(size);

    // Compute the area
    double computedArea = square.computeArea();

    // Compare with expected area
    if (computedArea == expectedArea) {
        return true;  // Valid
    }
    else {
        return false;  // Invalid
    }
}

// main.cpp (Driver program to test)
#include "Test.h"
#include <iostream>

int main() {
    Test test;

    // Test cases
    std::cout << "Test 1: " << (test.isSquareAreaValid(4, 16) ? "Pass" : "Fail") << std::endl;
    std::cout << "Test 2: " << (test.isSquareAreaValid(400, 160000) ? "Pass" : "Fail") << std::endl;
    std::cout << "Test 3: " << (test.isSquareAreaValid(0, 0) ? "Pass" : "Fail") << std::endl;
    std::cout << "Test 4: " << (test.isSquareAreaValid(-4, 0) ? "Pass" : "Fail") << std::endl;

    return 0;
}
