#include <iostream>

void solve() {
    int l, r;
    std::cin >> l >> r;

    int x = r / 2;
    int y = x * 2;

    if (x < l || r < y) x = y = -1;

    std::cout << x << " " << y << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}