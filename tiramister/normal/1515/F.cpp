#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cassert>

template <class T>
using MaxHeap = std::priority_queue<T>;

struct UnionFind {
    std::vector<int> par;
    int gnum;

    explicit UnionFind(int n) : par(n, -1), gnum(n) {}

    int find(int v) {
        return (par[v] < 0) ? v : (par[v] = find(par[v]));
    }

    // u <- v
    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;

        // if (par[u] > par[v]) std::swap(u, v);
        par[u] += par[v];
        par[v] = u;
        --gnum;
    }

    bool same(int u, int v) { return find(u) == find(v); }
    bool ispar(int v) { return par[v] < 0; }
    int size(int v) { return -par[find(v)]; }
};

using namespace std;
using lint = long long;

void solve() {
    int n, m;
    lint x;
    cin >> n >> m >> x;

    MaxHeap<pair<lint, int>> heap;
    vector<lint> xs(n);
    {
        lint sum = 0;
        for (int v = 0; v < n; ++v) {
            cin >> xs[v];
            heap.emplace(xs[v], v);
            sum += xs[v];
        }

        if (sum < x * (n - 1)) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";

    vector<set<pair<int, int>>> graph(n);
    {
        UnionFind uf(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;

            if (uf.same(u, v)) continue;
            uf.unite(u, v);

            graph[u].emplace(v, i);
            graph[v].emplace(u, i);
        }
    }

    vector<bool> used(m, false);
    UnionFind uf(n);

    for (int q = n - 1; q > 0;) {
        auto [a, v] = heap.top();
        heap.pop();
        if (xs[v] < 0) continue;
        --q;

        auto it = graph[v].begin();
        while (true) {
            assert(it != graph[v].end());

            auto [u, i] = *it;
            u = uf.find(u);

            if (used[i]) {
                it = graph[v].erase(it);
            } else if (xs[u] >= 0 && xs[u] + xs[v] >= x) {
                break;
            } else {
                ++it;
            }
        }

        auto [u, i] = *it;
        u = uf.find(u);
        graph[v].erase(it);

        cout << i + 1 << "\n";
        used[i] = true;

        if (graph[u].size() < graph[v].size()) swap(u, v);
        // u <- v
        uf.unite(u, v);
        xs[u] += xs[v] - x;
        xs[v] = -1;

        for (auto p : graph[v]) graph[u].insert(p);
        graph[v].clear();

        heap.emplace(xs[u], u);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    solve();

    return 0;
}