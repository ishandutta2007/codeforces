#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, C;
    std::cin >> N >> C;
    std::vector<int> p(N), s(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> p[i];
    }
    for (int i = 0; i < N; ++i) {
        std::cin >> s[i];
    }
    const long long inf = std::numeric_limits<long long>::max() / 2;
    std::vector<long long> dp(N + 1, inf);
    dp[0] = 0;
    for (int i = 0; i < N; ++i) {
        std::vector<long long> dpnxt(N + 1, inf);
        for (int k = 0; k <= i; ++k) {
            dpnxt[k] = std::min(dpnxt[k], dp[k] + p[i] + 1LL * k * C);
            dpnxt[k + 1] = std::min(dpnxt[k + 1], dp[k] + s[i]);
        }
        swap(dp, dpnxt);
    }
    long long ans = *std::min_element(dp.begin(), dp.end());
    std::cout << ans << '\n';
}