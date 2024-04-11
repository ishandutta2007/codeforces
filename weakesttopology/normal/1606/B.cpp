#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int64_t N, K;
        std::cin >> N >> K;
        int64_t M = 1, ans = 0;
        while (M < K) {
            M *= 2;
            ++ans;
        }
        ans += (N - M + K - 1) / K;
        std::cout << ans << '\n';
    }
    exit(0);
}