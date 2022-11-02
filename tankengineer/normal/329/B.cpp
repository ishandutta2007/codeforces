#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
const int INF = 200000000;

int n, m, dis[1005][1005], qhead, qtail, q[1005 * 1005][2];
char map[1005][1005];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", map[i] + 1);
	}
	int tx, ty;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (map[i][j] == 'E') {
				tx = i;
				ty = j;
				dis[i][j] = 0;
			} else {
				dis[i][j] = INF;
			}
		}
	}
	qhead = 0; qtail = 1; q[qtail][0] = tx; q[qtail][1] = ty;
	while (qhead < qtail) {
		++qhead;
		int nx = q[qhead][0], ny = q[qhead][1];
		for (int d = 0; d < 4; ++d) {
			tx = nx + dx[d];
			ty = ny + dy[d];
			if (tx > 0 && tx <= n && ty > 0 && ty <= m && map[tx][ty] != 'T' && dis[tx][ty] > dis[nx][ny] + 1) {
				dis[tx][ty] = dis[nx][ny] + 1;
				++qtail;
				q[qtail][0] = tx;
				q[qtail][1] = ty;
			}
		}
	}
	int ans = 0, bar = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (map[i][j] == 'S') {
				bar = dis[i][j];
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (map[i][j] > '0' && map[i][j] <= '9' && dis[i][j] <= bar) {
				ans += map[i][j] - '0';
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}