#include <iostream>
#include <algorithm>

void solve() {
    int a, b;
    std::cin >> a >> b;
    std::cout << std::min({a, b, (a + b) / 3}) << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}