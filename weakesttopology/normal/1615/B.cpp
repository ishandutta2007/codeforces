#include <bits/stdc++.h>
constexpr int K = 18;
int cnt[K][1 << K];
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    for (int k = 0; k < K; ++k) {
        for (int x = 0; x < (1 << K); ++x) {
            if (x >> k & 1) {
                ++cnt[k][x];
            }
        }
        std::partial_sum(std::begin(cnt[k]), std::end(cnt[k]), std::begin(cnt[k]));
    }
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int l, r;
        std::cin >> l >> r;
        int ans = std::numeric_limits<int>::max(), len = r - l + 1;
        for (int k = 0; k < K; ++k) {
            ans = std::min(ans, len - (cnt[k][r] - cnt[k][l - 1]));
        }
        std::cout << ans << '\n';
    }
    exit(0);
}