#include <iostream>
#include <algorithm>
#include <vector>

using lint = long long;

void solve() {
    int n;
    lint m;
    std::cin >> n >> m;

    std::vector<lint> xs(n);
    for (auto& x : xs) std::cin >> x;
    std::sort(xs.rbegin(), xs.rend());

    int ans = 0;
    lint sz = 0;
    for (auto x : xs) {
        ++sz;
        if (sz * x >= m) {
            ++ans;
            sz = 0;
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