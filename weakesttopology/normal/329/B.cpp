#include <bits/stdc++.h>
const int dx[] = {+1, -1, +0, -0};
const int dy[] = {+0, -0, +1, -1};
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int R, C;
    std::cin >> R >> C;
    std::vector<std::string> g(R);
    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<int>> d(R, std::vector<int>(C, -1));
    int sr, sc;
    for (int r = 0; r < R; ++r) {
        std::cin >> g[r];
        for (int c = 0; c < C; ++c) {
            if (g[r][c] == 'E') {
                q.emplace(r, c);
                d[r][c] = 0;
            } else if (g[r][c] == 'S') {
                sr = r;
                sc = c;
            }
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int t = 0; t < 4; ++t) {
            int nx = x + dx[t], ny = y + dy[t];
            if (std::min(nx, ny) < 0 || nx == R || ny == C || g[nx][ny] == 'T' || d[nx][ny] != -1) continue;
            d[nx][ny] = d[x][y] + 1;
            q.emplace(nx, ny);
        }
    }
    int cost = 0;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (d[r][c] != -1 && d[r][c] <= d[sr][sc] && std::isdigit(g[r][c])) {
                cost += g[r][c] - '0';
            }
        }
    }
    std::cout << cost << '\n';
    exit(0);
}