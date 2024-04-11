#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    const long double M_PI = 3.141592653589793238462643383279503;
    long double n, r;
    std::cin >> n;
    std::cin >> r;
    std::cout << std::setprecision(15) <<
            n * r * r * sin(M_PI / n) * sin(M_PI / (2 * n))
            / sin ((1. - 1.5 / n) * M_PI);
}