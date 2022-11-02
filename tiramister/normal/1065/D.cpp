#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

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

constexpr int INF = 1 << 30;
constexpr std::pair<int, int> PINF = std::make_pair(INF, INF);

void solve() {
    int n;
    std::cin >> n;

    int nn = n * n * 3;
    auto enc = [&](int x, int y, int t) {
        return (x * n + y) * 3 + t;
    };

    Graph<int> graph(nn);
    for (int x1 = 0; x1 < n; ++x1) {
        for (int y1 = 0; y1 < n; ++y1) {
            for (int x2 = 0; x2 < n; ++x2) {
                for (int y2 = 0; y2 < n; ++y2) {
                    if (x1 == x2 || y1 == y2) {
                        graph.span(true, enc(x1, y1, 0), enc(x2, y2, 0), 0);
                    }
                    if (std::abs(x1 - x2) == std::abs(y1 - y2)) {
                        graph.span(true, enc(x1, y1, 1), enc(x2, y2, 1), 0);
                    }
                    if ((std::abs(x1 - x2) == 1 && std::abs(y1 - y2) == 2) ||
                        (std::abs(x1 - x2) == 2 && std::abs(y1 - y2) == 1)) {
                        graph.span(true, enc(x1, y1, 2), enc(x2, y2, 2), 0);
                    }
                }
            }

            for (int t = 0; t < 3; ++t) {
                graph.span(false, enc(x1, y1, t), enc(x1, y1, (t + 1) % 3), 1);
            }
        }
    }

    std::vector<std::pair<int, int>> pos(n * n);
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            int a;
            std::cin >> a;
            pos[--a] = std::make_pair(x, y);
        }
    }

    std::vector<std::pair<int, int>> dist(nn, std::make_pair(0, 0));

    for (int i = 0; i < n * n - 1; ++i) {
        auto [sx, sy] = pos[i];

        MinHeap<std::pair<std::pair<int, int>, int>> heap;
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                for (int t = 0; t < 3; ++t) {
                    if (x == sx && y == sy) {
                        heap.emplace(dist[enc(x, y, t)], enc(x, y, t));
                    } else {
                        dist[enc(x, y, t)] = PINF;
                    }
                }
            }
        }

        while (!heap.empty()) {
            auto [d, v] = heap.top();
            heap.pop();
            if (d > dist[v]) continue;

            for (auto e : graph[v]) {
                auto nd = d;
                nd.first += 1;
                nd.second += e.cost;

                int u = e.dst;
                if (dist[u] <= nd) continue;

                dist[u] = nd;
                heap.emplace(nd, u);
            }
        }
    }

    auto ans = PINF;
    {
        auto [x, y] = pos.back();
        for (int t = 0; t < 3; ++t) {
            ans = std::min(ans, dist[enc(x, y, t)]);
        }
    }

    std::cout << ans.first << " " << ans.second << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}