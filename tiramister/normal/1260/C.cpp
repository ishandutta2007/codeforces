#include <iostream>
#include <algorithm>

template <class T>
T gcd(T n, T m) {
    while (m != 0) {
        n %= m;
        std::swap(n, m);
    }
    return n;
}

void solve() {
    int r, b, k;
    std::cin >> r >> b >> k;

    if (r == b) {
        std::cout << "OBEY" << std::endl;
        return;
    }

    if (r > b) std::swap(r, b);
    int c = (b + r - gcd(r, b) - 1) / r;
    std::cout << (c >= k ? "REBEL" : "OBEY") << std::endl;
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