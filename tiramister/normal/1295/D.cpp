#include <iostream>
#include <algorithm>
#include <vector>

template <class T>
T gcd(T n, T m) {
    while (m != 0) {
        n %= m;
        std::swap(n, m);
    }
    return n;
}

using lint = long long;

void solve() {
    lint a, m;
    std::cin >> a >> m;
    m /= gcd(a, m);

    lint ans = m;
    for (lint p = 2; p * p <= m; ++p) {
        if (m % p != 0) continue;
        ans = ans / p * (p - 1);
        while (m % p == 0) m /= p;
    }
    if (m > 1) {
        ans = ans / m * (m - 1);
    }

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