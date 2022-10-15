#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    int64_t L;
    std::cin >> N >> L;
    std::vector<int64_t> c(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> c[i];
    }
    for (int i = 0; i + 1 < N; ++i) {
        c[i + 1] = std::min(c[i + 1], 2 * c[i]);
    }
    while ((1LL << (N - 1)) <= L) {
        c.push_back(2 * c.back());
        ++N;
    }
    int64_t ans = std::numeric_limits<int64_t>::max(), pref = 0;
    for (int i = N - 1; i >= 0; --i) {
        if (L >> i & 1) {
            pref += c[i];
        } else {
            ans = std::min(ans, pref + c[i]);
        }
    }
    ans = std::min(ans, pref);
    std::cout << ans << '\n';
    exit(0);
}