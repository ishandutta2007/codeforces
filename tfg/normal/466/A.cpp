#include <iostream>

int main() {
    int n, m, a, b;
    std::cin >> n >> m >> a >> b;
    b = std::min(m * a, b);
    std::cout << std::min(n / m * b + n % m * a, n / m * b + b) << '\n';
}