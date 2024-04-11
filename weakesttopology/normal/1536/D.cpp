#include "bits/stdc++.h"
const int inf = std::numeric_limits<int>::max();
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        std::cin >> N;
        std::vector<int> b(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> b[i];
        }
        std::set<int> S;
        bool good = true;
        for (int i = 0; i < N; ++i) {
            S.insert(b[i]);
            if (i + 1 < N) {
                int l = b[i], r = b[i + 1];
                if (r < l) std::swap(l, r);
                auto iter = S.upper_bound(l);
                if (iter != S.end() && *iter < r) {
                    good = false;
                }
            }
        }
        std::cout << (good ? "YES" : "NO") << '\n';
    }
    exit(0);
}