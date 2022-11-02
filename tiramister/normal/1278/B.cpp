#include <iostream>
#include <cmath>

using lint = long long;

void solve() {
    lint a, b;
    std::cin >> a >> b;

    for (lint m = 0;; ++m) {
        lint d = std::abs(a - b);
        lint s = m * (m + 1) / 2;
        if (d <= s && (s - d) % 2 == 0) {
            std::cout << m << std::endl;
            return;
        }
    }
}

int main() {
    int q;
    std::cin >> q;
    while (q--) solve();
    return 0;
}