#include <iostream>
#include <algorithm>
#include <vector>

using lint = long long;

void solve() {
    int n, m;
    lint k;
    std::cin >> n >> m >> k;

    std::vector<lint> xs(n);
    for (auto& x : xs) std::cin >> x;

    lint ans = 0;
    for (int q = 0; q < m && !xs.empty(); ++q) {
        lint sum = 0, min = 0;

        for (int i = 0; i < n; ++i) {
            auto x = xs[i];
            if (i % m == 0) {
                min = std::min(min, sum);
                x -= k;
            }
            sum += x;
            ans = std::max(ans, sum - min);
        }

        xs.erase(xs.begin());
        --n;
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}