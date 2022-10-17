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

int n, x;
int a[100100] = {};
signed main () {
	int T = read();
	while (T--) {
		n = read(), x = read();
		int i, j;
		int ans = 1e9 + 7;
		for (i = 1; i <= n; i++) {
			j = read();
			if (j >= x) {
				if (j == x) ans = min(ans, 1ll);
				else ans = min(ans, 2ll);
			}
			else {
				if (x % j == 0) ans = min(ans, x / j);
				else ans = min(ans, x / j + 1);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}