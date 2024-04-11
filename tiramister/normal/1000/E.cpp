#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <tuple>
#include <limits>
#include <queue>

template <class Cost = int>
struct Edge {
    int src, dst, id;
    Cost cost;

    Edge(int src = -1, int dst = -1, int id = -1, Cost cost = 1)
        : src(src), dst(dst), id(id), cost(cost){};

    bool operator<(const Edge<Cost>& e) const { return this->cost < e.cost; }
    bool operator>(const Edge<Cost>& e) const { return this->cost > e.cost; }
};

template <class Cost = int>
struct Graph {
    std::vector<std::vector<Edge<Cost>>> graph;

    Graph(int n = 0) : graph(n) {}

    void span(bool direct, int src, int dst, int id, Cost cost = 1) {
        graph[src].emplace_back(src, dst, id, cost);
        if (!direct) graph[dst].emplace_back(dst, src, id, cost);
    }

    int size() const { return graph.size(); }
    void clear() { graph.clear(); }
    void resize(int n) { graph.resize(n); }

    std::vector<Edge<Cost>>& operator[](int v) { return graph[v]; }
    std::vector<Edge<Cost>> operator[](int v) const { return graph[v]; }
};

template <class Cost = int>
struct Lowlink {
    Graph<Cost> graph;
    int time;
    std::vector<int> order, low;

    std::vector<int> artics;
    std::vector<Edge<Cost>> bridges;

    explicit Lowlink(const Graph<Cost>& graph)
        : graph(graph), order(graph.size(), -1), low(graph.size(), graph.size()) {
        time = 0;
        for (int v = 0; v < (int)graph.size(); ++v) {
            if (order[v] < 0) dfs(v, -1);
        }
    }

    void dfs(int v, int r) {
        order[v] = low[v] = time++;
        int deg = 0;
        bool is_artic = false;

        for (auto e : graph[v]) {
            if (order[e.dst] < 0) {
                ++deg;
                dfs(e.dst, e.src);
                low[e.src] = std::min(low[e.src], low[e.dst]);

                if (order[e.src] <= low[e.dst]) is_artic = true;
                if (order[e.src] < low[e.dst]) bridges.push_back(e);
            } else if (e.dst != r) {
                low[e.src] = std::min(low[e.src], order[e.dst]);
            }
        }

        if (r < 0) is_artic = (deg > 1);
        if (is_artic) artics.push_back(v);
    }
};

template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

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

        for (const auto& e : graph[v]) {
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

    Graph<int> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        graph.span(false, --u, --v, i, 0);
    }

    auto bridges = Lowlink(graph).bridges;
    std::vector<bool> isbridge(m, false);
    for (auto e : bridges) isbridge[e.id] = true;

    for (int v = 0; v < n; ++v) {
        for (auto& e : graph[v]) {
            if (isbridge[e.id]) e.cost = 1;
        }
    }

    auto dist = dijkstra(graph, 0);
    int r = std::max_element(dist.begin(), dist.end()) - dist.begin();

    dist = dijkstra(graph, r);
    std::cout << *std::max_element(dist.begin(), dist.end()) << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}