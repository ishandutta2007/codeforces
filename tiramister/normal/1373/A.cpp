#include <iostream>

using lint = long long;

void solve() {
    lint a, b, c;
    std::cin >> a >> b >> c;

    std::cout << (a < c ? 1 : -1) << " "
              << (c < a * b ? b : -1) << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}