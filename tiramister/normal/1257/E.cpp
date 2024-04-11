#include <iostream>
#include <numeric>
#include <vector>

void solve() {
    std::vector<int> ks(3);
    for (auto& k : ks) std::cin >> k;
    int n = std::accumulate(ks.begin(), ks.end(), 0);

    std::vector<std::vector<int>> psum(3, std::vector<int>(n + 1, 0));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < ks[i]; ++j) {
            int x;
            std::cin >> x;
            ++psum[i][x];
        }
    }
    for (auto& v : psum) {
        for (int i = 1; i <= n; ++i) {
            v[i] += v[i - 1];
        }
    }

    int ans = n, minl = n;
    for (int r = 0; r <= n; ++r) {
        minl = std::min(minl, psum[1][r] - psum[0][r]);
        ans = std::min(ans, psum[2][r] - psum[1][r] + minl);
    }
    std::cout << ans + ks[0] + ks[1] << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}