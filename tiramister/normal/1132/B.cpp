#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using lint = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<lint> xs(n);
    for (auto& x : xs) std::cin >> x;
    std::sort(xs.rbegin(), xs.rend());

    lint sum = std::accumulate(xs.begin(), xs.end(), 0LL);

    int q;
    std::cin >> q;
    while (q--) {
        int m;
        std::cin >> m;
        std::cout << sum - xs[--m] << "\n";
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}