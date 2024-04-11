#include <iostream>

void solve() {
    int n;
    std::cin >> n;

    int ans = (1 << n);
    for (int i = 1; i <= n / 2 - 1; ++i) {
        ans += (1 << i);
    }
    for (int i = n / 2; i < n; ++i) {
        ans -= (1 << i);
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