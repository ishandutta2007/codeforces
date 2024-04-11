#include <iostream>
#include <vector>

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> ps(m);
    for (auto& p : ps) std::cin >> p;

    for (int i = 0; i < m; ++i) {
        if (i + ps[i] > n) {
            std::cout << -1 << std::endl;
            return;
        }
    }

    std::vector<int> ans(m);
    int r = n - 1;
    for (int i = m - 1; i >= 0; --i) {
        int l = std::max(i, r - ps[i] + 1);
        ans[i] = l;
        r = l - 1;
    }

    if (r >= 0) {
        std::cout << -1 << std::endl;
        return;
    }

    for (auto& a : ans) std::cout << a + 1 << " ";
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}