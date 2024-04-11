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
#define ll long long
const int MAXN = 5050;
int n, x[MAXN], y[MAXN];
bool vis[MAXN]; ll dis[MAXN][MAXN];

int main () {
	n = read(); int i, j;
	for (i = 1; i <= n; i++) x[i] = read(), y[i] = read();
	for (i = 1; i <= n; i++) {
		for (j = i + 1; j <= n; j++) {
			dis[i][j] = dis[j][i] = 1ll * (x[i] - x[j]) * (x[i] - x[j]) + 1ll * (y[i] - y[j]) * (y[i] - y[j]);
		}
	}
	int now = 1; putchar('1'); vis[1] = 1;
	for (i = 1; i < n; i++) {
		int mx = now;
		for (j = 1; j <= n; j++) if (!vis[j] && dis[now][j] > dis[now][mx]) mx = j;
		printf(" %d", mx); now = mx; vis[mx] = 1;
	}
	return 0;
}