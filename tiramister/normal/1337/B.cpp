#include <iostream>

void solve() {
    int x, n, m;
    std::cin >> x >> n >> m;

    while (n--) {
        if (x <= m * 10) {
            std::cout << "YES\n";
            return;
        }

        x = x / 2 + 10;
    }

    std::cout << (x <= m * 10 ? "YES" : "NO") << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}