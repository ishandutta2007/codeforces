#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

void solve() {
    std::vector<int> xs(4);
    for (auto& x : xs) std::cin >> x;

    int sum = std::accumulate(xs.begin(), xs.end(), 0);
    bool ok = (sum % 3 == 0);
    for (int i = 0; i < 3; ++i) {
        if (xs[i] > sum / 3) ok = false;
    }

    std::cout << (ok ? "YES" : "NO") << std::endl;
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