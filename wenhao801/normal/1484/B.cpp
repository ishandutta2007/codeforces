#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define int long long
inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}

long long a[100100];

signed main () {
	int T = read();
	while (T--) {
		int n = read(),  i, j;
		for ( i = 1; i <= n; i++) a[i] = read();
		if (n == 1 || n == 2) { puts("0"); continue; }
		for (i = 3; i <= n; i++) if (a[i] - a[i - 1] != a[2] - a[1]) break;
		if (i > n) { puts("0"); continue; }
		int d = -1, mod = -1;
		for (i = 2; i <= n; i++) if (d == -1 && a[i] > a[i - 1]) { d = a[i] - a[i - 1]; break; }
		if (d == -1) { puts("-1"); continue; }
		for (i = 2; i <= n; i++) if (a[i] < a[i - 1] && mod == -1) { mod = d + a[i - 1] - a[i]; break; }
		if (mod <= d)  { puts("-1"); continue; }
		for (i = 1; i <= n; i++) if (a[i] >= mod) { break; }
		if (i <= n) { puts("-1"); continue; }
		for (i = 2; i <= n; i++) if (a[i] != (a[i - 1] + d) % mod) break;
		if (i > n) printf("%lld %lld\n", mod, d); else puts("-1");
	}
	return 0;
}