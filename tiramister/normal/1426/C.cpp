#include <iostream>

void solve() {
    int n;
    std::cin >> n;

    int ans = n;
    for (int h = 1; h * h <= n; ++h) {
        int w = (n + h - 1) / h;
        ans = std::min(ans, h + w - 2);
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}