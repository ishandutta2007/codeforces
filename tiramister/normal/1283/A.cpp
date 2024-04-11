#include <iostream>

int main() {
    int q;
    std::cin >> q;

    while (q--) {
        int h, m;
        std::cin >> h >> m;
        std::cout << (23 - h) * 60 + (60 - m) << std::endl;
    }
    return 0;
}