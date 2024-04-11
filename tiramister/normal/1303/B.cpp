#include <iostream>

using lint = long long;

void solve() {
    lint n, g, b;
    std::cin >> n >> g >> b;

    lint m = (n + 1) / 2;
    lint w = (m - 1) / g;
    std::cout << (g >= b ? n
                         : std::max(n, w * (g + b) + (m - g * w)))
              << std::endl;
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