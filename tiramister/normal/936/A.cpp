#include <iostream>

using lint = long long;

void solve() {
    lint k, d, t;
    std::cin >> k >> d >> t;
    d = (k + d - 1) / d * d;

    lint term = k * 2 + (d - k);
    t *= 2;

    bool rem = false;
    lint ans = t / term * d;
    t %= term;

    if (t <= k * 2) {
        ans += t / 2;
        rem = t % 2;
    } else {
        t -= k * 2;
        ans += k + t;
    }

    std::cout << ans << (rem ? ".5" : ".0") << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}