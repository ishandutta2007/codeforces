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

int n, a[11]; bool f = 0;
void dfs (int x, int s, bool has) {
	if (x > n) { f |= !s && has; return; }
	dfs(x + 1, s + a[x], 1); dfs(x + 1, s - a[x], 1); dfs(x + 1, s, has);
}

int main () {
	int T = read();
	while (T--) {
		n = read(); int i, j;
		for (i = 1; i <= n; i++) a[i] = read();
		f = 0; dfs(1, 0, 0); puts(f ? "YES" : "NO");
	}
	return 0;
}