#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        std::cin >> N;
        std::map<int, int> f;
        for (int i = 0; i < N; ++i) {
            int a;
            std::cin >> a;
            ++f[std::abs(a)];
        }
        int ans = 0;
        for (auto [k, v] : f) {
            ans += std::min(v, 1 + !!k);
        }
        std::cout << ans << '\n';
    }
    exit(0);
}