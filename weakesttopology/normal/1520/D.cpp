#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        std::cin >> N;
        std::map<int, int> cnt;
        for (int i = 0; i < N; ++i) {
            int a;
            std::cin >> a;
            ++cnt[a - i];
        }
        int64_t ans = 0;
        for (auto [k, v] : cnt) {
            ans += 1LL * v * (v - 1) / 2;
        }
        std::cout << ans << '\n';
    }
    exit(0);
}