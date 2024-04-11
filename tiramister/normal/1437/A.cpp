#include <iostream>

void solve() {
    int l, r;
    std::cin >> l >> r;
    std::cout << (l * 2 >= r + 1 ? "YES" : "NO") << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}