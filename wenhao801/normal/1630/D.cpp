#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}

#define ll long long
#define size(v) (int(v.size()))
const int MAXN = 1001000;

int n, m, a[MAXN];
queue <int> q;

int main () {
	int T = read();
	while (T--) {
		n = read(), m = read(); int i, j;
		for (i = 1; i <= n; i++) a[i] = read();
		int cur = 0;
		for (i = 1; i <= m; i++) {
			j = read();
			cur = (!cur) ? j : __gcd(cur, j);
		}
		// for (i = 1; i <= n; i++) {
		// 	if (size(q) & 1) a[i] *= -1;
		// 	if (i <= n - cur + 1 && a[i] < 0) a[i] *= -1, q.push(i + cur - 1);
		// 	if (!q.empty() && q.front() < i) q.pop();
		// }
		ll ans = 0, u = 0, v = 0;
		for (i = 0; i < cur; i++) {
			int mn = 1e9 + 7; bool f = 0;
			for (j = n - i; j >= 1; j -= cur) mn = min(mn, abs(a[j])), ans += abs(a[j]), f ^= a[j] < 0;
			if (f) u += mn; else v += mn;
		}
		printf("%lld\n", ans - 2ll * min(u, v));
	}
	return 0;
}