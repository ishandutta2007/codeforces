#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, h, m;
    std::cin >> n >> h >> m;

    std::vector<int> mx(n + 1, h);
    while (m--) {
        int l, r, x;
        std::cin >> l >> r >> x;

        for (int i = l; i <= r; i++) {
            mx[i] = std::min(mx[i], x);
        }
    }

    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += mx[i] * mx[i];
    }

    std::cout << ans << "\n";
    return 0;
}