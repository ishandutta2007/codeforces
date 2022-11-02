#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2005;
int n, m;
char map[N][N]; 
int dgr[N][N], dis[N][N][2];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", map[i]);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (map[i][j] == '<') {
				++dgr[i][j - 1];
			} else if (map[i][j] == '>') {
				++dgr[i][j + 1];
			} else if (map[i][j] == '^') {
				++dgr[i - 1][j];
			} else if (map[i][j] == 'v') {
				++dgr[i + 1][j];
			}
		}
	}
	memset(dis, -1, sizeof(dis));
	queue<pair<int, int> > q;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (dgr[i][j] == 0) {
				q.push(make_pair(i, j));
				dis[i][j][0] = 0;
			}
		}
	}
	while (q.size()) {
		int i = q.front().first, j = q.front().second, x, y;
		q.pop();
		if (map[i][j] == '<') {
			x = i, y = j - 1;
		} else if (map[i][j] == '>') {
			x = i, y = j + 1;
		} else if (map[i][j] == '^') {
			x = i - 1, y = j;
		} else if (map[i][j] == 'v') {
			x = i + 1, y = j;
		} else {
			continue;
		}
		--dgr[x][y];
		if (dgr[x][y] == 0) {
			q.push(make_pair(x, y));
		}
		if (map[x][y] == '#') {
			if (dis[i][j][0] + 1 > dis[x][y][0]) {
				dis[x][y][1] = dis[x][y][0];
				dis[x][y][0] = dis[i][j][0] + 1;
			} else if (dis[i][j][0] + 1 > dis[x][y][1]) {
				dis[x][y][1] = dis[i][j][0] + 1;
			}
			if (dis[i][j][1] + 1 > dis[x][y][1]) {
				dis[x][y][1] = dis[i][j][1] + 1;
			}
		} else {
			if (dis[i][j][0] + 1 > dis[x][y][0]) {
				dis[x][y][1] = dis[x][y][0];
				dis[x][y][0] = dis[i][j][0] + 1;
			} else if (dis[i][j][0] + 1 < dis[x][y][0] && dis[i][j][0] + 1 > dis[x][y][1]) {
				dis[x][y][1] = dis[i][j][0] + 1;
			}
			if (dis[i][j][1] + 1 < dis[x][y][0] && dis[i][j][1] + 1 > dis[x][y][1]) {
				dis[x][y][1] = dis[i][j][1] + 1;
			}
		}
	}
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (dis[i][j][0] > ans1) {
				ans2 = ans1;
				ans1 = dis[i][j][0];
			} else if (dis[i][j][0] > ans2) {
				ans2 = dis[i][j][0];
			}
			if (dis[i][j][1] > ans2) {
				ans2 = dis[i][j][1];
			}
		}
	}
	int ans = ans1 + ans2;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (dgr[i][j]) {
				ans = -1;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}