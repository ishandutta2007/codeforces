#include <iostream>
#include <vector>

const std::vector<int> sz{1, 2};

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> pos(2);
    for (int i = 1; i <= n; ++i) {
        int x;
        std::cin >> x;
        pos[x & 1].push_back(i);
    }

    for (int i = 0; i < 2; ++i) {
        if ((int)pos[i].size() >= sz[i]) {
            std::cout << sz[i] << std::endl;

            for (int j = 0; j < sz[i]; ++j) {
                std::cout << pos[i][j] << " ";
            }
            std::cout << std::endl;

            return;
        }
    }

    std::cout << -1 << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}