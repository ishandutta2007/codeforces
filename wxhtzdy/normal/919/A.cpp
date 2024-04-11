#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    double ans = 1e9;
    for (int i = 0; i < n; i++) {
        double a, b;
        std::cin >> a >> b;

        ans = std::min(ans, (double) (a / b) * 1.0 * m);
    }

    std::cout << std::fixed << std::setprecision(6) << ans << "\n";

    return 0;
}