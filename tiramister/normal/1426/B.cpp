#include <iostream>
#include <vector>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

void solve() {
    int n, m;
    std::cin >> n >> m;

    auto grids = vec(n, vec(2, vec(2, 0)));
    for (auto& grid : grids) {
        for (auto& v : grid) {
            for (auto& x : v) {
                std::cin >> x;
            }
        }
    }

    if (m % 2 != 0) {
        std::cout << "NO\n";
        return;
    }

    for (auto& grid : grids) {
        if (grid[0][1] == grid[1][0]) {
            std::cout << "YES\n";
            return;
        }
    }

    std::cout << "NO\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}