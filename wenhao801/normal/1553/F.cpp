#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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

#define ll long long
const int MAXN = 300300, B = 1500, lim = 3e5;
int n, a[MAXN]; int buc[B + 5][B + 5], buc2[B + 5];

struct BIT {
	ll t[MAXN];
	inline int lowbit (int x) { return x & -x; }
	inline ll sum (int x) { ll ret = 0; while (x) ret += t[x], x -= lowbit(x); return ret; }
	inline ll query (int l, int r) { return sum(r) - (l ? sum(l - 1) : 0); }
	inline void add (int x, int k) { while (x <= lim) t[x] += k, x += lowbit(x); }
} noval, val;	

int main () {
	n = read(); int i, j;
	for (i = 1; i <= n; i++) a[i] = read();
	ll ans = 0;
	for (i = 1; i <= n; i++) {
		ans += 1ll * (i - 1) * a[i];
		
		for (j = 1; j <= B; j++) ans -= j * buc2[j] * (a[i] / j);
		for (int L = B + 1, R; L <= a[i]; L = R + 1) {
			int tmp = a[i] / L;
			R = a[i] / tmp; R = min(R, a[i]);
			ans -= 1ll * tmp * val.query(L, R);
		}

		if (a[i] <= B) {
			for (j = 0; j < a[i]; j++) ans += 1ll * j * buc[a[i]][j];
		}
		else {
			for (int L = 0, R = a[i] - 1; L <= lim; L += a[i], R += a[i]) {
				R = min(R, lim);
				ans += val.query(L, R) - 1ll * L * noval.query(L, R);
			}
		}
		cout << ans << ' ';
		noval.add(a[i], 1); val.add(a[i], a[i]);
		for (j = 1; j <= B; j++) ++buc[j][a[i] % j];
		if (a[i] <= B) ++buc2[a[i]];
	}
	return 0;
}