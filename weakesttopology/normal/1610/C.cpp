#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        std::cin >> N;
        std::vector<int> a(N), b(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> a[i] >> b[i];
        }
        int L = 1, R = N + 1;
        while (L + 1 < R) {
            int M = (L + R) / 2;
            int k = 0;
            for (int i = 0; i < N; ++i) {
                if (k <= b[i] && M - (k + 1) <= a[i]) {
                    ++k;
                }
            }
            k >= M ? L = M : R = M;
        }
        std::cout << L << '\n';
    }
    exit(0);
}