#include <iostream>
#include <algorithm>
#include <vector>

void solve() {
    std::vector<int> xs(3);
    for (auto& x : xs) std::cin >> x;

    int ans = 0;
    for (int p = 0; p < (1 << 8); ++p) {
        auto ys = xs;

        for (int b = 0; b < 8; ++b) {
            if (!((p >> b) & 1)) continue;

            for (int i = 0; i < 3; ++i) {
                if (!((b >> i) & 1)) continue;
                --ys[i];
            }
        }

        if (*std::min_element(ys.begin(), ys.end()) >= 0) {
            ans = std::max(ans, __builtin_popcount(p));
        }
    }

    std::cout << ans - 1 << std::endl;
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