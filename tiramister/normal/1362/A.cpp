#include <iostream>

using lint = long long;

int shift(lint& x) {
    int ret = 0;
    while (x % 2 == 0) {
        ++ret;
        x >>= 1;
    }
    return ret;
}

void solve() {
    lint a, b;
    std::cin >> a >> b;

    int d = std::abs(shift(a) - shift(b));
    std::cout << (a == b ? (d + 2) / 3 : -1) << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}