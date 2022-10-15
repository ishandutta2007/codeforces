#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int64_t S, N, K;
        std::cin >> S >> N >> K;
        std::string res;
        if (S < K) {
            res = "NO";
        } else if (S == K) {
            res = "YES";
        } else {
            int64_t M = S + K + 1, A = S + K, r = 1 + A % K;
            M -= r * ((A / K + 1) % 2);
            A -= r;
            M -= (K - r) * ((A / K + 1) % 2);
            res = M >= 2 * N + 1 ? "NO" : "YES";
        }
        std::cout << res << '\n';
    }
    exit(0);
}