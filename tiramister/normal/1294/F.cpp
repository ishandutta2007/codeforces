#include <iostream>
#include <algorithm>
#include <numeric>
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

Graph<> tree;
std::vector<std::vector<std::pair<int, int>>> chss;
int ans;
std::vector<int> anss;

std::pair<int, int> dfs(int v, int p = -1) {
    auto& chs = chss[v];
    for (auto e : tree[v]) {
        if (e.dst == p) {
            chs.emplace_back(-1, -1);
        } else {
            chs.push_back(dfs(e.dst, v));
        }
    }
    chs.emplace_back(0, v);

    auto max = *std::max_element(chs.begin(), chs.end());
    ++max.first;
    return max;
}

void efs(int v, int p = -1,
         std::pair<int, int> par = std::make_pair(-1, -1)) {
    auto& chs = chss[v];
    chs.push_back(par);

    std::vector<int> idx(chs.size());
    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(),
              [&](int i, int j) { return chs[i] > chs[j]; });

    if (chs.size() >= 3) {
        int sum = 0;
        std::vector<int> s;
        for (int i = 0; i < 3; ++i) {
            sum += chs[idx[i]].first;
            s.push_back(chs[idx[i]].second);
        }

        if (sum > ans) {
            ans = sum;
            anss = s;
        }
    }

    for (int i = 0; i < (int)tree[v].size(); ++i) {
        const auto& e = tree[v][i];
        if (e.dst == p) continue;

        auto max = (idx[0] == i ? chs[idx[1]] : chs[idx[0]]);
        ++max.first;
        efs(e.dst, v, max);
    }
}

void solve() {
    int n;
    std::cin >> n;

    tree.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        tree[u].emplace_back(u, v);
        tree[v].emplace_back(v, u);
    }

    chss.resize(n);
    dfs(0);

    // for (int v = 0; v < n; ++v) {
    //     std::cerr << v << ": ";
    //     for (auto p : chss[v]) {
    //         std::cerr << "(" << p.first << "," << p.second << "), ";
    //     }
    //     std::cerr << std::endl;
    // }

    ans = 0;
    efs(0);

    std::cout << ans << std::endl;
    for (auto v : anss) std::cout << v + 1 << " ";
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}