#include "bits/stdc++.h"
// K > floor(log(tree height))
template<int K>
struct LCA {
    const std::vector<std::vector<int>>& E;
    int N;
    std::vector<int> L, R, inv, h;
    std::vector<std::array<int, K>> up;
    int timer = 0;
    void dfs(int u, int p) {
        up[u][0] = p;
        for (int i = 0; i + 1 < K; ++i) up[u][i + 1] = up[up[u][i]][i];
        inv[L[u] = timer++] = u;
        for (int v : E[u]) {
            if (v == p) continue;
            h[v] = h[u] + 1;
            dfs(v, u);
        }
        R[u] = timer;
    }
    LCA(const std::vector<std::vector<int>>& E, int root) : E(E), N(E.size()), L(N), R(N), inv(N), h(N), up(N) {
        dfs(root, root);
    }
    bool is_ancestor(int u, int v) const {
        return L[u] <= L[v] && R[v] <= R[u];
    }
    int lca(int u, int v) const {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (int i = K - 1; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v)) u = up[u][i];
        }
        return up[u][0];
    }
    int dist(int u, int v) const {
        int w = lca(u, v);
        return h[u] + h[v] - 2 * h[w];
    }
};
// builds virtual tree on F given the vertex set V and returns its root
// V is modified to contain the new vertices and is sorted by L[u]
template<typename LCA>
int build_virtual_tree(std::vector<int>& V, std::vector<std::vector<int>>& F, const LCA& lca) {
    auto cmp = [&](int u, int v) { return lca.L[u] > lca.L[v]; };
    std::sort(V.begin(), V.end(), cmp);
    int k = V.size();
    for (int j = 0; j + 1 < k; ++j) V.push_back(lca.lca(V[j], V[j + 1]));
    std::sort(V.begin(), V.end(), cmp), V.erase(std::unique(V.begin(), V.end()), V.end());
    std::stack<int> stk;
    for (auto u : V) {
        while (not stk.empty() && lca.is_ancestor(u, stk.top())) {
            int v = stk.top();
            stk.pop();
            F[u].push_back(v), F[v].push_back(u);
        }
        stk.push(u);
    }
    return stk.top();
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> E(N), F(N);
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }
    LCA<18> lca(E, 0);
    std::vector<int> f(N, -1);
    int Q;
    std::cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int K, M;
        std::cin >> K >> M;
        std::vector<int> V(K), s(K);
        for (int j = 0; j < K; ++j) {
            std::cin >> V[j] >> s[j];
            --V[j];
        }
        std::vector<int> U(M);
        for (int j = 0; j < M; ++j) {
            std::cin >> U[j];
            --U[j];
        }
        auto W = V;
        W.insert(W.end(), U.begin(), U.end());
        build_virtual_tree(W, F, lca);
        std::priority_queue<std::tuple<int, int, int>> pq;
        for (int j = 0; j < K; ++j) {
            pq.emplace(0, -j, V[j]);
        }
        while (!pq.empty()) {
            auto [d, j, u] = pq.top();
            pq.pop();
            d *= -1, j *= -1;
            if (f[u] != -1) continue;
            f[u] = j;
            for (auto v : F[u]) {
                if (f[v] != -1) continue;
                int nd = (lca.dist(V[j], v) + s[j] - 1) / s[j];
                pq.emplace(-nd, -j, v);
            }
        }
        for (int j = 0; j < M; ++j) {
            std::cout << f[U[j]] + 1 << "\n "[j + 1 < M];
        }
        for (auto w : W) {
            F[w].clear();
            f[w] = -1;
        }
    }
    exit(0);
}