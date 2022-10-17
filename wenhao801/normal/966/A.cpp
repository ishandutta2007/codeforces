#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
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

const int MAXN = 200200, inf = 1e9;
int n, m, cl, ce, v, L[MAXN], E[MAXN];

signed main () {
	n = read(), m = read(), cl = read(), ce = read(), v = read(); int i, j;
	for (i = 1; i <= cl; i++) L[i] = read(); L[0] = -inf, L[cl + 1] = inf;
	for (i = 1; i <= ce; i++) E[i] = read(); E[0] = -inf, E[ce + 1] = inf;
	int q = read();
	while (q--) {
		int x1 = read(), y1 = read(), x2 = read(), y2 = read();
		swap(x1, y1), swap(x2, y2);
		if (x1 > x2) swap(x1, x2); if (y1 > y2) swap(y1, y2);
		if (y1 == y2) { printf("%lld\n", x2 - x1); continue; }
		ll tmp = lower_bound(L, L + cl + 1, x1) - L, ans = 1e18;
		if (L[tmp] <= x2) ans = min(ans, x2 - x1 + y2 - y1);
		else {
			if (tmp) { int x3 = L[tmp - 1]; ans = min(ans, x1 - x3 + x2 - x3 + y2 - y1); }
			ans = min(ans, L[tmp] - x1 + L[tmp] - x2 + y2 - y1);
		}
		
		int tim = (y2 - y1) / v + ((y2 - y1) % v == 0 ? 0 : 1);
		tmp = lower_bound(E, E + ce + 1, x1) - E;
		if (E[tmp] <= x2) ans = min(ans, x2 - x1 + tim);
		else {
			if (tmp) { int x3 = E[tmp - 1]; ans = min(ans, x1 - x3 + x2 - x3 + tim); }
			ans = min(ans, E[tmp] - x1 + E[tmp] - x2 + tim);
		}
		printf("%lld\n", ans);
	}
	return 0;
}