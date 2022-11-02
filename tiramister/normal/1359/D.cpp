#include <iostream>
#include <vector>

constexpr int X = 30;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;

    int ans = 0;
    std::vector<bool> used(n, false);

    for (int r = X; r >= -X; --r) {
        int pmin = 0, acc = 0;
        for (int i = 0; i < n; ++i) {
            if (used[i]) {
                pmin = acc = 0;
            } else {
                acc += xs[i];
                ans = std::max(ans, acc - pmin - r);
                pmin = std::min(pmin, acc);
            }
            if (xs[i] == r) used[i] = true;
        }
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}