#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 1001000;
int n; vector <int> E[MAXN];
int mx[MAXN], lson[MAXN];

void dfs1 (int x, int f) {
	mx[x] = 1;
	for (auto i: E[x]) {
		if (i == f) continue;
		dfs1(i, x);
		if (mx[i] + 1 > mx[x]) mx[x] = mx[i] + 1, lson[x] = i;
	}
}
int pos[MAXN], dp[MAXN], ans[MAXN], now;
void dfs2 (int x, int f) {
	dp[pos[x]] = 1;
	if (lson[x]) {
		pos[lson[x]] = pos[x] + 1;
		dfs2(lson[x], x);
		ans[x] = ans[lson[x]] + 1;
		for (auto i: E[x]) {
			if (i == f || i == lson[x]) continue;
			pos[i] = now; now += mx[i];
			dfs2(i, x);
			for (int j = 1; j <= mx[i]; j++) {
				dp[pos[x] + j] += dp[pos[i] + j - 1];
				if (dp[pos[x] + ans[x]] < dp[pos[x] + j] || (dp[pos[x] + ans[x]] == dp[pos[x] + j] && j < ans[x])) ans[x] = j;
			}
		}
	}
	if (dp[pos[x] + ans[x]] == 1) ans[x] = 0;
}

int main () {
	n = read();
	int i, j;
	for (i = 1; i < n; i++) {
		int u = read(), v = read();
		E[u].push_back(v), E[v].push_back(u);
	}
	dfs1(1, 0);
	pos[1] = 0; now += mx[1];
	dfs2(1, 0);
	for (i = 1; i <= n; i++) printf("%d\n", ans[i]);
	return 0;
}