#include <iostream>

void solve() {
    int a, b;
    std::cin >> a >> b;

    int ans = (a + b - 1) / b * b - a;
    std::cout << ans << std::endl;
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