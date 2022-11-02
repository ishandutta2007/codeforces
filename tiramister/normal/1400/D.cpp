#include <iostream>
#include <vector>

using lint = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n);
    for (auto& x : xs) {
        std::cin >> x;
        --x;
    }

    lint ans = 0;
    std::vector<lint> fcnt(n, 0);
    for (int i = 0; i < n; ++i) {
        lint sum = 0;
        for (int j = i + 1; j < n; ++j) {
            if (xs[i] == xs[j]) ans += sum;
            sum += fcnt[xs[j]];
        }
        ++fcnt[xs[i]];
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