#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int N, M;
        std::cin >> N >> M;
        std::vector<std::vector<std::pair<int, int>>> E(N), F(N);
        for (int i = 0; i < N - 1; ++i) {
            int u, v, c;
            std::cin >> u >> v >> c;
            --u, --v;
            E[u].emplace_back(v, c);
            E[v].emplace_back(u, c);
        }
        for (int j = 0; j < M; ++j) {
            int u, v, c;
            std::cin >> u >> v >> c;
            --u, --v;
            F[u].emplace_back(v, c);
            F[v].emplace_back(u, c);
        }
        std::vector<int> color(N, -1);
        bool bipartite = true;
        auto dfs = [&](auto& self, int u) -> void {
            for (auto edge_set : {E[u], F[u]}) {
                for (auto [v, c] : edge_set) {
                    if (c == -1) continue;
                    int b = std::popcount((unsigned)c) % 2;
                    if (color[v] == -1) {
                        color[v] = color[u] ^ b;
                        self(self, v);
                    } else if (color[v] != color[u] ^ b) {
                        bipartite = false;
                    }
                }
            }
        };
        for (int u = 0; u < N; ++u) {
            if (color[u] == -1) {
                color[u] = 0;
                dfs(dfs, u);
            }
        }
        if (!bipartite) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
            for (int u = 0; u < N; ++u) {
                for (auto [v, c] : E[u]) {
                    if (u > v) continue;
                    std::cout << u + 1 << ' ' << v + 1 << ' '
                        << (c == -1 ? color[u] ^ color[v] : c) << '\n';
                }
            }
        }
    }
    exit(0);
}