#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>

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

const int MAXN = 300300 * 4;
ll n, a[MAXN];

struct segtree {

	struct node {
		ll mn, mx;
		node operator + (const node &tmp) const {
			return node{min(mn, tmp.mn), max(mx, tmp.mx)};
		}
	} t[MAXN];
	ll tag[MAXN], inv[MAXN];

	void cov1 (int x, ll k) { t[x].mn += k, t[x].mx += k; tag[x] += k; }
	void cov2 (int x) { swap(t[x].mn, t[x].mx); t[x].mn *= -1, t[x].mx *= -1; inv[x] ^= 1, tag[x] *= -1; }
	void pushdown (int x) {
		if (inv[x]) { cov2(x << 1), cov2(x << 1 | 1), inv[x] = 0; }
		if (tag[x]) {
			cov1(x << 1, tag[x]), cov1(x << 1 | 1, tag[x]);
			tag[x] = 0;
		}
	}
	void modify (int l, int r, ll k, int L, int R, int x) {
		if (l > r) return;
		if (l <= L && R <= r) { cov1(x, k); return; }
		int mid = (L + R) >> 1; pushdown(x);
		if (l <= mid) modify(l, r, k, L, mid, x << 1); 
		if (mid <r) modify(l,r , k, mid + 1, R, x << 1 | 1);
		t[x] = t[x << 1] + t[x << 1 | 1];
	}
	int query (int l, int r, int x) {
		if (t[x].mx < 0) return r + 1;
		if (t[x].mn >= 0) return l - 1;
		pushdown(x); int mid = (l + r) >> 1;
		if (t[x << 1 | 1].mn >= 0) {
			return query(l, mid, x << 1);
		}
		else return query(mid + 1, r, x << 1 | 1);
	}
	void clear (int l, int r, int x) {
		tag[x] = 0, inv[x] = 0; t[x].mn = t[x].mx = 0;
		if (l == r) return;
		int mid = (l + r) >> 1; clear(l, mid, x << 1), clear(mid + 1, r, x << 1 | 1);
	}
} seg[2];

map <ll, int> vis; int top;
vector <int> presum[MAXN];

int main () {
	int T = read();
	while (T--) {
		n = read(); int i, j;
		for (i = 1; i <= n; i++) a[i] = read();
		ll ans = 0, now = 0; vis[0] = ++top, presum[1].push_back(0);
		for (i = 1; i <= n; i++) {
			// seg[i & 1].cov2(1); 
            if (i & 1) {
                seg[0].modify(1, (i + 1) >> 1, a[i], 1, n, 1);
                seg[1].modify(1, i >> 1, -a[i], 1, n, 1);
            }
            else {
                seg[0].modify(1, i >> 1, -a[i], 1, n, 1);
                seg[1].modify(1, i >> 1, a[i], 1, n, 1);
            }
            // printf("? %d %d\n", seg[0].query(1, n, 1), seg[1].query(1, n, 1));
			int lim = max((seg[0].query(1, n, 1) - 1) * 2, (seg[1].query(1, n, 1) - 1) * 2 - 1);
			if (i & 1) now += a[i]; else now -= a[i];
			int tmp = vis[now] ? vis[now] : (vis[now] = ++top);
			ans += presum[tmp].end() - lower_bound(presum[tmp].begin(), presum[tmp].end(), lim);
			presum[tmp].push_back(i);
			// cout << lim << endl;
		}
		printf("%lld\n", ans);
		seg[0].clear(1, n, 1), seg[1].clear(1, n, 1);
		for (i = 1; i <= top; i++) presum[i].clear();
		vis.clear(); top = 0;
	}
	return 0;
}