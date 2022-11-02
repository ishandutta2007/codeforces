#include <iostream>
#include <algorithm>
#include <vector>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

void solve() {
    int n;
    std::cin >> n;

    auto costs = vec(4, vec(2, 0));

    for (int i = 0; i < 4; ++i) {
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                char c;
                std::cin >> c;

                int b = c - '0';
                ++costs[i][(x + y) % 2 == b];
            }
        }
    }

    int ans = 0;
    std::vector<int> ds(4);
    for (int i = 0; i < 4; ++i) {
        ans += costs[i][0];
        ds[i] = costs[i][1] - costs[i][0];
    }

    std::sort(ds.begin(), ds.end());
    ans += ds[0] + ds[1];

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}