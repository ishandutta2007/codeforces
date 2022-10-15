#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M, K;
    std::cin >> N >> M >> K;
    std::vector<std::vector<int>> E(N);
    for (int j = 0; j < M; ++j) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }
    std::vector<int> p(N, -1), h(N);
    std::vector<bool> leaf(N, true);
    auto dfs = [&](auto &self, int u) -> void {
        for (auto& v : E[u]) {
            if (v == p[u]) {
                std::swap(v, E[u].back());
            }
            if (p[v] != -1) continue;
            leaf[u] = false;
            p[v] = u;
            h[v] = h[u] + 1;
            self(self, v);
        }
    };
    p[0] = 0;
    dfs(dfs, 0);
    int u = std::max_element(h.begin(), h.end()) - h.begin();
    if (h[u] >= (N + K - 1) / K) {
        std::cout << "PATH\n" << h[u] + 1 << '\n';
        for (int i = 0, v = u; i <= h[u]; ++i) {
            std::cout << v + 1 << "\n "[i < h[u]];
            v = p[v];
        }
    } else {
        std::vector<int> leaves;
        for (int u = 0; u < N; ++u) {
            if (leaf[u]) {
                leaves.push_back(u);
            }
        }
        assert(leaves.size() >= K);
        leaves.resize(K);
        std::cout << "CYCLES\n";
        for (auto s : leaves) {
            int u = E[s][0], v = E[s][1];
            if (h[u] < h[v]) {
                std::swap(u, v);
            }
            int x = h[s] - h[u], y = h[u] - h[v];
            std::vector<int> C;
            C.push_back(s);
            if ((x + 1) % 3) {
                for (int i = 0, w = s; i < x; ++i) {
                    w = p[w];
                    C.push_back(w);
                }
            } else if ((x + y + 1) % 3) {
                for (int i = 0, w = s; i < x + y; ++i) {
                    w = p[w];
                    C.push_back(w);
                }
            } else {
                C.push_back(u);
                for (int i = 0, w = u; i < y; ++i) {
                    w = p[w];
                    C.push_back(w);
                }
            }
            int c = C.size();
            std::cout << c << '\n';
            for (int i = 0; i < c; ++i) {
                std::cout << C[i] + 1 << "\n "[i + 1 < c];
            }
        }
    }
    exit(0);
}