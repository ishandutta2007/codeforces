#include <iostream>

using lint = long long;

void solve() {
    int x, y, a, b;
    std::cin >> x >> y >> a >> b;

    int d = y - x;
    if (d % (a + b) != 0) {
        std::cout << -1 << std::endl;
        return;
    }

    int t = d / (a + b);
    std::cout << t << std::endl;
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