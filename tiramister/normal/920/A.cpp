#include <iostream>
#include <algorithm>
#include <vector>

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> xs(k);
    for (auto& x : xs) {
        std::cin >> x;
        --x;
    }

    for (int t = 0;; ++t) {
        std::vector<bool> ok(n, false);
        for (auto x : xs) {
            for (int i = x - t; i <= x + t; ++i) {
                if (i < 0 || n <= i) continue;
                ok[i] = true;
            }
        }

        if (std::all_of(ok.begin(), ok.end(), [](auto b) { return b; })) {
            std::cout << t + 1 << std::endl;
            break;
        }
    }
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