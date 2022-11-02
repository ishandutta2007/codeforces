#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <set>

struct UnionFind {
    std::vector<int> par, sz;
    int gnum;

    explicit UnionFind(int n)
        : par(n), sz(n, 1), gnum(n) {
        std::iota(par.begin(), par.end(), 0);
    }

    int find(int v) {
        return (par[v] == v) ? v : (par[v] = find(par[v]));
    }

    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;

        if (sz[u] < sz[v]) std::swap(u, v);
        sz[u] += sz[v];
        par[v] = u;
        --gnum;
    }

    bool same(int u, int v) { return find(u) == find(v); }
    bool ispar(int v) { return v == find(v); }
    int size(int v) { return sz[find(v)]; }
};

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

void solve() {
    int n, m;
    std::cin >> n >> m;

    if (n <= 5000) {
        std::vector<std::vector<bool>> rel(n, std::vector<bool>(n, true));
        while (m--) {
            int u, v;
            std::cin >> u >> v;
            --u, --v;
            rel[u][v] = rel[v][u] = false;
        }

        UnionFind uf(n);
        for (int v = 0; v < n; ++v) {
            for (int u = 0; u < v; ++u) {
                if (rel[u][v]) uf.unite(u, v);
            }
        }

        std::vector<int> ans;
        for (int v = 0; v < n; ++v) {
            if (uf.ispar(v)) ans.push_back(uf.size(v));
        }
        std::sort(ans.begin(), ans.end());

        std::cout << ans.size() << std::endl;
        for (auto a : ans) std::cout << a << " ";
        std::cout << std::endl;

    } else {
        Graph<> graph(n);

        while (m--) {
            int u, v;
            std::cin >> u >> v;
            --u, --v;
            graph[u].emplace_back(u, v);
            graph[v].emplace_back(v, u);
        }

        std::set<int> big, small;
        for (int v = 0; v < n; ++v) {
            if ((int)graph[v].size() < n - 100) {
                big.insert(v);
            } else {
                small.insert(v);
            }
        }

        while (true) {
            std::vector<int> erased;
            for (auto v : small) {
                auto sbig = big;
                for (auto e : graph[v]) sbig.erase(e.dst);
                if (!sbig.empty()) erased.push_back(v);
            }
            if (erased.empty()) break;

            for (auto v : erased) {
                small.erase(v);
                big.insert(v);
            }
        }

        std::vector<int> sidx(n, -1);
        m = 0;
        for (auto v : small) sidx[v] = m++;

        std::vector<std::vector<bool>> rel(m, std::vector<bool>(m, true));
        for (auto v : small) {
            int i = sidx[v];
            for (auto e : graph[v]) {
                int j = sidx[e.dst];
                if (j != -1) rel[i][j] = rel[j][i] = false;
            }
        }

        UnionFind uf(m);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < i; ++j) {
                if (rel[i][j]) uf.unite(i, j);
            }
        }

        std::vector<int> ans{(int)big.size()};
        for (int i = 0; i < m; ++i) {
            if (uf.ispar(i)) ans.push_back(uf.size(i));
        }
        std::sort(ans.begin(), ans.end());

        std::cout << ans.size() << std::endl;
        for (auto a : ans) std::cout << a << " ";
        std::cout << std::endl;
    }
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}