#include <iostream>
#include <vector>

using lint = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<lint> xs(n);
    for (auto& x : xs) std::cin >> x;

    lint sum = 0;
    for (int i = 0; i < n; i += 2) sum += xs[i];

    lint ans = sum;
    {
        lint min = 0, acc = 0;
        for (int i = 0; i + 1 < n; i += 2) {
            acc += xs[i + 1] - xs[i];
            ans = std::max(ans, sum + acc - min);
            min = std::min(min, acc);
        }
    }

    {
        lint min = 0, acc = 0;
        for (int i = 1; i + 1 < n; i += 2) {
            acc += xs[i] - xs[i + 1];
            ans = std::max(ans, sum + acc - min);
            min = std::min(min, acc);
        }
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}