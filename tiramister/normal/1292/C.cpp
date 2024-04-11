#include <iostream>
#include <vector>

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

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

using lint = long long;

Graph<> tree;
std::vector<lint> sz;

// calculate the size of subtrees
lint szdfs(int v, int p) {
    sz[v] = 1;
    for (auto e : tree[v]) {
        if (e.dst == p) continue;
        sz[v] += szdfs(e.dst, v);
    }
    return sz[v];
}

// the ends of the current path is u and v
// each root is ru and rv
lint dfs(int u, int v, int ru, int rv) {
    static auto dp = vec(sz.size(), vec(sz.size(), -1LL));
    if (dp[u][v] >= 0) return dp[u][v];

    auto& ret = dp[u][v];
    ret = 0;
    for (auto e : tree[u]) {
        if (e.dst == v || e.dst == rv || sz[e.dst] > sz[u]) continue;
        ret = std::max(ret, sz[e.dst] * sz[v] + dfs(e.dst, v, ru, rv));
    }
    for (auto e : tree[v]) {
        if (e.dst == u || e.dst == ru || sz[e.dst] > sz[v]) continue;
        ret = std::max(ret, sz[u] * sz[e.dst] + dfs(u, e.dst, ru, rv));
    }
    return ret;
}

void solve() {
    int n;
    std::cin >> n;
    sz.resize(n);

    tree = Graph<>(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        tree[u].emplace_back(u, v);
        tree[v].emplace_back(v, u);
    }

    lint ans = 0;
    for (int v = 0; v < n; ++v) {
        for (auto e : tree[v]) {
            int u = e.dst;
            if (u > v) continue;

            // update size
            szdfs(u, v);
            szdfs(v, u);

            ans = std::max(ans, sz[u] * sz[v] + dfs(u, v, u, v));
        }
    }
    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}