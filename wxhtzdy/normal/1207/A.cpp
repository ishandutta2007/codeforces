#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        int b, p, f;
        std::cin >> b >> p >> f;

        int h, c;
        std::cin >> h >> c;

        int ans =  0;
        for (int i = 0; i <= p; i++) {
            for (int j = 0; j <= f; j++) {
                if (i * 2 + j * 2 <= b) {
                    ans = std::max(ans, i * h + j * c);
                }
            }
        }

        std::cout << ans << "\n";
    }
    return 0;
}