#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int64_t N;
        std::cin >> N;
        int d = 0;
        for (int64_t M = N; M; M /= 10, ++d);
        int64_t ans = 9 * (d - 1);
        int64_t M = 0;
        for (int i = 0; i < d; ++i) {
            M = 10 * M + 1;
        }
        for (int c = 1; c * M <= N; ++c) {
            ++ans;
        }
        std::cout << ans << '\n';
    }
    exit(0);
}