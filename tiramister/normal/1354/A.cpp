#include <iostream>

using lint = long long;

void solve() {
    lint a, b, c, d;
    std::cin >> a >> b >> c >> d;

    if (a <= b) {
        std::cout << b << "\n";
        return;
    }

    a -= b;

    auto x = c - d;
    if (x <= 0) {
        std::cout << -1 << "\n";
        return;
    }

    auto t = (a + x - 1) / x;
    std::cout << b + c * t << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}