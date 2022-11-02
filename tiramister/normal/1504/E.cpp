#line 2 "/Users/tiramister/CompetitiveProgramming/Cpp/CppLibrary/Graph/dijkstra.hpp"

#line 2 "/Users/tiramister/CompetitiveProgramming/Cpp/CppLibrary/Tools/heap_alias.hpp"

#include <queue>

template <class T>
using MaxHeap = std::priority_queue<T>;
template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/Users/tiramister/CompetitiveProgramming/Cpp/CppLibrary/Graph/graph.hpp"

#include <vector>

template <class Cost = int>
struct Edge {
    int src, dst;
    Cost cost;

    Edge() = default;
    Edge(int src, int dst, Cost cost = 1)
        : src(src), dst(dst), cost(cost){};

    bool operator<(const Edge<Cost>& e) const { return cost < e.cost; }
    bool operator>(const Edge<Cost>& e) const { return cost > e.cost; }
};

template <class Cost = int>
struct Graph : public std::vector<std::vector<Edge<Cost>>> {
    using std::vector<std::vector<Edge<Cost>>>::vector;

    void span(bool direct, int src, int dst, Cost cost = 1) {
        (*this)[src].emplace_back(src, dst, cost);
        if (!direct) (*this)[dst].emplace_back(dst, src, cost);
    }
};
#line 5 "/Users/tiramister/CompetitiveProgramming/Cpp/CppLibrary/Graph/dijkstra.hpp"

template <class Cost>
std::vector<Cost> dijkstra(const Graph<Cost>& graph, int s) {
    std::vector<Cost> dist(graph.size(), -1);
    dist[s] = 0;
    MinHeap<std::pair<Cost, int>> que;
    que.emplace(0, s);

    while (!que.empty()) {
        auto [d, v] = que.top();
        que.pop();
        if (d > dist[v]) continue;

        for (const auto& e : graph[v]) {
            if (dist[e.dst] != -1 &&
                dist[e.dst] <= dist[v] + e.cost) continue;
            dist[e.dst] = dist[v] + e.cost;
            que.emplace(dist[e.dst], e.dst);
        }
    }

    return dist;
}
#line 2 "main.cpp"
#include <iostream>
#include <algorithm>
#line 5 "main.cpp"
#include <cassert>

using namespace std;
using lint = long long;

void solve() {
    int n;
    cin >> n;

    vector<pair<lint, lint>> ps(n);
    lint ans = 0;
    for (auto& [x, y] : ps) {
        cin >> x >> y;
        ans += y;
        y += x;
    }
    sort(ps.begin(), ps.end());

    // 0n-1
    Graph<lint> graph(n);
    for (int i = 0; i + 1 < n; ++i) {
        graph.span(true, i + 1, i, 0);
    }

    for (int i = 0; i < n; ++i) {
        auto y = ps[i].second;
        int j = lower_bound(ps.begin(), ps.end(), make_pair(y + 1, 0LL)) - ps.begin();

        // 
        graph.span(true, i, j - 1, 0);
        if (j < n) graph.span(true, i, j, ps[j].first - y);
    }

    cout << ans + dijkstra(graph, 0)[n - 1] << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    solve();

    return 0;
}