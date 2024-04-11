#include <iostream>
#include <iomanip>
#include <cmath>

// x^2 + l^2 = (x + h)^2
// l^2 = 2hx + h^2
// x = (l^2 - h^2) / 2h

using ldouble = long double;

int main() {
    ldouble h, l;
    std::cin >> h >> l;
    std::cout << std::fixed << std::setprecision(10)
              << (l * l - h * h) / (h * 2)
              << std::endl;
    return 0;
}