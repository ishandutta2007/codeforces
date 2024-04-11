#include <iostream>

using lint = long long;

void solve() {
    lint d, m;
    std::cin >> d >> m;

    lint ans = 1;
    for (int k = 0; k < 40; ++k) {
        lint x = (1LL << k);
        if (d < x) break;
        (ans *= (std::min(d - x + 1, x) + 1) % m) %= m;
    }

    std::cout << (ans + m - 1) % m << std::endl;
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