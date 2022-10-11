#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <cstring>
#include <cstdio>

const int ms = 1010;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int dist[ms][ms];
char str[ms][ms];

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	memset(dist, 0x3f, sizeof dist);
	int n, m;
	std::cin >> n >> m;
	std::pair<int, int> st;
	for(int i = 0; i < n; i++) {
		scanf(" %s", str[i]);
		for(int j = 0; j < m; j++) {
			if(str[i][j] == 'E') {
				st = std::pair<int, int>(i, j);
			}
		}
	}
	std::queue<std::pair<int, int>> q;
	q.push(st);
	dist[st.first][st.second] = 0;
	while(!q.empty()) {
		st = q.front();
		q.pop();
		//std::cout << "on " << st.first << ", " << st.second << ", dist is " << dist[st.first][st.second] << std::endl;
		for(int k = 0; k < 4; k++) {
			int x = st.first + dx[k], y = st.second + dy[k];
			if(x >= 0 && x < n && y >= 0 && y < m && str[x][y] != 'T' && dist[x][y] == 0x3f3f3f3f) {
				dist[x][y] = dist[st.first][st.second] + 1;
				q.push({x, y});
			}
		}
	}
	int cmp = -1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(str[i][j] == 'S') {
				cmp = dist[i][j];
			}
		}
	}
	//std::cout << "cmp is " << cmp << std::endl;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(str[i][j] >= '0' && str[i][j] <= '9' && dist[i][j] <= cmp) {
				ans += str[i][j] - '0';
			}
		}
	}
	std::cout << ans << std::endl;
}