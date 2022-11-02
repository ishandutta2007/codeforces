#include <iostream>
#include <vector>

using lint = long long;

void solve() {
    lint x;
    std::cin >> x;

    if (x == 0) {
        std::cout << 1 << " " << 1 << std::endl;
        return;
    }

    for (lint p = 1; p * p <= x; ++p) {
        if (x % p != 0) continue;

        auto q = x / p;
        if ((p + q) % 2 != 0) continue;

        lint n = (q + p) / 2,
             l = (q - p) / 2;

        lint ok = 0, ng = n + 1;
        // n / ok >= l
        while (ng - ok > 1) {
            lint mid = (ok + ng) / 2;
            if (n / mid >= l) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        if (ok == 0 || n / ok != l) continue;

        std::cout << n << " " << ok << std::endl;
        return;
    }

    std::cout << -1 << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}