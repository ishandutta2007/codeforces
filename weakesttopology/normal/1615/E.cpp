#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, K;
    std::cin >> N >> K;
    std::vector<std::vector<int>> E(N);
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    int cnt = 0;
    auto dfs = [&](auto &self, int u, int p) -> std::multiset<int> {
        std::multiset<int> S;
        bool leaf = true;
        for (auto v : E[u]) {
            if (v == p) continue;
            leaf = false;
            auto T = self(self, v, u);
            if (T.size() > S.size()) {
                std::swap(S, T);
            }
            S.merge(T);
        }
        if (leaf) {
            ++cnt;
            S.insert(0);
        } else {
            auto iter = std::prev(S.end());
            int x = *iter + 1;
            S.erase(iter);
            S.insert(x);
        }
        return S;
    };
    auto S = dfs(dfs, 0, -1);
    int64_t ans = std::numeric_limits<int64_t>::min();
    if (cnt <= K) {
        for (int64_t x = cnt; x <= K; ++x) {
            ans = std::max(ans, x * (N - x));
        }
    } else {
        int64_t wmin = 0;
        for (int r = 0; r <= K; ++r) {
            int64_t bmax = N - (wmin + r);
            auto f = [&](int64_t b) {
                return (wmin + bmax - b) * (r - b);
            };
            int L = 0, R = bmax;
            while (L < R) {
                int M = (L + R) / 2;
                f(M) <= f(M + 1) ? R = M : L = M + 1;
            }
            ans = std::max(ans, f(L));
            auto iter = std::prev(S.end());
            wmin += *iter;
            S.erase(iter);
        }
    }
    std::cout << ans << '\n';
    exit(0);
}