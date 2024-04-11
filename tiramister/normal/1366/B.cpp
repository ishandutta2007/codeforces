#include <iostream>

void solve() {
    int n, x, m;
    std::cin >> n >> x >> m;

    int l = x, r = x;
    while (m--) {
        int c, d;
        std::cin >> c >> d;
        if (d < l || r < c) continue;

        l = std::min(l, c);
        r = std::max(r, d);
    }

    std::cout << r - l + 1 << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}