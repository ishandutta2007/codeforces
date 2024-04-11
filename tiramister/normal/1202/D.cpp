#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using lint = long long;

void solve() {
    lint n;
    std::cin >> n;

    std::vector<lint> ts;
    while (n > 0) {
        lint t = 2;
        while (t * (t - 1) / 2 <= n) ++t;

        ts.push_back(t - 1);
        n -= (t - 1) * (t - 2) / 2;
    }

    std::reverse(ts.begin(), ts.end());
    int zs = 0;
    std::cout << 1;
    for (auto t : ts) {
        while (zs < t) {
            std::cout << 3;
            ++zs;
        }
        std::cout << 7;
    }

    std::cout << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}