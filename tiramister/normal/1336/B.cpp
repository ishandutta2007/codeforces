#include <iostream>
#include <algorithm>
#include <vector>

template <class T>
T sq(T x) { return x * x; }

using lint = long long;
constexpr lint INF = 1LL << 62;

void solve() {
    std::vector<std::vector<lint>> xss(3);
    for (auto& xs : xss) {
        int n;
        std::cin >> n;
        xs.resize(n);
    }

    for (auto& xs : xss) {
        for (auto& x : xs) {
            std::cin >> x;
        }
        std::sort(xs.begin(), xs.end());
    }

    lint ans = INF;
    for (int q = 0; q < 6; ++q) {
        for (auto x : xss[0]) {
            auto lit = std::upper_bound(xss[1].begin(), xss[1].end(), x);
            if (lit == xss[1].begin()) continue;
            lint y = *(--lit);

            auto rit = std::lower_bound(xss[2].begin(), xss[2].end(), x);
            if (rit == xss[2].end()) continue;
            lint z = *rit;

            ans = std::min(ans, sq(x - y) + sq(y - z) + sq(z - x));
        }
        std::next_permutation(xss.begin(), xss.end());
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}