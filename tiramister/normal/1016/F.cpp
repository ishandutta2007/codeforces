#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <set>
#include <queue>
#include <cassert>

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

template <class Cost>
std::vector<Cost> bfs(const Graph<Cost>& graph, int s) {
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

void solve() {
    int n, m;
    std::cin >> n >> m;

    Graph<lint> graph(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        lint w;
        std::cin >> u >> v >> w;
        graph.span(false, --u, --v, w);
    }

    auto xs = bfs(graph, 0),
         ys = bfs(graph, n - 1);
    lint d = xs[n - 1];

    std::vector<int> vs(n);
    std::iota(vs.begin(), vs.end(), 0);
    std::sort(vs.begin(), vs.end(),
              [&](auto u, auto v) {
                  return xs[u] - ys[u] > xs[v] - ys[v];
              });

    std::multiset<lint> xss(xs.begin(), xs.end());
    lint max = 0;
    std::vector<bool> removed(n, false);

    for (auto v : vs) {
        xss.erase(xss.find(xs[v]));
        if (xss.empty()) continue;
        removed[v] = true;

        for (auto e : graph[v]) {
            int u = e.dst;
            if (!removed[u]) xss.erase(xss.find(xs[u]));
        }

        if (!xss.empty()) {
            max = std::max(max, ys[v] + *xss.rbegin());
        }

        for (auto e : graph[v]) {
            int u = e.dst;
            if (!removed[u]) xss.insert(xs[u]);
        }
    }

    while (m--) {
        lint x;
        std::cin >> x;
        std::cout << std::min(d, max + x) << "\n";
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}