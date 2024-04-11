#include <iostream>

void solve() {
    int x, y;
    std::cin >> x >> y;
    bool out = ((x == 1 && y > 1) || (x <= 3 && y > 3));
    std::cout << (out ? "NO" : "YES") << std::endl;
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