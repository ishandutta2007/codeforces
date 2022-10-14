#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    int bot = 0, top = n, ans = 0;
    while (bot <= top) {
        int mid = bot + top >> 1;

        std::vector<std::vector<int>> nxt(n + 2, std::vector<int>(k, n + 1));
        for (int j = 0; j < k; j++) {
            int bal = 0;

            for (int i = n - 1; i >= 0; i--) {
                if (s[i] == '?' || s[i] == (char) ('a' + j)) {
                    bal++;
                } else {
                    bal = 0;
                }

                nxt[i][j] = (bal >= mid ? i + mid : nxt[i + 1][j]);
            }
        }

        std::vector<int> dp(1 << k, n + 1);
        dp[0] = 0;
        for (int i = 0; i < (1 << k); i++) {
            for (int j = 0; j < k; j++) {
                if (i & (1 << j)) continue;

                dp[i | (1 << j)] = std::min(dp[i | (1 << j)], nxt[dp[i]][j]);
            }
        }

        if (dp[(1 << k) - 1] <= n) {
            ans = mid;
            bot = mid + 1;
        } else {
            top = mid - 1;
        }
    }

    std::cout << ans;

    return 0;
}