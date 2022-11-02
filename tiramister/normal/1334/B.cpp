#include <iostream>
#include <algorithm>
#include <vector>

using lint = long long;

void solve() {
    int n;
    lint x;
    std::cin >> n >> x;

    std::vector<lint> ys(n);
    for (auto& y : ys) {
        std::cin >> y;
        y -= x;
    }
    std::sort(ys.rbegin(), ys.rend());

    lint sum = 0;
    int i;
    for (i = 0; i < n; ++i) {
        sum += ys[i];
        if (sum < 0) break;
    }

    std::cout << i << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}