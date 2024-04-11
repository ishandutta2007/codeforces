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

const int MAXN = 400400;

int a[300300] = {};
int b[MAXN], c[MAXN];
int x[MAXN], y[MAXN];

int main () {
	int T = read();
	while (T--) {
		int n = read();
		int i, j;

		for (i = 1; i <= n; i++) a[i] = b[i] = c[i] = read();
		for (i = 1; i <= n; i++) b[i] -= i - 1;
		for (i = n; i >= 1; i--) c[i] -= n - i;
		x[0] = y[n + 1] = 1e9 + 1;
		for (i = 1; i <= n; i++) x[i] = min(x[i - 1], b[i]);
		for (i = n; i >= 1; i--) y[i] = min(y[i + 1], c[i]);
		bool f = false;
		for (i = 1; i <= n; i++) if (x[i] >= 0 && y[i] >= 0) {f = true; break;}
		if (f) puts("Yes"); else puts("No");
	}
	return 0;
}