#include <bits/stdc++.h>
constexpr int64_t mod = 1e9 + 7;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<int> e(N);
    for (int i = 0; i < N; ++i) {
        int a;
        std::cin >> a;
        while (a % 2 == 0) {
            ++e[i];
            a /= 2;
        }
    }
    std::sort(e.rbegin(), e.rend());
    std::array<int64_t, 2> dp{};
    dp[0] = 1;
    int64_t ans = 0;
    for (int i = 0; i < N; ++i) {
        if (i > 0 && e[i] != e[i - 1]) {
            dp[0] += dp[1];
            dp[1] = 0;
        }
        if (e[i] == 0) {
            ans += dp[0];
            ans %= mod;
            dp[0] = 2 * dp[0] % mod;
        } else {
            ans += dp[1];
            ans %= mod;
            auto ndp = dp;
            for (int t : {0, 1}) {
                ndp[t ^ 1] += dp[t];
                ndp[t ^ 1] %= mod;
            }
            std::swap(dp, ndp);
        }
    }
    std::cout << ans << '\n';
    exit(0);
}