#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t N, K;
    int M;
    std::cin >> N >> M >> K;
    std::vector<int64_t> p(M);
    for (int j = 0; j < M; ++j) {
        std::cin >> p[j];
    }
    int64_t offset = 0, r = 0;
    int ops = 0, kill = 0;
    for (int j = 0; j < M;) {
        if (r == 0) {
            offset += (p[j] - 1 - offset) / K * K;
        }
        while (j < M && p[j] - offset + r <= K) {
            int64_t add = p[j] - offset;
            r += add;
            offset += add;
            ++kill;
            ++j;
        }
        if (j < M) {
            offset += K - r;
            if (kill) {
                r = K - kill;
                kill = 0;
                ++ops;
            } else {
                r = 0;
            }
        }
    }
    if (kill) {
        ++ops;
    }
    std::cout << ops << '\n';
    exit(0);
}