#include <iostream>
#include <algorithm>
#include <vector>

using lint = long long;

void solve() {
    int n;
    lint k;
    std::cin >> n >> k;

    std::vector<lint> xs(n);
    for (auto& x : xs) std::cin >> x;
    std::sort(xs.begin(), xs.end());

    lint ans = 0;
    for (int i = 1; i < n; ++i) {
        auto d = xs[i] - xs[0];
        if (d % k != 0) {
            std::cout << "-1\n";
            return;
        }
        ans += d / k;
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}