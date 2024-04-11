#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        int a, b, x, y;
        std::cin >> a >> b >> x >> y;

        int ans = std::max({x * b, y * a, (a - x - 1) * b, (b - y - 1) * a});

        std::cout << ans << "\n";
    }
    return 0;
}