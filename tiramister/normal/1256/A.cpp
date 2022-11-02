#include <iostream>

void solve() {
    int a, b, n, s;
    std::cin >> a >> b >> n >> s;

    int g = std::min(s / n, a);
    s -= g * n;
    std::cout << (0 <= s && s <= b ? "YES" : "NO")
              << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}