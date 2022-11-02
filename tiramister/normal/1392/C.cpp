#include <iostream>

using lint = long long;

void solve() {
    int n;
    std::cin >> n;

    lint p;
    std::cin >> p;
    --n;

    lint ans = 0;
    while (n--) {
        lint x;
        std::cin >> x;
        ans += std::max(0LL, p - x);
        p = x;
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