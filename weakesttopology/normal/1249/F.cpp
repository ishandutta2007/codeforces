#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, K;
    std::cin >> N >> K;
    ++K;
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
    }
    std::vector<std::vector<int>> E(N);
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    auto get = [](const auto& dp, int h) {
        h = std::max(h, 0);
        return h < dp.size() ? dp[h] : 0;
    };
    auto dfs = [&](auto &self, int u, int p) -> std::deque<int> {
        std::deque<int> dp = {0};
        for (auto v : E[u]) {
            if (v == p) continue;
            auto dpv = self(self, v, u);
            dpv.push_front(dpv[0]);
            if (dpv.size() > dp.size()) {
                std::swap(dpv, dp);
            }
            std::vector<int> ndp(dpv.size());
            for (int d = 0; d < dpv.size() && 2 * d <= K; ++d) {
                ndp[d] = std::max(dp[d] + get(dpv, K - d), dpv[d] + get(dp, K - d));
            }
            for (int d = K / 2 + 1; d < dpv.size(); ++d) {
                ndp[d] = std::max(ndp[d], dp[d] + dpv[d]);
            }
            for (int d = dpv.size() - 1; d >= 0; --d) {
                dp[d] = std::max(dp[d], ndp[d]);
                if (d + 1 < dp.size()) {
                    dp[d] = std::max(dp[d], dp[d + 1]);
                }
            }
        }
        dp[0] = std::max(dp[0], a[u] + get(dp, K));
        return dp;
    };
    std::cout << dfs(dfs, 0, -1)[0] << '\n';
    exit(0);
}