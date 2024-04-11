#include <iostream>
#include <vector>
#include <cassert>

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    if (n * m * 4 - n * 2 - m * 2 < k) {
        std::cout << "NO" << std::endl;
        return;
    }

    std::vector<std::pair<int, char>> ans;
    ans.emplace_back(n - 1, 'D');
    for (int i = 0; i < n - 1; ++i) {
        ans.emplace_back(m - 1, 'R');
        ans.emplace_back(m - 1, 'L');
        ans.emplace_back(1, 'U');
    }

    ans.emplace_back(m - 1, 'R');
    for (int i = 0; i < m - 1; ++i) {
        ans.emplace_back(n - 1, 'D');
        ans.emplace_back(n - 1, 'U');
        ans.emplace_back(1, 'L');
    }

    std::vector<std::pair<int, char>> sol;
    for (auto p : ans) {
        int s = std::min(k, p.first);
        if (s == 0) continue;
        sol.emplace_back(s, p.second);
        k -= s;
        if (k == 0) break;
    }
    assert(k == 0);

    std::cout << "YES" << std::endl
              << sol.size() << std::endl;
    for (auto p : sol) {
        std::cout << p.first << " " << p.second << std::endl;
    }
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}