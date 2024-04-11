#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <cassert>

using ldouble = long double;
constexpr ldouble EPS = 1e-20;

void solve() {
    int n;
    ldouble tt;
    std::cin >> n >> tt;

    std::vector<ldouble> xs(n), ts(n);
    for (auto& x : xs) std::cin >> x;
    for (auto& t : ts) {
        std::cin >> t;
        t -= tt;
    }

    ldouble sum = 0;
    for (int i = 0; i < n; ++i) sum += ts[i] * xs[i];

    std::vector<int> idxs(n);
    std::iota(idxs.begin(), idxs.end(), 0);
    std::sort(idxs.begin(), idxs.end(),
              [&](int i, int j) { return ts[i] < ts[j]; });

    if (sum > 0) std::reverse(idxs.begin(), idxs.end());

    for (auto i : idxs) {
        if (std::abs(ts[i]) < EPS) continue;
        ldouble need = std::min(sum / ts[i], xs[i]);
        xs[i] -= need;
        sum -= need * ts[i];
    }

    ldouble ans = std::accumulate(xs.begin(), xs.end(), 0.L);
    std::cout << std::fixed << std::setprecision(20) << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}