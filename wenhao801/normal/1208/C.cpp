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

const int MAXN = 1010;
int a[MAXN * MAXN], ans[MAXN][MAXN];

bool cmp (int x, int y) {
	if ((x & 3) != (y & 3))  return (x & 3) < (y & 3);
	return x < y;
}

int main () {
	int n = read(), i, j;
	for (i = 1; i <= n * n; i++) a[i] = i - 1;
	sort(a + 1, a +n  * n + 1, cmp);
	int hn = n >> 1, now = 0;
	for (i = 1; i <= hn; i++) for (j = 1; j <= hn; j++) ans[i][j] = a[++now];
	for (i = 1; i <= hn; i++) for (j = hn + 1; j <= n; j++) ans[i][j] = a[++now];
	for (i = hn + 1; i <= n; i++) for (j = 1; j <= hn; j++) ans[i][j] = a[++now];
	for (i = hn + 1; i <= n; i++) for (j = hn + 1; j <= n; j++) ans[i][j] = a[++now];
	for (i = 1; i <= n; i++) { for (j = 1; j <= n; j++) cout << ans[i][j] <<' '; cout << endl; }
	return 0;
}