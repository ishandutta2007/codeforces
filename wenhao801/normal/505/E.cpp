#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
#define int long long
#define ll long long
inline int read () {
	int ret = 0, t = 1; char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 100100;
int n, m, k, p;
int h[MAXN], a[MAXN], cnt[MAXN];

ll ceil (ll x, ll y) { return x / y + (x % y ? 1 : 0); }
struct qwq {
	ll und, id;
	bool operator < (const qwq &x) const { return x.und < und; }
};
priority_queue <qwq> q;

bool check (ll x) {
	int i, j;
	while (!q.empty()) q.pop();
	for (i = 1; i <= n; i++) cnt[i] = 0;
	for (i = 1; i <= n; i++) if (x - m * a[i] < h[i]) q.push({x / a[i], i});
	for (i = 1; i <= m; i++) for (j = 1; j <= k; j++) {
		if (!q.empty()) {
			qwq f = q.top(); q.pop();
			if (f.und < i) return false;
			++cnt[f.id];
			if (x + cnt[f.id] * p - m * a[f.id] < h[f.id])
				q.push({(x + cnt[f.id] * p) / a[f.id], f.id});
		}
	}
	return q.empty();
}

signed main () {
	n = read(), m = read(), k = read(), p = read();
	int i, j;
	ll L = 0, R = 1e18, ans;
	for (i = 1; i <= n; i++) h[i] = read(), a[i] = read(), L = max(L, (ll)(a[i]));
	
	while (L <= R) {
		ll mid = (L + R) >> 1;
		if (check(mid)) ans = mid, R = mid - 1;
		else L = mid + 1;
	}
	printf("%lld\n", ans);
	return 0;
}