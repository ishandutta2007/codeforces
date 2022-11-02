#include <iostream>
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

    std::vector<Edge<Cost>>& operator[](int v) { return graph[v]; }
    std::vector<Edge<Cost>> operator[](int v) const { return graph[v]; }

    int size() const { return graph.size(); }

    void clear() { graph.clear(); }
    void resize(int n) { graph.resize(n); }
};

using lint = long long;
constexpr lint INF = 1LL << 60;

std::vector<lint> xs, ys;
Graph<> tree;
std::vector<std::vector<std::pair<int, lint>>> dps;

void dfs(int v, int par) {
    auto d = ys[v] - xs[v];
    auto& dp = dps[v];
    dp.assign(1, std::make_pair(0, d));

    for (auto e : tree[v]) {
        int u = e.dst;
        if (u == par) continue;

        dfs(u, v);
        auto& cdp = dps[u];

        int sz = dp.size(), csz = cdp.size();
        std::vector<std::pair<int, lint>>
            ndp(sz + csz, std::make_pair(0, -INF));

        for (int i = 0; i < sz; ++i) {
            auto p = dp[i];
            for (int j = 0; j < csz; ++j) {
                auto q = cdp[j];

                // merge
                {
                    auto r = std::make_pair(p.first + q.first, p.second + q.second);
                    ndp[i + j] = std::max(ndp[i + j], r);
                }

                // cut
                {
                    auto r = std::make_pair(p.first + q.first, p.second);
                    if (q.second > 0) ++r.first;
                    ndp[i + j + 1] = std::max(ndp[i + j + 1], r);
                }
            }
        }
        std::swap(dp, ndp);
    }
}

void solve() {
    int n, m;
    std::cin >> n >> m;

    xs.resize(n);
    ys.resize(n);
    for (auto& x : xs) std::cin >> x;
    for (auto& y : ys) std::cin >> y;

    tree.clear();
    tree.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        tree.span(false, --u, --v);
    }

    dps.clear();
    dps.resize(n);

    dfs(0, -1);

    auto p = dps[0][m - 1];
    std::cout << p.first + (p.second > 0) << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}