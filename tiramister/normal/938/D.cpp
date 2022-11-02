#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <tuple>

template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

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
std::vector<Cost> dijkstra(const Graph<Cost>& graph, int s) {
    constexpr Cost INF = std::numeric_limits<Cost>::max();

    std::vector<Cost> dist(graph.size(), INF);
    dist[s] = 0;
    MinHeap<std::pair<Cost, int>> que;
    que.emplace(0, s);

    while (!que.empty()) {
        int v;
        Cost d;
        std::tie(d, v) = que.top();
        que.pop();
        if (d > dist[v]) continue;

        for (auto e : graph[v]) {
            if (dist[e.dst] <= dist[v] + e.cost) continue;
            dist[e.dst] = dist[v] + e.cost;
            que.emplace(dist[e.dst], e.dst);
        }
    }
    return dist;
}

using lint = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    Graph<lint> graph(n);
    while (m--) {
        int u, v;
        lint d;
        std::cin >> u >> v >> d;
        --u, --v;
        d *= 2;

        graph[u].emplace_back(u, v, d);
        graph[v].emplace_back(v, u, d);
    }

    MinHeap<std::pair<lint, int>> que;
    std::vector<lint> dist(n);
    for (int v = 0; v < n; ++v) {
        std::cin >> dist[v];
        que.emplace(dist[v], v);
    }

    while (!que.empty()) {
        int v;
        lint d;
        std::tie(d, v) = que.top();
        que.pop();
        if (d > dist[v]) continue;

        for (auto e : graph[v]) {
            if (dist[e.dst] <= dist[v] + e.cost) continue;
            dist[e.dst] = dist[v] + e.cost;
            que.emplace(dist[e.dst], e.dst);
        }
    }

    for (auto& d : dist) std::cout << d << " ";
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}