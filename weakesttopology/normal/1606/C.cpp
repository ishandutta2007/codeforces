#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int N, K;
        std::cin >> N >> K;
        ++K;
        std::vector<int> a(N), p(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> a[i];
            p[i] = 1;
            for (int j = 0; j < a[i]; ++j) {
                p[i] *= 10;
            }
        }
        std::vector<int64_t> sum(N);
        for (int i = 0; i + 1 < N; ++i) {
            sum[i + 1] = p[i + 1] / p[i] - 1 + sum[i];
        }
        int64_t S = 0;
        for (int i = N - 1; i >= 0; --i) {
            if (sum[i] >= K) {
                continue;
            } else {
                int64_t m = K - sum[i];
                S += m * p[i];
                K -= m;
            }
        }
        std::cout << S << '\n';
    }
    exit(0);
}