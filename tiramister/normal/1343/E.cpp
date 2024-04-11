#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <limits>

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

template <class Cost>
std::vector<int> bfs(const Graph<Cost>& graph, int s) {
    std::vector<Cost> dist(graph.size(), -1);
    dist[s] = 0;
    std::queue<int> que;
    que.push(s);

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (const auto& e : graph[v]) {
            if (dist[e.dst] != -1) continue;
            dist[e.dst] = dist[v] + e.cost;
            que.push(e.dst);
        }
    }

    return dist;
}

using lint = long long;
constexpr lint INF = 1LL << 60;

void solve() {
    int n, m, a, b, c;
    std::cin >> n >> m >> a >> b >> c;
    --a, --b, --c;

    std::vector<lint> psum(m + 1);
    {
        std::vector<lint> ps(m);
        for (auto& p : ps) std::cin >> p;
        std::sort(ps.begin(), ps.end());

        psum[0] = 0;
        for (int i = 0; i < m; ++i) {
            psum[i + 1] = psum[i] + ps[i];
        }
    }

    Graph<> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        graph.span(false, --u, --v);
    }

    auto dsa = bfs(graph, a),
         dsb = bfs(graph, b),
         dsc = bfs(graph, c);

    lint ans = INF;
    for (int v = 0; v < n; ++v) {
        int d2 = dsb[v],
            d1 = dsa[v] + dsc[v];

        if (d1 + d2 > m) continue;
        ans = std::min(ans, psum[d1 + d2] + psum[d2]);
    }

    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}