#include <iostream>
#include <vector>

using lint = long long;

void solve() {
    int n;
    std::cin >> n;

    lint a;
    std::cin >> a;
    --n;

    lint ans = 0;
    while (n--) {
        lint x;
        std::cin >> x;
        if (x * a > 0) {
            a = std::max(a, x);
        } else {
            ans += a;
            a = x;
        }
    }
    ans += a;

    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}