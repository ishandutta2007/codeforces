#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <limits>
#include <tuple>
#include <functional>

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

template <class T>
struct SegmentTree {
    using Merger = std::function<T(T, T)>;

    int length;
    std::vector<T> dat;
    T unit;
    Merger merge;

    explicit SegmentTree(int n, T unit, Merger merge)
        : length(1), unit(unit), merge(merge) {
        while (length < n) length <<= 1;
        dat.assign(length * 2, unit);
    }

    T query(int ql, int qr, int nidx, int nl, int nr) {
        if (nr <= ql || qr <= nl) return unit;
        if (ql <= nl && nr <= qr) return dat[nidx];

        int nm = (nl + nr) / 2;
        T vl = query(ql, qr, nidx * 2 + 0, nl, nm);
        T vr = query(ql, qr, nidx * 2 + 1, nm, nr);
        return merge(vl, vr);
    }

    T query(int ql, int qr) { return query(ql, qr, 1, 0, length); }

    void update(int nidx, T elem) {
        nidx += length;
        dat[nidx] = elem;

        while (nidx > 0) {
            nidx >>= 1;
            T vl = dat[nidx * 2 + 0];
            T vr = dat[nidx * 2 + 1];
            dat[nidx] = merge(vl, vr);
        }
    }
};

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> xs(k);
    for (auto& x : xs) {
        std::cin >> x;
        --x;
    }

    Graph<int> graph(n);
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        graph[u].emplace_back(u, v, 1);
        graph[v].emplace_back(v, u, 1);
    }

    auto sdist = dijkstra(graph, 0),
         gdist = dijkstra(graph, n - 1);

    std::vector<int> sidx(k);
    std::iota(sidx.begin(), sidx.end(), 0);
    std::sort(sidx.begin(), sidx.end(),
              [&](int i, int j) {
                  return sdist[xs[i]] < sdist[xs[j]];
              });

    std::vector<int> gidx(k);
    std::iota(gidx.begin(), gidx.end(), 0);
    std::sort(gidx.begin(), gidx.end(),
              [&](int i, int j) {
                  return gdist[xs[i]] > gdist[xs[j]];
              });

    int ok = -1, ng = sdist[n - 1] + 1;
    while (ng - ok > 1) {
        int mid = (ok + ng) / 2;

        bool judge = false;
        SegmentTree<int> seg(n, 0,
                             [](int a, int b) { return a + b; });

        int j = 0;
        for (int i = 0; i < k; ++i) {
            int v = xs[sidx[i]];
            int dsv = sdist[v];
            while (j < k && gdist[xs[gidx[j]]] >= mid - dsv - 1) {
                int u = xs[gidx[j]];
                int dsu = sdist[u];
                seg.update(dsu, seg.query(dsu, dsu + 1) + 1);
                ++j;
            }

            int dgv = gdist[v];
            int lower = 0;
            if (dsv >= mid - dgv - 1) ++lower;
            if (seg.query(mid - dgv - 1, n) > lower) judge = true;
        }

        if (judge) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    std::cout << ok << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}