#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int cost[] = {1, 0, 1, 0};

std::vector<std::pair<int, int>> q[2];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> dist(n, std::vector<int>(m, (int) 1e9));
	std::vector<std::string> mat(n);
	int sx, sy;
	std::cin >> sx >> sy;
	sx--;sy--;
	q[0].push_back({sx, sy});
	dist[sx][sy] = 0;
	int x, y;
	std::cin >> x >> y;
	for(int i = 0; i < n; i++) {
		std::cin >> mat[i];
	}
	int ans = 0;
	for(int i = 0; i < n * m; i++) {
		while(!q[i%2].empty()) {
			int curX = q[i%2].back().first, curY = q[i%2].back().second;
			q[i%2].pop_back();
			if(dist[curX][curY] < i) continue;
			// left + right = dist
			// left - right = sy - curY
			// left = (dist + curY - sy) / 2
			// right = dist - left
			int left = (i + sy - curY) / 2;
			int right = (i - left);
			//std::cout << "visiting (" << curX << ", " << curY << ") with dist " << i << ", left is " << left << ", right is " << right << "\n";
			if(left > x || right > y) {
				//std::cout << "bad\n";
				dist[curX][curY] = -1;
				continue;
			}
			ans++;
			for(int k = 0; k < 4; k++) {
				int toDist = i + cost[k];
				int toX = curX + dx[k], toY = curY + dy[k];
				if(toX < 0 || toY < 0 || toX >= n || toY >= m) {
					continue;
				}
				if(mat[toX][toY] == '*') continue;
				if(dist[toX][toY] > toDist) {
					dist[toX][toY] = toDist;
					q[toDist%2].push_back({toX, toY});
				}
			}
		}
	}
	std::cout << ans << "\n";
}