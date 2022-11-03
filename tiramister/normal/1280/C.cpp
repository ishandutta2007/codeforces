#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using lint = long long;

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
struct Graph {
    std::vector<std::vector<Edge<Cost>>> graph;

    Graph(int n = 0) : graph(n) {}

    void span(bool direct, int src, int dst, Cost cost = 1) {
        graph[src].emplace_back(src, dst, cost);
        if (!direct) graph[dst].emplace_back(dst, src, cost);
    }

    std::vector<Edge<Cost>>& operator[](int v) { return graph[v]; }
    std::vector<Edge<Cost>> operator[](int v) const { return graph[v]; }

    int size() const { return graph.size(); }
};

void solve() {
    int n;
    std::cin >> n;
    n *= 2;

    Graph<lint> tree(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        lint c;
        std::cin >> u >> v >> c;
        tree.span(false, --u, --v, c);
    }

    lint minsol = 0;
    {
        std::function<bool(int, int)> dfs =
            [&](int v, int p) -> bool {
            int sz = 1;
            for (auto e : tree[v]) {
                int u = e.dst;
                if (u == p) continue;
                if (dfs(u, v)) {
                    minsol += e.cost;
                    ++sz;
                }
            }
            return sz % 2 != 0;
        };
        dfs(0, -1);
    }

    lint maxsol = 0;
    {
        std::function<int(int, int)> dfs =
            [&](int v, int p) -> int {
            int sz = 1;
            for (auto e : tree[v]) {
                int u = e.dst;
                if (u == p) continue;

                auto csz = dfs(u, v);
                maxsol += std::min(csz, n - csz) * e.cost;
                sz += csz;
            }
            return sz;
        };
        dfs(0, -1);
    }

    std::cout << minsol << " " << maxsol << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}