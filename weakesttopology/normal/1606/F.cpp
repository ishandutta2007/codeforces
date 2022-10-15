#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> E(N);
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    int Q;
    std::cin >> Q;
    std::vector<std::vector<std::pair<int, int>>> qs(N);
    for (int q = 0; q < Q; ++q) {
        int v, k;
        std::cin >> v >> k;
        --v;
        qs[v].emplace_back(q, k);
    }
    int magic = 0;
    while (magic * magic <= N) ++magic;
    std::vector<int> ans(Q);
    auto dfs = [&](auto &self, int u, int p) -> std::pair<std::vector<int>, std::vector<int>> {
        std::vector<int> dpm = {0}, dpk(magic);
        for (auto v : E[u]) {
            if (v == p) continue;
            auto [dpmv, dpkv] = self(self, v, u);
            std::vector<int> ndpm(std::min<int>(dpm.size() + dpmv.size(), magic));
            for (int i = 0; i < dpm.size(); ++i) {
                ndpm[i] = std::max(ndpm[i], dpm[i] + 1);
                for (int j = 0; j < dpmv.size() && i + j + 1 < magic; ++j) {
                    ndpm[i + j + 1] = std::max(ndpm[i + j + 1], dpm[i] + dpmv[j]);
                }
            }
            std::swap(dpm, ndpm);
            for (int k = 0; k < magic; ++k) {
                dpk[k] += std::max(1, dpkv[k] - k);
            }
        }
        for (auto [q, k] : qs[u]) {
            if (k < magic) {
                ans[q] = dpk[k];
            } else {
                for (int m = 0; m < dpm.size(); ++m) {
                    ans[q] = std::max(ans[q], dpm[m] - k * m);
                }
            }
        }
        return {dpm, dpk};
    };
    dfs(dfs, 0, -1);
    for (int q = 0; q < Q; ++q) {
        std::cout << ans[q] << '\n';
    }
    exit(0);
}