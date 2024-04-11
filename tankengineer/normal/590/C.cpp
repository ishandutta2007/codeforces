#include<deque>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1005;

int n, m;

char map[N][N];

int dis[3][N][N];

const int dx[4] = {-1, 0, 1, 0},
		  dy[4] = {0, -1, 0, 1};

const int INF = 1000000000;

int g[3][3];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", map[i]);
	}
	for (int c = 0; c < 3; ++c) {
		deque<pair<int, int> > q;
		memset(dis[c], -1, sizeof(dis[c]));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (map[i][j] == '1' + c) {
					dis[c][i][j] = 0;
					q.push_back(make_pair(i, j));
				}
			}
		}
		while (q.size()) {
			int x = q.front().first, y = q.front().second;
			//cout << c << ' ' << x << ' ' << y << ' ' << dis[c][x][y] << endl;
			q.pop_front();
			for (int d = 0; d < 4; ++d) {
				int tx = x + dx[d], ty = y + dy[d];
				if (tx >= 0 && tx < n && ty >= 0 && ty < m && map[tx][ty] != '#' && dis[c][tx][ty] == -1) {
					dis[c][tx][ty] = dis[c][x][y] + (map[tx][ty] == '.');
					if (dis[c][tx][ty] == dis[c][x][y]) {
						q.push_front(make_pair(tx, ty));
					} else {
						q.push_back(make_pair(tx, ty));
					}
				}
			}
		}
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			g[i][j] = INF;
			for (int x = 0; x < n; ++x) {
				for (int y = 0; y < m; ++y) {
					if (map[x][y] == j + '1' && dis[i][x][y] != -1) {
						g[i][j] = min(g[i][j], dis[i][x][y]);
					}
				}
			}
			if (g[i][j] == INF) {
				printf("-1\n");
				return 0;
			}
		}
	}
	int ans = min(g[0][1] + g[0][2], min(g[1][0] + g[1][2], g[0][2] + g[2][1]));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (map[i][j] == '.') {
				int sum = 1;
				for (int c = 0; c < 3; ++c) {
					if (dis[c][i][j] != -1) {
						sum += dis[c][i][j] - 1;
					} else {
						sum = INF;
						break;
					}
				}
				/*
				cout << i << ' ' << j << ' ' << sum << endl;
				cout << ' ' << dis[0][i][j] << ' ' << dis[1][i][j] << ' ' << dis[2][i][j] << endl;
				*/
				ans = min(ans, sum);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}