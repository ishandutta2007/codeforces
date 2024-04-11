#include <iostream>

void solve() {
    int a, b, c;
    std::cin >> a >> b >> c;

    int l = std::max(a, (a + b + c) / 2 + 1);
    std::cout << std::max(0, a + c - l + 1) << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}