#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>

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

Graph<> tree;
std::vector<int> cs, sz, ans;

int szdfs(int v) {
    sz[v] = 1;
    for (auto e : tree[v]) {
        sz[v] += szdfs(e.dst);
    }

    if (cs[v] > sz[v] - 1) {
        std::cout << "NO" << std::endl;
        std::exit(0);
    }

    return sz[v];
}

void dfs(int v, std::vector<int>& ids) {
    assert(sz[v] == (int)ids.size());
    ans[v] = ids[cs[v]];

    int it = 0;
    for (auto e : tree[v]) {
        int u = e.dst;
        std::vector<int> nids;

        while ((int)nids.size() < sz[u]) {
            while (ids[it] == ans[v]) ++it;
            nids.push_back(ids[it++]);
        }

        dfs(u, nids);
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    tree = Graph<>(n);
    cs.resize(n);
    int r = -1;
    for (int v = 0; v < n; ++v) {
        int p;
        std::cin >> p >> cs[v];
        if (--p < 0) {
            r = v;
        } else {
            tree[p].emplace_back(p, v);
        }
    }

    sz.resize(n);
    szdfs(r);

    std::vector<int> ids(n);
    std::iota(ids.begin(), ids.end(), 1);

    ans.resize(n);
    dfs(r, ids);

    std::cout << "YES\n";
    for (int v = 0; v < n; ++v) {
        std::cout << ans[v] << " ";
    }
    std::cout << "\n";
    return 0;
}