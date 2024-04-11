#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

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

template <class Cost = int>
struct Centroid {
    Graph<Cost> graph;
    std::vector<bool> deleted;
    std::vector<int> sz;

    explicit Centroid(const Graph<Cost>& graph)
        : graph(graph), deleted(graph.size(), false), sz(graph.size()) {}

    int szdfs(int v, int p = -1) {
        sz[v] = 1;
        for (auto e : graph[v]) {
            if (e.dst == p || deleted[e.dst]) continue;
            sz[v] += szdfs(e.dst, v);
        }
        return sz[v];
    }

    int find(int v) {
        int n = szdfs(v);

        int p = -1;
        while (true) {
            int nxt = -1;
            for (auto e : graph[v]) {
                if (e.dst == p || deleted[e.dst]) continue;
                if (nxt == -1 || sz[e.dst] > sz[nxt]) nxt = e.dst;
            }

            if (nxt == -1 || sz[nxt] <= n / 2) return v;
            p = v;
            v = nxt;
        }
    }
};

void solve() {
    int n;
    std::cin >> n;

    Graph<> graph(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        graph[u].emplace_back(u, v);
        graph[v].emplace_back(v, u);
    }

    Centroid<> cent(graph);
    std::queue<std::pair<int, int>> cents;
    cents.emplace(0, 0);
    std::vector<int> ans(n);

    while (!cents.empty()) {
        int r, d;
        std::tie(r, d) = cents.front();
        cents.pop();

        r = cent.find(r);
        ans[r] = d;
        cent.deleted[r] = true;

        for (auto e : graph[r]) {
            if (cent.deleted[e.dst]) continue;
            cents.emplace(e.dst, d + 1);
        }
    }

    for (auto a : ans) {
        std::cout << char(a + 'A') << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}