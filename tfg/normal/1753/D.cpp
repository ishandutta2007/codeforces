#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

using li = std::pair<long long, int>;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    long long p, q;
    std::cin >> p >> q;
    std::vector<std::string> mat(n);
    for(int i = 0; i < n; i++) {
        std::cin >> mat[i];
    }
    std::vector<std::vector<int>> groups(n, std::vector<int>(m, 0));
    std::vector<int> gX(1), gY(1);
    const long long INF = 1e18;
    std::vector<std::vector<long long>> dist(n, std::vector<long long>(m, INF));
    std::priority_queue<li, std::vector<li>, std::greater<li>> hp;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
        if(mat[i][j] == 'L') {
            groups[i][j] = groups[i][j+1] = (int) gX.size();
            gX.push_back(i ^ i), gY.push_back(j ^ (j+1));
        } else if(mat[i][j] == 'U') {
            groups[i][j] = groups[i+1][j] = (int) gX.size();
            gX.push_back(i ^ (i+1)), gY.push_back(j ^ j);
        } else if(mat[i][j] == '*') {
            groups[i][j] = -1;
        } else if(mat[i][j] == '.') {
            dist[i][j] = 0;
            hp.push({0, i * m + j});
        }
    }
    long long ans = INF;
    while(!hp.empty()) {
        auto [curDist, curId] = hp.top();
        hp.pop();
        int curX = curId / m, curY = curId % m;
        if(dist[curX][curY] != curDist) {
            continue;
        }
        const int dx[4] = {1, 0, -1, 0};
        const int dy[4] = {0, 1, 0, -1};
        for(int dir = 0; dir < 4; dir++) {
            int toX = dx[dir] + curX, toY = dy[dir] + curY;
            if(0 > toX || toX >= n || 0 > toY || toY >= m || groups[toX][toY] == -1) continue;
            ans = std::min(ans, curDist + dist[toX][toY]);
            if(groups[toX][toY] >= 1) {
                int g = groups[toX][toY];
                int x = toX ^ gX[g];
                int y = toY ^ gY[g];
                long long toDist = curDist + (x == curX || y == curY ? q : p);
                if(toDist < dist[x][y]) {
                    dist[x][y] = toDist;
                    hp.push({toDist, x * m + y});
                }
            }
        }
    }
    if(ans == INF) {
        ans = -1;
    }
    std::cout << ans << '\n';
}