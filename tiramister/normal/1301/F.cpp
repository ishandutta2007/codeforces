#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <tuple>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

const std::vector<int> dx{-1, 0, 1, 0}, dy{0, -1, 0, 1};

int dists[40][1000][1000];

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    auto grid = vec(n, vec(m, 0));
    for (auto& v : grid) {
        for (auto& x : v) {
            std::cin >> x;
            --x;
        }
    }

    std::vector<std::vector<std::pair<int, int>>> cells(k);
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            cells[grid[x][y]].emplace_back(x, y);
        }
    }

    for (int c = 0; c < k; ++c) {
        auto& dist = dists[c];
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m; ++y) {
                dist[x][y] = -1;
            }
        }

        std::vector<bool> visited(k, false);
        std::queue<std::pair<int, int>> que;
        for (auto p : cells[c]) {
            int x, y;
            std::tie(x, y) = p;
            dist[x][y] = 0;
            que.emplace(x, y);
        }

        while (!que.empty()) {
            int x, y;
            std::tie(x, y) = que.front();
            que.pop();

            int nc = grid[x][y];
            if (!visited[nc]) {
                visited[nc] = true;
                for (auto p : cells[nc]) {
                    int nx, ny;
                    std::tie(nx, ny) = p;
                    if (dist[nx][ny] != -1) continue;
                    dist[nx][ny] = dist[x][y] + 1;
                    que.emplace(nx, ny);
                }
            }

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d],
                    ny = y + dy[d];
                if (nx < 0 || n <= nx || ny < 0 || m <= ny ||
                    dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[x][y] + 1;
                que.emplace(nx, ny);
            }
        }
    }

    int q;
    std::cin >> q;
    while (q--) {
        int sx, sy, gx, gy;
        std::cin >> sx >> sy >> gx >> gy;
        --sx, --sy, --gx, --gy;

        int ans = std::abs(sx - gx) + std::abs(sy - gy);
        for (int c = 0; c < k; ++c) {
            int d = dists[c][sx][sy] + dists[c][gx][gy] + 1;
            ans = std::min(ans, d);
        }
        std::cout << ans << "\n";
    }
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}