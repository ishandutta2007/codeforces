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

const int MAXN = 100100;
int n, a[MAXN], ans[MAXN];
bool dfs (int x) {
	if (ans[x] != -1) return ans[x];
	bool fail = 1;
	for (int i = x - a[x]; i >= 1; i -= a[x]) if (a[i] > a[x]) fail &= dfs(i);
	for (int i = x + a[x]; i <= n; i += a[x]) if (a[i] > a[x]) fail &= dfs(i);
	return ans[x] = !fail;
}

int main () {
	n = read(); int i, j;
	for (i = 1; i <= n; i++) a[i] = read(), ans[i] = -1;
	for (i = 1; i <= n; i++) {
		putchar(dfs(i) ? 'A' : 'B');
	}
	return 0;
}