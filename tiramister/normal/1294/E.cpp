#include <iostream>
#include <algorithm>
#include <vector>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

void solve() {
    int n, m;
    std::cin >> n >> m;

    auto grid = vec(n, vec(m, 0));
    for (auto& v : grid) {
        for (auto& x : v) {
            std::cin >> x;
            --x;
        }
    }

    int ans = 0;
    for (int j = 0; j < m; ++j) {
        std::vector<int> cnt(n, 0);
        for (int i = 0; i < n; ++i) {
            int x = grid[i][j];
            if (x >= n * m || x % m != j) continue;

            int s = i - x / m;
            if (s < 0) s += n;
            ++cnt[s];
        }

        int cost = n;
        for (int i = 0; i < n; ++i) {
            cost = std::min(cost, (n - cnt[i]) + i);
        }
        ans += cost;
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