#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
typedef __int128_t ll;
typedef pair<ll, ll> pll;
template<typename T1, typename T2> void chkmax(T1 &x, T2 y) {if (x < y) x = y;}
template<typename T1, typename T2> void chkmin(T1 &x, T2 y) {if (x > y) x = y;}
const int MAXN = 1e5;
const ll INF = 1e18;
int n, a[MAXN + 5]; ll k;
int ord[MAXN + 5], min_ord[MAXN + 5], rk[MAXN + 5];
ll sum[MAXN + 5], premin[MAXN + 5], sum_sorted[MAXN + 5];
void init() {
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i], sum_sorted[i] = sum[i];
    for (int i = 0; i <= n; i++) ord[i] = i;
    sort(ord, ord + n + 1, [&](int x, int y) {return mp(sum[x], x) < mp(sum[y], y);});
	for (int i = 0; i <= n; i++) rk[ord[i]] = i;
    for (int i = 1; i <= n; i++) premin[i] = min(premin[i - 1], sum[i]);
	sort(sum_sorted, sum_sorted + n + 1);
	min_ord[0] = ord[0];
	for (int i = 1; i <= n; i++) min_ord[i] = min(min_ord[i - 1], ord[i]);
}
pll operator + (pll X, pll Y) {return mp(X.fi + Y.fi, X.se + Y.se);}
struct fenwick {
	ll t[MAXN + 15];
	void clear() {memset(t, 0, sizeof(t));}
	fenwick() {clear();}
	void add(int x, ll v) {x += 5; for (int i = x; i <= n + 10; i += (i & (-i))) t[i] += v;}
	ll query(int x) {x += 5; ll ret = 0; for (int i = x; i; i &= (i - 1)) ret += t[i]; return ret;}
} T1, T2;
struct segtree {
	struct node {int l, r; pll mx_dp, mx_dp_sub_mn, lz;} s[MAXN * 4 + 5];
	void pushup(int k) {
		s[k].mx_dp = max(s[k << 1].mx_dp, s[k << 1 | 1].mx_dp);
		s[k].mx_dp_sub_mn = max(s[k << 1].mx_dp_sub_mn, s[k << 1 | 1].mx_dp_sub_mn);
	}
	void build(int k, int l, int r) {
		s[k].l = l; s[k].r = r; s[k].mx_dp = s[k].mx_dp_sub_mn = mp(-INF, 0); s[k].lz = mp(0, 0);
		if (l == r) return; int mid = l + r >> 1; build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
	}
	void tag(int k, pll v) {s[k].lz = s[k].lz + v; s[k].mx_dp = s[k].mx_dp + v; s[k].mx_dp_sub_mn = s[k].mx_dp_sub_mn + v;}
	void pushdown(int k) {if (s[k].lz.fi || s[k].lz.se) tag(k << 1, s[k].lz), tag(k << 1 | 1, s[k].lz), s[k].lz = mp(0, 0);}
	void upd(int k, int p, pll v) {
		if (s[k].l == s[k].r) {
			s[k].mx_dp = s[k].mx_dp_sub_mn = v;
			if (p) s[k].mx_dp_sub_mn.fi -= premin[p - 1];
			return;
		}
		pushdown(k);
		int mid = s[k].l + s[k].r >> 1;
		if (p <= mid) upd(k << 1, p, v); else upd(k << 1 | 1, p, v);
		pushup(k);
	}
	void add(int k, int l, int r, pll v) {
		if (l > r) return; if (l <= s[k].l && s[k].r <= r) return tag(k, v), void();
		pushdown(k); int mid = s[k].l + s[k].r >> 1;
		if (r <= mid) add(k << 1, l, r, v);
		else if (l > mid) add(k << 1 | 1, l, r, v);
		else add(k << 1, l, mid, v), add(k << 1 | 1, mid + 1, r, v);
		pushup(k);
	}
	pll query_dp(int k, int l, int r) {
		if (l > r) return mp(-INF, 0);
		if (l <= s[k].l && s[k].r <= r) return s[k].mx_dp;
		pushdown(k); int mid = s[k].l + s[k].r >> 1;
		if (r <= mid) return query_dp(k << 1, l, r);
		else if (l > mid) return query_dp(k << 1 | 1, l, r);
		else return max(query_dp(k << 1, l, mid), query_dp(k << 1 | 1, mid + 1, r));
	}
	pll query_dp_sub(int k, int l, int r) {
		if (l > r) return mp(-INF, 0);
		if (l <= s[k].l && s[k].r <= r) return s[k].mx_dp_sub_mn;
		pushdown(k); int mid = s[k].l + s[k].r >> 1;
		if (r <= mid) return query_dp_sub(k << 1, l, r);
		else if (l > mid) return query_dp_sub(k << 1 | 1, l, r);
		else return max(query_dp_sub(k << 1, l, mid), query_dp_sub(k << 1 | 1, mid + 1, r));
	}
} T;
pll calc(ll K) {
	T1.clear(); T2.clear(); T.build(1, 0, n); pll dp = mp(0, 0); T.upd(1, 0, dp);
	for (int i = 1; i <= n; i++) {
		T1.add(rk[i - 1], 1); T2.add(rk[i - 1], sum[i - 1]);
		int pos = upper_bound(sum_sorted, sum_sorted + n + 1, sum[i] - K) - sum_sorted - 1;
		ll c = T1.query(pos), s = T2.query(pos); s = c * (sum[i] - K) - s;
		dp = dp + mp(s, c); T.add(1, 0, n, mp(s, c));
		int lim = (!c) ? i : min_ord[pos]; if (lim == 0 && sum[i] >= K) --lim;
		pll tmp = T.query_dp(1, lim + 1, i); chkmax(dp, tmp);
		if (!c) T.upd(1, i, dp), dp = mp(-INF, 0);
		tmp = T.query_dp_sub(1, 0, lim); tmp = tmp + mp(sum[i] - K, 1);
		chkmax(dp, tmp);
	}
	return dp;
}
int main() {
	scanf("%d%lld", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	init();
	ll L = -5e9, R = 5e9, p = 0;
	while (L <= R) {
		ll mid = L + R >> 1;
		if (calc(mid).se >= k) p = mid, L = mid + 1;
		else R = mid - 1;
	}
	printf("%lld\n", (long long)(calc(p).fi + k * p));
    return 0;
}