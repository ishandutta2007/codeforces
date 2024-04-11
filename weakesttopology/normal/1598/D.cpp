#include <iostream>
#include <vector>
#include <algorithm>
int64_t C(int64_t N, int64_t K) {
    int64_t num = 1, den = 1;
    for (int64_t i = 0; i < K; ++i) {
        num *= N - i;
        den *= K - i;
    }
    return num / den;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        std::cin >> N;
        std::vector<int> a(N), b(N), fb(N);
        std::vector<std::vector<int>> E(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> a[i] >> b[i];
            --a[i], --b[i];
            E[a[i]].push_back(i);
            ++fb[b[i]];
        }
        int64_t dp[4]{}, ans = 0;
        dp[0] = 1;
        for (int e = 0; e < N; ++e) {
            int64_t sz = E[e].size();
            for (int x = 2; x >= 0; --x) {
                dp[x + 1] += dp[x] * sz;
            }
            ans += C(sz, 3);
            int64_t pref = 0;
            for (int j = 0; j < sz; ++j) {
                int i = E[e][j];
                ans += pref - 1LL * j * (fb[b[i]] - 1);
                pref += N - sz - (fb[b[i]] - 1);
            }
        }
        ans += dp[3];
        std::cout << ans << '\n';
    }
    exit(0);
}