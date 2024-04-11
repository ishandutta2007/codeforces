#include <iostream>
#include <string>

std::string a, b;

int main() {
    std::cin >> a >> b;
    if (a == b) std::cout << a << '\n';
    else std::cout << "1\n";
}