#include "bits/stdc++.h"
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int N, M;
        std::cin >> N >> M;
        std::vector<bool> dead(N);
        for (int j = 0; j < M; ++j) {
            int a, b, c;
            std::cin >> a >> b >> c;
            --b;
            dead[b] = true;
        }
        int s = 0;
        while (dead[s]) ++s;
        for (int u = 0; u < N; ++u) {
            if (u == s) continue;
            std::cout << u + 1 << ' ' << s + 1 << '\n';
        }
    }
    exit(0);
}