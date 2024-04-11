#include <iostream>

void solve() {
    int n, m;
    std::cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << (i == 0 && j == 0 ? 'W' : 'B');
        }
        std::cout << std::endl;
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}