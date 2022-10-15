#include "bits/stdc++.h"
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M;
    std::cin >> N >> M;
    std::vector<std::string> g(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> g[i];
    }
    std::vector<int> p(M);
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j + 1 < M; ++j) {
            if (g[i][j] == 'X' && g[i - 1][j + 1] == 'X') {
                p[j + 1] = 1;
            }
        }
    }
    std::partial_sum(p.begin(), p.end(), p.begin());
    auto query = [&](int l, int r) {
        return p[r] - (l ? p[l - 1] : 0);
    };
    int Q;
    std::cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int l, r;
        std::cin >> l >> r;
        --l, --r;
        std::cout << (l == r || !query(l + 1, r) ? "YES" : "NO") << '\n';
    }
    exit(0);
}