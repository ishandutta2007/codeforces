#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

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
    int n;
    std::cin >> n;

    std::map<std::pair<int, int>, std::vector<int>> es;
    // 

    for (int u = 0; u < n - 2; ++u) {
        std::vector<int> vs(3);
        for (auto& v : vs) {
            std::cin >> v;
            --v;
        }

        for (int i = 0; i < 3; ++i) {
            int a = vs[i], b = vs[(i + 1) % 3];
            if (a > b) std::swap(a, b);
            es[std::make_pair(a, b)].push_back(u);
        }
    }

    // 
    if (n == 3) {
        std::cout << "1 2 3" << std::endl
                  << "1" << std::endl;
        return;
    }

    /* ----------  ---------- */
    // 
    Graph<> perm(n);
    for (const auto& e : es) {
        auto vs = e.second;
        if (vs.size() == 1) {
            int u, v;
            std::tie(u, v) = e.first;
            perm[u].emplace_back(u, v);
            perm[v].emplace_back(v, u);
        }
    }

    // 0
    std::vector<int> ps{0};
    int prev = 0, cur = perm[0][0].dst;
    while (cur != 0) {
        ps.push_back(cur);
        for (auto e : perm[cur]) {
            if (e.dst == prev) continue;
            prev = cur;
            cur = e.dst;
            break;
        }
    }

    for (auto v : ps) std::cout << v + 1 << " ";
    std::cout << std::endl;

    /* ----------  ---------- */
    // 
    Graph<std::pair<int, int>> tree(n - 2);
    std::vector<int> deg(n - 2, 0);

    for (const auto& e : es) {
        auto vs = e.second;

        if (vs.size() == 2) {
            int u = vs[0], v = vs[1];
            auto p = e.first;
            tree[u].emplace_back(u, v, p);
            tree[v].emplace_back(v, u, p);
            ++deg[u], ++deg[v];
        }
    }

    // 
    std::queue<int> que;
    for (int v = 0; v < n - 2; ++v) {
        if (deg[v] == 1) que.push(v);
    }

    std::vector<int> qs;
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        qs.push_back(v);

        for (auto e : tree[v]) {
            int u = e.dst;
            if (--deg[u] == 1) que.push(u);
        }
    }

    for (auto v : qs) std::cout << v + 1 << " ";
    std::cout << std::endl;
}

int main() {
    int q;
    std::cin >> q;
    while (q--) solve();
    return 0;
}