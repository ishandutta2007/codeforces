#include <iostream>
#include <vector>

using lint = long long;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) {
        int n;
        std::cin >> n;

        lint a = 0, b = 0;
        while (n--) {
            lint x;
            std::cin >> x;
            a += x;
            b ^= x;
        }

        std::cout << 2 << "\n"
                  << b << " " << a + b << std::endl;
    }
    return 0;
}