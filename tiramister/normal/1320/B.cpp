#include <iostream>
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

void solve() {
    int n, m;
    std::cin >> n >> m;

    Graph<> graph(n), rgraph(n);
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        graph[u].emplace_back(u, v);
        rgraph[v].emplace_back(v, u);
    }

    int k;
    std::cin >> k;
    std::vector<int> vs(k);
    for (auto& v : vs) {
        std::cin >> v;
        --v;
    }

    auto dist = dijkstra(rgraph, vs.back());
    int min = 0, max = 0;
    for (int i = 0; i + 1 < k; ++i) {
        int v = vs[i], u = vs[i + 1];

        if (dist[v] - dist[u] != 1) {
            ++min;
            ++max;
        } else {
            for (auto e : graph[v]) {
                if (e.dst != u &&
                    dist[v] - dist[e.dst] == 1) {
                    ++max;
                    break;
                }
            }
        }
    }

    std::cout << min << " " << max << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}