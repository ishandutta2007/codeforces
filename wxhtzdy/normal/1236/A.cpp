#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        int a, b, c;
        std::cin >> a >> b >> c;

        int ans = 0;
        for (int i = 0; i <= a; i++) {
            for (int j = 0; j <= b; j++) {
                if (2 * i + j <= b && j * 2 <= c) {
                    ans = std::max(ans, (i + j) * 3);
                }
            }
        }

        std::cout << ans << "\n";
    }
    return 0;
}