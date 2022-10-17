#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
#define int long long
inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}
const int MAXN = 200200;
int n;
int a[MAXN];
int p[MAXN], q[MAXN], tp, tq;
int dpp[MAXN], dpq[MAXN];

signed main () {
	int T = read();
	while (T--) {
		n = read(); tp = tq = 0;
		int i, j, sum = 0;
		for (i = 0; i < n; i++) { a[i] = read(); if (i % 2 == 0) sum += a[i]; }
		for (i = 0; i < n; i++) {
			if (i % 2 == 0 && i != n - 1) p[++tp] = a[i + 1] - a[i];
			if (i % 2 == 1 && i != n - 1) q[++tq] = a[i] - a[i + 1];
		}
		for (i = 1; i <= tp; i++)
			dpp[i] = max(p[i], p[i] + dpp[i - 1]);
		for (i = 1; i <= tq; i++)
			dpq[i] = max(q[i], q[i] + dpq[i - 1]);
		int res = 0;
		for (i = 1; i <= tp; i++) res = max(res, dpp[i]);
		for (i = 1; i <= tq; i++) res = max(res, dpq[i]);
		printf("%lld\n", sum + res);
	}
	return 0;
}