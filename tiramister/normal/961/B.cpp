#include <iostream>
#include <vector>

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int c;
        std::cin >> c;
        if (c) {
            ans += xs[i];
            xs[i] = 0;
        }
    }

    std::vector<int> sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        sum[i + 1] = sum[i] + xs[i];
    }

    int max = 0;
    for (int i = 0; i + k <= n; ++i) {
        max = std::max(max, sum[i + k] - sum[i]);
    }
    std::cout << ans + max << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}