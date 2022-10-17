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
int a[200200], b[200200];
signed main () {
	int n = read(), m = read();
	int i, j;
	for (i = 1; i <= n; i++) a[i] = read();
	for (i = 1; i <= m; i++) b[i] = read();
	sort(a + 1, a + n + 1);
	int res = 0;
	for (i = 2; i <= n; i++) res = __gcd(res, a[i] - a[i - 1]);
	for (i = 1; i <= m; i++) printf("%lld ",__gcd(res, a[1] + b[i]));
	return 0;
}