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
class LowestCommonAncestor {
private:
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

public:
    explicit LowestCommonAncestor(const Graph<Cost> tree, int root)
        : tree(tree), par(20, std::vector<int>(tree.size())), depth(tree.size()), cdepth(tree.size()) {
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
    int n;
    std::cin >> n;

    Graph<> tree(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        tree[u].emplace_back(u, v);
        tree[v].emplace_back(v, u);
    }
    LowestCommonAncestor lca(tree, 0);

    int q;
    std::cin >> q;
    while (q--) {
        int x, y, a, b, k;
        std::cin >> x >> y >> a >> b >> k;
        --x, --y, --a, --b;

        int d;
        d = lca.dist(a, b);
        if (d <= k && d % 2 == k % 2) {
            std::cout << "YES\n";
            continue;
        }

        d = lca.dist(a, x) + 1 + lca.dist(y, b);
        if (d <= k && d % 2 == k % 2) {
            std::cout << "YES\n";
            continue;
        }

        d = lca.dist(a, y) + 1 + lca.dist(x, b);
        if (d <= k && d % 2 == k % 2) {
            std::cout << "YES\n";
            continue;
        }

        std::cout << "NO\n";
    }
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}