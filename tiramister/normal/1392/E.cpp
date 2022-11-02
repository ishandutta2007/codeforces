#include <iostream>
#include <vector>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

using lint = long long;

void solve() {
    int n;
    std::cin >> n;

    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            std::cout << (x % 2 == 0 ? 0 : 1LL << (x + y - 1)) << " ";
        }
        std::cout << std::endl;
    }

    int q;
    std::cin >> q;
    while (q--) {
        lint k;
        std::cin >> k;

        int x = 0, y = 0, i = 0;
        std::cout << x + 1 << " " << y + 1 << std::endl;

        while (x != n - 1 || y != n - 1) {
            int b = (k >> i) & 1;

            if ((b == 0) == (x % 2 == 0)) {
                ++y;
            } else {
                ++x;
            }

            std::cout << x + 1 << " " << y + 1 << std::endl;
            ++i;
        }
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}