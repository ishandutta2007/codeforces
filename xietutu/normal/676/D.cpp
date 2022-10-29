#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <queue>
using namespace std;
const int maxn = 1005;
const int xy[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
const int anti[4] = {2, 3, 0, 1};
char s[maxn];
struct arr {
	int x, y, op;
	arr(int x = 0, int y = 0, int op = 0):x(x), y(y), op(op) {}
} st;
queue<arr> Q;
bool visit[maxn][maxn][4];
int n, m, ex, ey, dis[maxn][maxn][4];
inline void update(int x, int y, int op, int v) {
	if (dis[x][y][op] == -1) {
		dis[x][y][op] = v;
		Q.push(arr(x, y, op));
	}
}
inline void on(int x, int y, int op) {
	visit[x][y][op] = true;
}
inline void unon(int x, int y, int op) {
	for (int i = 0; i < 4; ++i)
		if (i != op) visit[x][y][i] = true;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s + 1);
		for (int j = 1; j <= m; ++j) {
			if (s[j] == '+') on(i, j, 0), on(i, j, 1), on(i, j, 2), on(i, j, 3);
			if (s[j] == '-') on(i, j, 1), on(i, j, 3);
			if (s[j] == '|') on(i, j, 0), on(i, j, 2);
			if (s[j] == '^') on(i, j, 0);
			if (s[j] == '>') on(i, j, 3);
			if (s[j] == '<') on(i, j, 1);
			if (s[j] == 'v') on(i, j, 2);
			if (s[j] == 'L') unon(i, j, 1);
			if (s[j] == 'R') unon(i, j, 3);
			if (s[j] == 'U') unon(i, j, 0);
			if (s[j] == 'D') unon(i, j, 2);
		}
	}
	scanf("%d%d", &st.x, &st.y);
	scanf("%d%d", &ex, &ey);
	Q.push(st);
	memset(dis, 255, sizeof(dis));
	dis[st.x][st.y][0] = 0;
	while (Q.size()) {
		arr now = Q.front(); Q.pop();
		int step = dis[now.x][now.y][now.op];
		update(now.x, now.y, (now.op + 1) % 4, step + 1);
		for (int i = 0; i < 4; ++i) 
			if (visit[now.x][now.y][(i + now.op) % 4]) {
				int x = now.x + xy[i][0], y = now.y + xy[i][1];
				if (x >= 1 && y >= 1 && x <= n && y <= m &&
					visit[x][y][(anti[i] + now.op) % 4]) {
					update(x, y, now.op, step + 1);
					}
			}
	}
	int ans = n * m * 10;
	for (int i = 0; i < 4; ++i)
		if (dis[ex][ey][i] != -1)
			ans = min(ans, dis[ex][ey][i]);
	if (ans == n * m * 10)	printf("-1\n");
	else printf("%d\n", ans);
}