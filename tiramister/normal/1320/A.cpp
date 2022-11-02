#include <iostream>
#include <map>

using lint = long long;

void solve() {
    std::map<int, lint> sums;

    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        int d = x - i;
        if (!sums.count(d)) sums[d] = 0;
        sums[d] += x;
    }

    lint ans = 0;
    for (auto p : sums) ans = std::max(ans, p.second);
    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}