#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

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

Graph<> graph;
std::vector<int> xdp, odp, chs;
std::vector<std::set<std::pair<int, int>>> xss, oss;

int ans;

void dfs(int v, int p = -1) {
    auto& ch = chs[v];
    ch = 0;

    auto& xs = xss[v];
    auto& os = oss[v];
    xs.emplace(0, -1);
    os.emplace(0, -1);

    for (auto e : graph[v]) {
        int u = e.dst;
        if (u == p) continue;

        ++ch;
        dfs(u, v);

        os.emplace(-xdp[u], u);
        xs.emplace(-xdp[u], u);
        xs.emplace(-odp[u], u);
    }

    odp[v] = 1 + -(os.begin()->first);
    xdp[v] = ch - 1 + -(xs.begin()->first);
}

void efs(int v, int p = -1, int ov = -1, int xv = -1) {
    auto& ch = chs[v];
    auto& xs = xss[v];
    auto& os = oss[v];

    if (p != -1) {
        // update dp
        os.emplace(-xv, p);
        xs.emplace(-xv, p);
        xs.emplace(-ov, p);
        ++ch;

        odp[v] = 1 + -(os.begin()->first);
        xdp[v] = ch - 1 + -(xs.begin()->first);
    }

    // std::cerr << v << ": " << odp[v] << " " << xdp[v] << std::endl;
    ans = std::max({ans, odp[v], xdp[v]});

    for (auto e : graph[v]) {
        int u = e.dst;
        if (u == p) continue;

        --ch;

        auto oit = os.begin();
        while (oit->second == u) ++oit;
        auto xit = xs.begin();
        while (xit->second == u) ++xit;

        auto cov = 1 + -(oit->first);
        auto cxv = ch - 1 + -(xit->first);

        efs(u, v, cov, cxv);

        ++ch;
    }
}

void solve() {
    int n;
    std::cin >> n;

    graph.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;

        graph[u].emplace_back(u, v);
        graph[v].emplace_back(v, u);
    }

    xdp.resize(n);
    odp.resize(n);
    chs.resize(n);

    xss.resize(n);
    oss.resize(n);

    dfs(0);

    ans = 0;

    efs(0);

    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}