#include <iostream>
#include <vector>

using lint = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<lint> sums(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        lint a;
        std::cin >> a;
        sums[i + 1] = sums[i] + a;
    }
    lint sum = sums.back();

    lint max = 0, pmin = 0;
    for (int i = 1; i < n; ++i) {
        max = std::max(max, sums[i] - pmin);
        pmin = std::min(pmin, sums[i]);
    }
    pmin = sums[1];
    for (int i = 2; i <= n; ++i) {
        max = std::max(max, sums[i] - pmin);
        pmin = std::min(pmin, sums[i]);
    }

    std::cout << (sum > max ? "YES" : "NO") << std::endl;
}

int main() {
    int q;
    std::cin >> q;
    while (q--) solve();
    return 0;
}