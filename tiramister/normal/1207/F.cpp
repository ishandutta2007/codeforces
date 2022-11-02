#include <iostream>
#include <vector>

constexpr int N = 500000;
constexpr int M = 700;

void solve() {
    std::vector<int> xs(N, 0);
    std::vector<std::vector<int>> small(M + 1);
    for (int i = 0; i <= M; ++i) {
        small[i].resize(i, 0);
    }

    int q;
    std::cin >> q;
    while (q--) {
        int t, x, y;
        std::cin >> t >> x >> y;

        if (t == 1) {
            --x;
            xs[x] += y;

            for (int i = 1; i <= M; ++i) {
                small[i][x % i] += y;
            }
        } else {
            if (--y < 0) y += x;
            if (x <= M) {
                std::cout << small[x][y] << "\n";
            } else {
                int ans = 0;
                while (y < N) {
                    ans += xs[y];
                    y += x;
                }
                std::cout << ans << "\n";
            }
        }
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}