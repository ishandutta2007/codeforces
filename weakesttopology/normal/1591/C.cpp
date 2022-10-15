#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int N, K;
        std::cin >> N >> K;
        std::vector<int> xs[2];
        for (int i = 0; i < N; ++i) {
            int x;
            std::cin >> x;
            xs[x < 0].push_back(std::abs(x));
        }
        int64_t ans = 0;
        for (int b : {0, 1}) {
            xs[b].push_back(0);
            std::sort(xs[b].rbegin(), xs[b].rend());
            for (int i = 0; i < xs[b].size(); i += K) {
                ans += 2 * xs[b][i];
            }
        }
        ans -= std::max(xs[0][0], xs[1][0]);
        std::cout << ans << '\n';
    }
    exit(0);
}