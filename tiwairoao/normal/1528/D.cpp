#include <bits/stdc++.h>

const int N = 600;
const int INF = (1 << 30);

int read() {
	int x = 0, ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while ('0' <= ch && ch <= '9') x = 10 * x + ch - '0', ch = getchar();
	return x;
}
void write(int x) {
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

int f[N + 5][N + 5], n;

int dis[N + 5]; bool vis[N + 5];
void solve(int *ans) {
	for (int i = 0; i < n; i++) vis[i] = false;
	for (int tmes = 1; tmes <= n; tmes++) {
		int x = -1;
		for (int i = 0; i < n; i++) if (!vis[i])
			if (x == -1 || ans[i] < ans[x]) x = i;		
		vis[x] = true;

		for (int i = 0, p = ans[x] % n; i < n; i++, p = (p + 1 == n ? 0 : p + 1))
			dis[p] = f[x][i];
		for (int i = 1; i < n; i++) dis[i] = std::min(dis[i], dis[i - 1] + 1);
		dis[0] = std::min(dis[0], dis[n - 1] + 1);
		for (int i = 1; i < n; i++) dis[i] = std::min(dis[i], dis[i - 1] + 1);
		
		for (int i = 0; i < n; i++) if (!vis[i])
			ans[i] = std::min(ans[i], ans[x] + dis[i]);
	}
}

int ans[N + 5][N + 5];
int main() {
	n = read(); int m = read();
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
		ans[i][j] = f[i][j] = INF;
	for (int i = 1, a, b, c; i <= m; i++)
		a = read(), b = read(), c = read(), f[a][b] = c;
	for (int i = 0; i < n; i++) {
		ans[i][i] = 0, solve(ans[i]);
		for (int j = 0; j < n; j++)
			write(ans[i][j]), putchar(j == n - 1 ? '\n' : ' ');
	}
}