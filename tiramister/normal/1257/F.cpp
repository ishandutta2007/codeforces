#include <iostream>
#include <vector>
#include <map>
#include <tuple>

// enumerate all difference sequences
std::map<std::vector<int>, int> calc(const std::vector<int>& xs) {
    int n = xs.size();
    std::map<std::vector<int>, int> ret;

    for (int b = 0; b < (1 << 15); ++b) {
        auto ys = xs;
        for (auto& y : ys) y = __builtin_popcount(y ^ b);

        std::vector<int> diff;
        for (int i = 0; i + 1 < n; ++i) {
            diff.push_back(ys[i + 1] - ys[i]);
        }
        ret[diff] = b;
    }
    return ret;
}

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n), ys(n);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;

        // separate
        xs[i] = x >> 15;
        ys[i] = x - (xs[i] << 15);
    }

    auto xmap = calc(xs),
         ymap = calc(ys);

    for (auto p : xmap) {
        int x;
        std::vector<int> diff;
        std::tie(diff, x) = p;

        for (auto& d : diff) d = -d;

        if (ymap.count(diff)) {
            int y = ymap[diff];
            std::cout << (x << 15) + y << std::endl;
            return;
        }
    }

    std::cout << -1 << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}