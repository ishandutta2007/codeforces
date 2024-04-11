#pragma GCC optimize("Ofast")
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

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
const int MAXN = 262145;

int n, a[MAXN], fa[MAXN];
int v[MAXN];
int gf (int x) { if (fa[x] == x) return x; return fa[x] = gf(fa[x]); }

int main () {
	n = read(); int i, j;
	++v[0];
	ll ans = 0;
	for (i = 1; i <= n; i++) a[i] = read(), ++v[a[i]], ans -= a[i];
	for (i = 0; i <= 262144; i++) fa[i] = i;
	for (i = 262144; i >= 1; i--) {
		for (j = i; 1; j = i & (j - 1)) {
			int x = j, y = i ^ j;
			if (v[x] && v[y] && gf(x) != gf(y)) fa[gf(x)] = gf(y), ans += 1ll * i * (v[x] + v[y] - 1), v[x] = v[y] = 1;
			if (!j) break;
		}
	}
	printf("%lld\n", ans);
	return 0;
}