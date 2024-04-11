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

const int MAXN = 2020;
int n, x[MAXN], y[MAXN];
void solve () {
	int i, j, f1 = 0, f2 = 0;
	for (i = 1; i <= n; i++) {
		if ((x[i] + y[i]) & 1) f1 = f2 = 1;
		else if ((x[i] & 1) && (y[i] & 1)) f2 = 1;
	}
	if (!f1 && !f2) {
		for (i = 1; i <= n; i++) x[i] >>= 1, y[i] >>= 1;
		solve(); return;
	}
	if (f1) {
		int cnt = 0;
		for (i = 1; i <= n; i++) if ((x[i] + y[i]) & 1) ++cnt;
		printf("%d\n", cnt);
		for (i = 1; i <= n; i++) if ((x[i] + y[i]) & 1) printf("%d ", i);
		return;
	}
	int cnt = 0;
	for (i = 1; i <= n; i++) if ((x[i] & 1) && (y[i] & 1)) ++cnt;
	printf("%d\n", cnt);
	for (i = 1; i <= n; i++) if ((x[i] & 1) && (y[i] & 1)) printf("%d ", i);
}

int main () {
	n = read(); int i, j;
	x[1] = read(); y[1] = read();
	for (i = 2; i <= n; i++) x[i] = read() - x[1], y[i] = read() - y[1];
	x[1] = y[1] = 0;
	solve();
	return 0;
}