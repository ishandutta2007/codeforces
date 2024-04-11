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

const int MAXN = 200200;
int ch[MAXN * 33][2], siz[MAXN * 33], f[MAXN * 33], top = 1, n;
void dfs (int x) {
	if (!ch[x][0] && !ch[x][1]) return;
	if (!ch[x][0]) { dfs(ch[x][1]), f[x] = f[ch[x][1]]; return; }
	if (!ch[x][1]) { dfs(ch[x][0]), f[x] = f[ch[x][0]]; return; }
	dfs(ch[x][0]), dfs(ch[x][1]);
	f[x] = min(f[ch[x][0]] + siz[ch[x][1]] - 1, f[ch[x][1]] + siz[ch[x][0]] - 1);
}

int main () {
	n = read(); int i, j;
	for (i = 1; i <= n; i++) {
		int x = read(), now = 1; ++siz[now];
		for (j = 30; j >= 0; j--) {
			int to = (x >> j) & 1;
			if (!ch[now][to]) ch[now][to] = ++top;
			now = ch[now][to]; ++siz[now];
		}
	}
	dfs(1); printf("%d\n", f[1]);
	return 0;
}