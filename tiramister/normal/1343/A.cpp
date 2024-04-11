#include <iostream>

using lint = long long;

void solve() {
    lint n;
    std::cin >> n;

    for (int k = 2;; ++k) {
        lint p = (1LL << k) - 1;
        if (n % p != 0) continue;

        std::cout << n / p << std::endl;
        return;
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}