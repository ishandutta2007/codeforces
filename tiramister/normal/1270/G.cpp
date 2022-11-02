#include <iostream>
#include <vector>
#include <functional>

std::vector<int> to, ans;
std::vector<bool> visited;

int dfs(int v) {
    if (visited[v]) {
        ans.push_back(v);
        return v;
    }

    visited[v] = true;
    int u = dfs(to[v]);
    if (u < 0 || u == v) return -1;
    ans.push_back(v);
    return u;
}

void solve() {
    int n;
    std::cin >> n;

    to.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        int a;
        std::cin >> a;
        to[i] = i - a;
    }

    ans.clear();
    visited.assign(n + 1, false);

    for (int v = 1; v <= n; ++v) {
        dfs(v);
        if (!ans.empty()) break;
    }

    std::cout << ans.size() << "\n";
    for (auto v : ans) {
        std::cout << v << " ";
    }
    std::cout << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();
    return 0;
}