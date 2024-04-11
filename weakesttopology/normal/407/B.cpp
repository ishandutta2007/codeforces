#include <bits/stdc++.h>
constexpr int mod = 1e9 + 7;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<int> p(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> p[i];
        --p[i];
    }
    std::vector dp(N, std::vector<int64_t>(N));
    dp[0][0] = 2;
    for (int r = 1; r < N; ++r) {
        dp[r][r] = 2 + dp[p[r]][r - 1];
        dp[r][r] %= mod;
        for (int l = r - 1; l >= 0; --l) {
            dp[l][r] = 2 + dp[l][r - 1] + dp[p[r]][r - 1];
            dp[l][r] %= mod;
        }
    }
    std::cout << dp[0][N - 1] << '\n';
    exit(0);
}