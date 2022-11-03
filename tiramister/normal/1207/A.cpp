#include <iostream>

void solve() {
    int b, x1, x2, y1, y2;
    std::cin >> b >> x1 >> x2 >> y1 >> y2;
    b /= 2;

    if (y1 < y2) {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }

    int ans = 0;
    ans += y1 * std::min(x1, b);
    b -= std::min(x1, b);
    ans += y2 * std::min(x2, b);

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