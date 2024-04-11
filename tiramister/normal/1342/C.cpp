#include <iostream>
#include <vector>

using lint = long long;

void solve() {
    lint a, b;
    std::cin >> a >> b;

    int g = a * b;
    std::vector<lint> cnt(g, 0);
    for (int x = 1; x < g; ++x) {
        cnt[x] = cnt[x - 1];
        if ((x % a) % b != (x % b) % a) ++cnt[x];
    }
    lint m = cnt.back();

    auto calc = [&](lint x) -> lint {
        return m * (x / g) + cnt[x % g];
    };

    int q;
    std::cin >> q;
    while (q--) {
        lint l, r;
        std::cin >> l >> r;
        std::cout << calc(r) - calc(l - 1) << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}