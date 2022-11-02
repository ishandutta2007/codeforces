#include <iostream>

using lint = long long;

void solve() {
    lint x, y;
    std::cin >> x >> y;
    x -= y;

    std::cout << (x == 1 ? "NO" : "YES") << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}