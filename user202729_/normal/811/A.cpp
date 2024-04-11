#include <iostream>
#include <cmath>

int a, b;

int main() {
    std::cin >> a >> b;
    int na = std::floor(std::sqrt(a)), nb = std::floor(std::sqrt(b + 0.25) - 0.5);
    std::cout << ((na > nb) ? "Valera\n" : "Vladik\n");
}