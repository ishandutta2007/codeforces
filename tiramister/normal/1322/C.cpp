#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

template <class T>
T gcd(T n, T m) {
    while (m != 0) {
        n %= m;
        std::swap(n, m);
    }
    return n;
}

using lint = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<lint> xs(n);
    for (auto& x : xs) std::cin >> x;

    std::vector<std::vector<int>> graph(n);
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        graph[v].push_back(u);
    }

    for (auto& v : graph) std::sort(v.begin(), v.end());
    std::vector<int> idxs(n);
    std::iota(idxs.begin(), idxs.end(), 0);
    std::sort(idxs.begin(), idxs.end(),
              [&](int i, int j) { return graph[i] < graph[j]; });

    lint ans = 0, acc = 0;
    for (int i = 0; i < n; ++i) {
        if (graph[idxs[i]].empty()) continue;

        acc += xs[idxs[i]];
        if (i == n - 1 || graph[idxs[i]] != graph[idxs[i + 1]]) {
            ans = gcd(ans, acc);
            acc = 0;
        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}