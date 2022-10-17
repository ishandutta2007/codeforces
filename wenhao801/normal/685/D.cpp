#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}

#define pii pair <int, int>
#define fr first
#define se second
using ll = long long;
const int MAXN = 200200;

int n, K, bx[MAXN], xt, by[MAXN], yt;
pii a[MAXN];

struct event { int l, r, k; }; vector <event> E[MAXN];
ll ans[MAXN], val[MAXN];

int main () {
	n = read(), K = read(); int i, j;
	for (i = 1; i <= n; i++) {
		a[i].fr = read(), a[i].se = read();
		bx[++xt] = a[i].fr + 1, bx[++xt] = a[i].fr - K + 1;
		by[++yt] = a[i].se + 1, by[++yt] = a[i].se - K + 1;
	}
	sort(bx + 1, bx + xt + 1); xt = unique(bx + 1, bx + xt + 1) - bx - 1;
	sort(by + 1, by + yt + 1); yt = unique(by + 1, by + yt + 1) - by - 1;
	for (i = 1; i <= n; i++) {
		int l = lower_bound(by + 1, by + yt + 1, a[i].se - K + 1) - by;
		int r = lower_bound(by + 1, by + yt + 1, a[i].se + 1) - by - 1;
		int lx = lower_bound(bx + 1, bx + xt + 1, a[i].fr - K + 1) - bx;
		int rx = lower_bound(bx + 1, bx + xt + 1, a[i].fr + 1) - bx;
		E[lx].push_back({l, r, 1}); E[rx].push_back({l, r, -1});
	}
	for (i = 1; i <= xt; i++) {
		for (auto e: E[i]) {
			for (j = e.l; j <= e.r; j++) {
				ans[val[j]] += 1ll * bx[i] * (by[j + 1] - by[j]);
				val[j] += e.k;
				ans[val[j]] -= 1ll * bx[i] * (by[j + 1] - by[j]);
			}
		}
	}
	for (i = 1; i <= n; i++) printf("%lld ", ans[i]);
	putchar('\n');
	return 0;
}