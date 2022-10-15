#include <bits/stdc++.h>
std::pair<std::vector<int>, std::vector<int>> sieve(int N) {
    std::vector<int> lp(N + 1), pr;
    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0) {
            pr.push_back(lp[i] = i);
        }
        for (auto p : pr) {
            if (p > lp[i] || i * p > N) break;
            lp[i * p] = p;
        }
    }
    return {lp, pr};
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    auto lp = sieve(1e6).first;
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int N, E;
        std::cin >> N >> E;
        std::vector<bool> dead(N);
        std::vector<std::vector<int>> occ(E);
        for (int e = 0; e < E; ++e) {
            occ[e].push_back(e - E);
        }
        for (int i = 0; i < N; ++i) {
            int a;
            std::cin >> a;
            if (a == 1) continue;
            occ[i % E].push_back(i);
            if (lp[a] != a) {
                dead[i] = true;
            }
        }
        int64_t ans = 0;
        for (int e = 0; e < E; ++e) {
            occ[(N + e) % E].push_back(N + e);
        }
        for (int e = 0; e < E; ++e) {
            for (int j = 1; j + 1 < occ[e].size(); ++j) {
                int l = occ[e][j - 1], m = occ[e][j], r = occ[e][j + 1];
                if (dead[m]) continue;
                ans += 1LL * (m - l) / E * (r - m) / E - 1;
            }
        }
        std::cout << ans << '\n';
    }
    exit(0);
}