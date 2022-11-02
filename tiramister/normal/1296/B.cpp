#include <iostream>

using lint = long long;

void solve() {
    lint n;
    std::cin >> n;

    lint ans = 0;
    while (n >= 10) {
        lint pay = n / 10 * 10;
        ans += pay;
        n -= pay;
        n += pay / 10;
    }
    ans += n;
    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}