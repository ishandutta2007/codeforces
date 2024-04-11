#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define int long long

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

int n, p, k;
struct per { int a; int s[8]; } a[100100];

int dp[100100][129];
bool cmp (per x, per y) { return x.a > y.a; }
int cnt (int x) { int ret = 0; while (x) ret += x & 1, x >>= 1; return ret; }
void out (int x, int y) { printf("(%d, ", x); for (int i = 1, j = y; i <= p; i++) cout << j % 2, j >>= 1; puts(")"); printf(": %lld\n", dp[x][y]); }
signed main () {
	n = read(), p = read(), k = read();
	int i, j, l;
	for (i = 1; i <= n; i++) a[i].a = read();
	for (i = 1; i <= n; i++) for (j = 1; j <= p; j++) a[i].s[j] = read();
	sort(a + 1, a + n + 1, cmp);
	for (j = 1; j < (1 << p); j++) dp[0][j] = -17936579348678037ll;
	for (i = 1; i <= n; i++) {
		for (j = 0; j < (1 << p); j++) {
			dp[i][j] = dp[i - 1][j];
			//out(i, j);
			if (i - cnt(j) <= k) dp[i][j] += a[i].a;
			for (l = 0; l < p; l++) if ((j >> l) & 1) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - (1 << l)] + a[i].s[l + 1]);
			}
			//out(i, j);
		}
	}
	printf("%lld\n", dp[n][(1 << p) - 1]);
	return 0;
}