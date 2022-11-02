#include <iostream>
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
std::set<int> ds;
int ans;

bool dfs(int v, int p = -1, int d = 0) {
    if (graph[v].size() == 1) {
        ds.insert(d);
        return true;
    }

    bool leaf = false;
    for (auto e : graph[v]) {
        int u = e.dst;
        if (u == p) continue;

        if (dfs(u, v, 1 - d)) {
            leaf = true;
        } else {
            ++ans;
        }
    }
    if (leaf) ++ans;

    return false;
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

    int r;
    for (r = 0; r < n; ++r) {
        if (graph[r].size() != 1) break;
    }

    ds.clear();
    ans = 0;
    dfs(r);

    std::cout << (ds.size() == 1 ? 1 : 3) << " "
              << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}