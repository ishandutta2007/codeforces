#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>

const int ms = 2020;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const char dir[] = {'<', '^', '>', 'v'};

char mat[ms][ms];
int deg[ms][ms];

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		scanf(" %s", mat[i]);
	}
	std::queue<std::pair<int, int>> q; 
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(mat[i][j] != '.') {
				deg[i][j] = 193832;
			} else {
				for(int k = 0; k < 4; k++) {
					int x = i + dx[k], y = j + dy[k];
					if(x < 0 || x >= n || y < 0 || y >= m) {
						continue;
					}
					if(mat[x][y] == '.') {
						deg[i][j]++;
					}
				}
			}
			if(deg[i][j] == 1) {
				q.push(std::pair<int, int>(i, j));
			}
		}
	}
	while(!q.empty()) {
		int i = q.front().first, j = q.front().second;
		q.pop();
		if(mat[i][j] == '.') {
			int x, y;
			for(int k = 0; k < 4; k++) {
				x = i + dx[k], y = j + dy[k];
				if(x < 0 || x >= n || y < 0 || y >= m) {
					continue;
				}
				if(mat[x][y] == '.') {
					mat[i][j] = dir[k];
					mat[x][y] = dir[k^2];
					if(deg[x][y] > 1) {
						deg[x][y] = 0;
						q.push(std::pair<int, int>(x, y));
					}
					break;
				}
			}
		}
		for(int k = 0; k < 4; k++) {
			int x = i + dx[k], y = j + dy[k];
			if(x < 0 || x >= n || y < 0 || y >= m) {
				continue;
			}
			deg[x][y]--;
			if(deg[x][y] == 1) {
				q.push(std::pair<int, int>(x, y));
			}
		}
	}
	bool ans = true;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			ans = ans && mat[i][j] != '.';
		}
	}
	if(!ans) {
		std::cout << "Not unique\n";
	} else {
		for(int i = 0; i < n; i++) {
			printf("%s\n", mat[i]);
		}
	}
}