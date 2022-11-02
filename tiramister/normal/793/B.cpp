#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <tuple>

const std::vector<std::pair<int, int>> dxys{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
constexpr int INF = 1 << 30;

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

void solve() {
    int h, w;
    std::cin >> h >> w;

    std::vector<std::string> grid(h);
    for (auto& s : grid) std::cin >> s;

    int sx, sy, gx, gy;
    for (int x = 0; x < h; ++x) {
        for (int y = 0; y < w; ++y) {
            if (grid[x][y] == 'S') {
                sx = x, sy = y;
            }
            if (grid[x][y] == 'T') {
                gx = x, gy = y;
            }
        }
    }

    auto dist = vec(h, vec(w, vec(4, INF)));
    std::fill(dist[sx][sy].begin(), dist[sx][sy].end(), 0);
    std::deque<std::tuple<int, int, int, int>> que;
    for (int i = 0; i < 4; ++i) {
        que.emplace_back(sx, sy, i, dist[sx][sy][i]);
    }

    while (!que.empty()) {
        auto [x, y, i, d] = que.front();
        que.pop_front();
        if (dist[x][y][i] < d) continue;

        for (int j = 0; j < 4; ++j) {
            if (dist[x][y][j] <= d + 1) continue;
            dist[x][y][j] = d + 1;
            que.emplace_back(x, y, j, dist[x][y][j]);
        }

        auto [dx, dy] = dxys[i];
        int nx = x + dx,
            ny = y + dy;

        if (nx < 0 || h <= nx ||
            ny < 0 || w <= ny ||
            grid[nx][ny] == '*' ||
            dist[nx][ny][i] <= d) continue;

        dist[nx][ny][i] = d;
        que.emplace_front(nx, ny, i, dist[nx][ny][i]);
    }

    int d = *std::min_element(dist[gx][gy].begin(), dist[gx][gy].end());
    std::cout << (d <= 2 ? "YES" : "NO") << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}