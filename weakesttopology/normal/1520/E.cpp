#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        std::cin >> N;
        std::vector<int> a;
        for (int i = 0; i < N; ++i) {
            char c;
            std::cin >> c;
            if (c == '*') {
                a.push_back(i);
            }
        }
        int K = a.size();
        auto f = [&](int d) {
            int64_t cost = 0;
            for (int j = 0; j < K; ++j) {
                cost += std::abs(d + j - a[j]);
            }
            return cost;
        };
        int L = -1, R = N - 1;
        // f(-1) = infinity
        // f(L) > f(L + 1)
        // f(R) <= f(R + 1)
        // f(N) = infinity
        while (L + 1 < R) {
            int M = (L + R) / 2;
            f(M) <= f(M + 1) ? R = M : L = M;
        }
        std::cout << f(R) << '\n';
    }
    exit(0);
}