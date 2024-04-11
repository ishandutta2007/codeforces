#include <bits/stdc++.h>
const int dx[4] = {+1, -1, +0, -0};
const int dy[4] = {+0, -0, +1, -1};
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int N, M;
        std::cin >> N >> M;
        std::vector<std::string> g(N);
        std::queue<std::pair<int, int>> q;
        std::vector vis(N, std::vector<bool>(M));
        for (int i = 0; i < N; ++i) {
            std::cin >> g[i];
            for (int j = 0; j < M; ++j) {
                if (g[i][j] == 'L') {
                    vis[i][j] = true;
                    q.emplace(i, j);
                }
            }
        }
        auto valid = [&](int i, int j) {
            return 0 <= std::min(i, j) && i < N && j < M;
        };
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int t = 0; t < 4; ++t) {
                int nx = x + dx[t], ny = y + dy[t];
                if (!valid(nx, ny) || g[nx][ny] == '#' || vis[nx][ny]) continue;
                int deg = 0;
                for (int s = 0; s < 4; ++s) {
                    int nnx = nx + dx[s], nny = ny + dy[s];
                    if (valid(nnx, nny) && g[nnx][nny] == '.') {
                        ++deg;
                    }
                }
                if (deg <= 1) {
                    vis[nx][ny] = true;
                    g[nx][ny] = '+';
                    q.emplace(nx, ny);
                }
            }
        }
        for (int i = 0; i < N; ++i) {
            std::cout << g[i] << '\n';
        }
    }
    exit(0);
}