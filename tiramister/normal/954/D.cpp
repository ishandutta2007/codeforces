#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

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

void solve() {
    int n, m, s, t;
    std::cin >> n >> m >> s >> t;
    --s, --t;

    Graph<> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        graph.span(false, --u, --v);
    }

    auto sdist = bfs(graph, s),
         tdist = bfs(graph, t);

    int ans = n * (n - 1) / 2 - m;
    for (int v = 0; v < n; ++v) {
        for (int u = 0; u < v; ++u) {
            int d = std::min(sdist[u] + tdist[v] + 1,
                             sdist[v] + tdist[u] + 1);
            if (d < sdist[t]) --ans;
        }
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}