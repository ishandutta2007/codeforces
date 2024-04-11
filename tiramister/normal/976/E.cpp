#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using lint = long long;

void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;
    lint mul = 1LL << a;

    std::vector<lint> hs(n), ds(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> hs[i] >> ds[i];
    }
    lint dsum = std::accumulate(ds.begin(), ds.end(), 0LL);

    if (b == 0) {
        std::cout << dsum << std::endl;
        return;
    }

    std::vector<int> idx(n);
    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(),
              [&](int i, int j) { return hs[i] - ds[i] > hs[j] - ds[j]; });

    std::vector<lint> gs(n);
    lint glast = 0, gsum = 0;
    for (int i = 0; i < n; ++i) {
        int j = idx[i];
        if (i < b) {
            lint g = std::max(hs[j] - ds[j], 0LL);
            gsum += g;
            glast = g;
            gs[j] = g;
        } else {
            gs[j] = glast;
        }
    }

    lint ans = dsum;
    for (int i = 0; i < n; ++i) {
        lint g = std::max(hs[i] * mul - ds[i], 0LL);
        ans = std::max(ans, dsum + gsum + g - gs[i]);
    }

    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}