#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i];
    }

    std::vector<int> tm(n);
    for (int i = 0; i < n; i++) {
        std::cin >> tm[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i] - (i == 0 ? 0 : b[i - 1]) + tm[i];
        if (i != n - 1) {
            ans = std::max(b[i], ans + (b[i] - a[i] + 1) / 2);
        }
    }

    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}