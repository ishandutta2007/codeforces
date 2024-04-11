#include <iostream>
#include <vector>
#include <string>

using lint = long long;

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

void solve() {
    int h, w;
    std::cin >> h >> w;

    auto sums = vec(h + 2, vec(w + 2, 0));
    auto grid = vec(h + 2, vec(w + 2, 0));
    for (int x = 1; x <= h; ++x) {
        for (int y = 1; y <= w; ++y) {
            char c;
            std::cin >> c;
            grid[x][y] = (c == 'X');
            sums[x][y] = grid[x][y] +
                         sums[x - 1][y] + sums[x][y - 1] -
                         sums[x - 1][y - 1];
        }
    }

    int ok = 0, ng = h;
    while (ng - ok > 1) {
        int mid = (ok + ng) / 2;
        int l = mid * 2 + 1;

        auto ngrid = vec(h + 2, vec(w + 2, 0));
        for (int x = 1; x <= h; ++x) {
            if (x < l) continue;
            for (int y = 1; y <= w; ++y) {
                if (y < l) continue;

                lint lx = x - l, ly = y - l;
                lint sum = sums[x][y] -
                           sums[x][ly] - sums[lx][y] +
                           sums[lx][ly];

                if (sum == (x - lx) * (y - ly)) {
                    ++ngrid[x][y];
                    --ngrid[lx][y];
                    --ngrid[x][ly];
                    ++ngrid[lx][ly];
                }
            }
        }

        for (int x = h; x >= 0; --x) {
            for (int y = w; y >= 0; --y) {
                ngrid[x][y] += ngrid[x + 1][y] + ngrid[x][y + 1] -
                               ngrid[x + 1][y + 1];
            }
        }

        for (auto& v : ngrid) {
            for (auto& x : v) {
                x = (x > 0);
            }
        }

        if (grid == ngrid) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    std::cout << ok << std::endl;
    int l = ok * 2 + 1;
    auto ngrid = vec(h + 1, vec(w + 1, 0LL));
    for (int x = 1; x <= h; ++x) {
        if (x < l) continue;
        for (int y = 1; y <= w; ++y) {
            if (y < l) continue;

            lint lx = x - l, ly = y - l;
            lint sum = sums[x][y] -
                       sums[x][ly] - sums[lx][y] +
                       sums[lx][ly];

            if (sum == (x - lx) * (y - ly)) {
                ++ngrid[x - ok][y - ok];
            }
        }
    }

    for (int x = 1; x <= h; ++x) {
        for (int y = 1; y <= w; ++y) {
            std::cout << (ngrid[x][y] ? "X" : ".");
        }
        std::cout << "\n";
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}