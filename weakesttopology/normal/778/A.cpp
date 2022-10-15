#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string t, p;
    std::cin >> t >> p;
    int N = t.size(), M = p.size();
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
        --a[i];
    }
    int L = 0, R = N + 1;
    while (L + 1 < R) {
        int K = (L + R) / 2;
        std::vector<bool> dead(N);
        for (int j = 0; j < K; ++j) {
            dead[a[j]] = true;
        }
        int ptr = 0;
        for (int i = 0; i < N && ptr < M; ++i) {
            if (!dead[i] && t[i] == p[ptr]) {
                ++ptr;
            }
        }
        ptr == M ? L = K : R = K;
    }
    std::cout << L << '\n';
    exit(0);
}