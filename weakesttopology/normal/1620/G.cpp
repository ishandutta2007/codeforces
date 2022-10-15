#include <bits/stdc++.h>
constexpr int K = 26, mod = 998244353;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<std::array<int, K>> f(1 << N);
    std::fill(f[0].begin(), f[0].end(), std::numeric_limits<int>::max());
    for (int i = 0; i < N; ++i) {
        std::string S;
        std::cin >> S;
        for (auto c : S) {
            ++f[1 << i][c - 'a'];
        }
    }
    std::vector<int64_t> dp(1 << N), sum(1 << N);
    for (uint32_t mask = 1; mask < (1 << N); ++mask) {
        uint32_t i = std::countr_zero(mask), lsb = 1 << i;
        sum[mask] = sum[mask ^ lsb] + i + 1;
        dp[mask] = std::popcount(mask) % 2 ? 1 : mod - 1;
        for (int k = 0; k < K; ++k) {
            f[mask][k] = std::min(f[mask ^ lsb][k], f[lsb][k]);
            dp[mask] *= f[mask][k] + 1;
            dp[mask] %= mod;
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int mask = 0; mask < (1 << N); ++mask) {
            if (mask >> i & 1) continue;
            int nmask = mask | 1 << i;
            dp[nmask] += dp[mask];
            dp[nmask] %= mod;
        }
    }
    int64_t ans = 0;
    for (uint32_t mask = 0; mask < (1 << N); ++mask) {
        ans ^= sum[mask] * std::popcount(mask) * dp[mask];
    }
    std::cout << ans << '\n';
    exit(0);
}