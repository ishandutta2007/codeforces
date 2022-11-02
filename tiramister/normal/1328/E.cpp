#include <iostream>
#include <algorithm>
#include <vector>

template <class Cost = int>
struct Edge {
    int src, dst;
    Cost cost;
    Edge(int src = -1, int dst = -1, Cost cost = 1)
        : src(src), dst(dst), cost(cost){};

    bool operator<(const Edge<Cost>& e) const { return this->cost < e.cost; }
    bool operator>(const Edge<Cost>& e) const { return this->cost > e.cost; }
};

template <class Cost = int>
using Graph = std::vector<std::vector<Edge<Cost>>>;

template <class Cost>
struct LowestCommonAncestor {
    Graph<Cost> tree;
    std::vector<std::vector<int>> par;
    std::vector<int> depth;
    std::vector<Cost> cdepth;

    void initdfs(int v, int r, int d, Cost c) {
        par[0][v] = r;
        depth[v] = d;
        cdepth[v] = c;
        for (const auto& e : tree[v]) {
            if (e.dst == r) continue;
            initdfs(e.dst, v, d + 1, c + e.cost);
        }
    }

    void doubling() {
        for (int k = 0; k < 19; ++k) {
            for (int v = 0; v < (int)tree.size(); ++v) {
                par[k + 1][v] = (par[k][v] < 0 ? -1 : par[k][par[k][v]]);
            }
        }
    }

    explicit LowestCommonAncestor(const Graph<Cost> tree, int root)
        : tree(tree),
          par(20, std::vector<int>(tree.size())),
          depth(tree.size()),
          cdepth(tree.size()) {
        initdfs(root, -1, 0, 0);
        doubling();
    }

    int lca(int u, int v) const {
        if (depth[u] > depth[v]) std::swap(u, v);

        int diff = depth[v] - depth[u];
        for (int k = 19; k >= 0; --k) {
            if ((diff >> k) & 1) v = par[k][v];
        }
        if (u == v) return u;

        for (int k = 19; k >= 0; --k) {
            if (par[k][u] != par[k][v]) {
                u = par[k][u];
                v = par[k][v];
            }
        }
        return par[0][u];
    }

    Cost dist(int u, int v) const {
        int r = lca(u, v);
        return cdepth[u] + cdepth[v] - cdepth[r] * 2;
    }
};

void solve() {
    int n, q;
    std::cin >> n >> q;

    Graph<> graph(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        graph[u].emplace_back(u, v);
        graph[v].emplace_back(v, u);
    }

    LowestCommonAncestor lca(graph, 0);

    while (q--) {
        int m;
        std::cin >> m;

        std::vector<int> vs(m);
        for (auto& v : vs) {
            std::cin >> v;
            --v;
        }

        std::sort(vs.begin(), vs.end(),
                  [&](auto u, auto v) {
                      return lca.depth[u] < lca.depth[v];
                  });

        int v = vs.back();
        vs.pop_back();

        bool judge = true, through = false;
        while (!vs.empty()) {
            int u = vs.back();
            vs.pop_back();

            int p = lca.lca(u, v);
            if ((lca.depth[v] - lca.depth[p] > 1 &&
                 lca.depth[u] - lca.depth[p] > 1) ||
                (through && lca.depth[u] - lca.depth[p] > 1)) {
                judge = false;
            }

            through = true;
            v = p;
        }

        std::cout << (judge ? "YES" : "NO") << "\n";
    }
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}