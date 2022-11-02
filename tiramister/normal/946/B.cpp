#include <iostream>

using lint = long long;

int main() {
    lint a, b;
    std::cin >> a >> b;

    while (a > 0 && b > 0) {
        if (a >= b * 2) {
            a %= (b * 2);
        } else if (b >= a * 2) {
            b %= (a * 2);
        } else {
            break;
        }
    }

    std::cout << a << " " << b << std::endl;
    return 0;
}