#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

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

    int size() const { return graph.size(); }
    void clear() { graph.clear(); }
    void resize(int n) { graph.resize(n); }

    std::vector<Edge<Cost>>& operator[](int v) { return graph[v]; }
    std::vector<Edge<Cost>> operator[](int v) const { return graph[v]; }
};

using lint = long long;

void solve() {
    int n;
    std::cin >> n;

    Graph<int> graph(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, c;
        std::cin >> u >> v >> c;
        graph.span(false, --u, --v, c);
    }

    std::vector<int> cs(n, 0), ds(n, 0);
    {
        std::function<void(int, int)> dfs =
            [&](int v, int p) -> void {
            for (auto e : graph[v]) {
                int u = e.dst;
                if (u == p) continue;

                dfs(u, v);

                if (e.cost == 0) {
                    cs[v] += cs[u] + 1;
                    ds[v] += 0;
                } else {
                    cs[v] += ds[u] + 1;
                    ds[v] += ds[u] + 1;
                }
            }
        };
        dfs(0, -1);
    }

    lint ans = 0;
    {
        std::function<void(int, int)> dfs =
            [&](int v, int p) -> void {
            ans += cs[v];

            for (auto e : graph[v]) {
                int u = e.dst;
                if (u == p) continue;

                int nc, nd;
                if (e.cost == 0) {
                    nc = cs[v] - cs[u];
                    nd = 0;
                } else {
                    nc = ds[v] - ds[u];
                    nd = ds[v] - ds[u];
                }

                cs[u] += nc;
                ds[u] += nd;

                dfs(u, v);

                cs[u] -= nc;
                ds[u] -= nd;
            }
        };
        dfs(0, -1);
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}