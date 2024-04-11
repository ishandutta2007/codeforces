#include <iostream>

void solve() {
    int n;
    std::cin >> n;

    char prev;
    int d = 0;
    for (int i = 0; i < n; ++i) {
        char c;
        std::cin >> c;

        if (i != 0 && c == prev) ++d;
        prev = c;
    }

    std::cout << (d + 1) / 2 << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}