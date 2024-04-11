#include <iostream>
#include <algorithm>
#include <vector>

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    k = std::min(k, m - 1);

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;
    auto rxs = xs;
    std::reverse(rxs.begin(), rxs.end());

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int j = k - i;
        if (j < 0) continue;

        int min = 1 << 30;
        for (int l = 0; l < m - k; ++l) {
            int r = m - k - l - 1;
            min = std::min(min, std::max(xs[i + l], rxs[j + r]));
        }
        ans = std::max(ans, min);
    }

    std::cout << ans << std::endl;
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