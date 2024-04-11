#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> dist(n, std::vector<int>(m, -1));
	std::vector<std::string> mat(n);
	std::queue<std::pair<int, int>> q;
	for(int i = 0; i < n; i++) {
		std::cin >> mat[i];
		for(int j = 0; j < m; j++) {
			if(mat[i][j] == '.') {
				dist[i][j] = 0;
				q.push({i, j});
			}
		}
	}
	for(int i = 0; i < n; i++) {
		if(dist[i][0] == -1) {
			dist[i][0] = 1;
			q.push({i, 0});
		}
		if(dist[i][m-1] == -1) {
			dist[i][m-1] = 1;
			q.push({i, m-1});
		}
	}
	for(int i = 0; i < m; i++) {
		if(dist[0][i] == -1) {
			dist[0][i] = 1;
			q.push({0, i});
		}
		if(dist[n-1][i] == -1) {
			dist[n-1][i] = 1;
			q.push({n-1, i});
		}
	}
	int l = 1, r = 1;
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int dx = -1; dx <= 1; dx++) {
			for(int dy = -1; dy <= 1; dy++) {
				int toX = x + dx, toY = y + dy;
				if(toX < 0 || toY < 0 || toX >= n || toY >= m) {
					continue;
				}
				if(dist[toX][toY] == -1) {
					dist[toX][toY] = 1 + dist[x][y];
					q.push({toX, toY});
				}
			}
		}
		r = dist[x][y];
	}
	auto check = [&](int d) {
		std::vector<std::vector<int>> dst(n, std::vector<int>(m, -1));
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(dist[i][j] >= d) {
					dst[i][j] = 0;
					q.push({i, j});
				}
			}
		}
		while(!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if(dst[x][y] + 1 == d) continue;
			for(int dx = -1; dx <= 1; dx++) {
				for(int dy = -1; dy <= 1; dy++) {
					int toX = x + dx, toY = y + dy;
					if(toX < 0 || toY < 0 || toX >= n || toY >= m) {
						continue;
					}
					if(dst[toX][toY] == -1) {
						dst[toX][toY] = 1 + dst[x][y];
						q.push({toX, toY});
					}
				}
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if((dst[i][j] != -1 ? 'X' : '.') != mat[i][j]) {
					return false;
				}
			}
		}
		return true;
	};
	while(l != r) {
		int mid = (l + r + 1) / 2;
		if(check(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	std::cout << l - 1 << '\n';
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			std::cout << (dist[i][j] >= l ? 'X' : '.');
		}
		std::cout << '\n';
	}
}