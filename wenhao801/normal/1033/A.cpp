#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

int n, ax, ay, bx, by, cx, cy;
bool vis[1010][1010];

int to[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
bool dfs (int x, int y) {
	if (x == cx && y == cy) return 1;
	vis[x][y] = 1;
	for (int i = 0; i < 8; i++) {
		int tx = x + to[i][0], ty = y + to[i][1];
		if (!vis[tx][ty] && tx >= 1 && tx <= n && ty >= 1 && ty <= n) { if (dfs(tx, ty)) return 1; }
	}
	return 0;
}

int main () {
	n = read(); int i, j;
	ax = read(), ay = read(), bx = read(), by=  read(), cx = read(), cy = read();
	for (i = 1; i <= n; i++) vis[ax][i] = vis[i][ay] = 1;
	for (i = -n; i <= n; i++) if (ax + i >= 1 && ax + i <= n && ay + i >= 1 && ay + i <= n) vis[ax + i][ay + i] = 1;
	for (i = -n; i <= n; i++) if (ax + i >= 1 && ax + i <= n && ay - i >= 1 && ay - i <= n) vis[ax + i][ay - i] = 1;
	puts(dfs(bx, by) ? "YES" : "NO");
	return 0;
}