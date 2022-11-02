#include <iostream>

void solve() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::cout << std::max(a + b, c + d) << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}