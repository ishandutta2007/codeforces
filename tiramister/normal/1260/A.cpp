#include <iostream>

void solve() {
    int c, s;
    std::cin >> c >> s;

    int b = s / c;
    s %= c;
    std::cout << b * b * (c - s) + (b + 1) * (b + 1) * s << std::endl;
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