#include <bits/stdc++.h>
constexpr int K = 26;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<int> h(N);
    std::vector<std::array<int, K>> go(N);
    for (int u = 0; u < N; ++u) {
        std::fill(go[u].begin(), go[u].end(), -1);
    }
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        char ch;
        std::cin >> u >> v >> ch;
        --u, --v;
        go[u][ch - 'a'] = v;
    }
    auto dfs = [&](auto& self, int u) -> void {
        for (int k = 0; k < K; ++k) {
            int v = go[u][k];
            if (v == -1) continue;
            h[v] = h[u] + 1;
            self(self, v);
        }
    };
    dfs(dfs, 0);
    auto merge = [&](auto& self, const auto& U) -> int {
        if (U.size() <= 1) {
            return 0;
        }
        int res = U.size() - 1;
        for (int k = 0; k < K; ++k) {
            std::vector<int> V;
            for (auto u : U) {
                int v = go[u][k];
                if (v == -1) continue;
                V.push_back(v);
            }
            res += self(self, V);
        }
        return res;
    };
    std::vector<int> cnt(N);
    for (int u = 0; u < N; ++u) {
        std::vector<int> V;
        for (int k = 0; k < K; ++k) {
            int v = go[u][k];
            if (v == -1) continue;
            V.push_back(v);
        }
        if (V.empty()) continue;
        cnt[h[u]] += 1 + merge(merge, V);
    }
    auto iter = std::max_element(cnt.begin(), cnt.end());
    int opt = iter - cnt.begin() + 1;
    std::cout << N - *iter << '\n' << opt << '\n';
    exit(0);
}