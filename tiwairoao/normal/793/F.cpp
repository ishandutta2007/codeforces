#include <bits/stdc++.h>

const int N = 100000;

namespace segtree{
	const int S = (N << 2);

	#define lch (x << 1)
	#define rch (x << 1 | 1)

	struct type{
		int mx, smx;
		friend type operator + (const type &a, const type &b) {
			if (a.mx == b.mx) {
				return (type){a.mx, std::max(a.smx, b.smx)};
			} else if(a.mx > b.mx) {
				return (type){a.mx, std::max(a.smx, b.mx)};
			} else {
				return (type){b.mx, std::max(a.mx, b.smx)};
			}
		}
	}a[S + 5];

	int le[S + 5], ri[S + 5], tag[S + 5];
	void build(int x, int l, int r) {
		le[x] = l, ri[x] = r, tag[x] = 0;
		if (l == r) {
			a[x] = (type){l, -1};
		} else {
			int m = (l + r) >> 1;
			build(lch, l, m), build(rch, m + 1, r);
			a[x] = a[lch] + a[rch];
		}
	}

	void addtag(int x, int k) {
		a[x].mx = k, tag[x] = k;
	}
	void pushdown(int x) {
		if (tag[x]) {
			if (a[lch].mx == a[rch].mx)
				addtag(lch, tag[x]), addtag(rch, tag[x]);
			else if(a[lch].mx > a[rch].mx)
				addtag(lch, tag[x]);
			else addtag(rch, tag[x]);
			tag[x] = 0;
		}
	}
	void modify(int x, int p, int k) {
		if (a[x].mx < p) return;
		if (a[x].smx < p) {
			addtag(x, k);
		} else {
			pushdown(x);
			modify(lch, p, k), modify(rch, p, k);
			a[x] = a[lch] + a[rch];
		}
	}
	void update(int x, int p, int k) {
		if (le[x] == ri[x]) {
			addtag(x, k);
		} else {
			pushdown(x);

			int m = (le[x] + ri[x]) >> 1;
			if (p <= m) update(lch, p, k);
			else modify(lch, p, k), update(rch, p, k);

			a[x] = a[lch] + a[rch];
		}
	}
	int query(int x, int p) {
		if (le[x] == ri[x]) {
			return a[x].mx;
		} else {
			pushdown(x);

			int m = (le[x] + ri[x]) >> 1;
			return query(p <= m ? lch : rch, p);
		}
	}
}

struct query{int i, l, r;};
std::vector<query>qry[N + 5];

int ans[N + 5], fr[N + 5], n, m, q;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) fr[i] = n + 1;
	for (int i = 1, a, b; i <= m; i++) scanf("%d%d", &a, &b), fr[b] = a;
	scanf("%d", &q);
	for (int i = 1, l, r; i <= q; i++) scanf("%d%d", &l, &r), qry[r].push_back((query){i, l, r});

	segtree::build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		if (fr[i] < i) segtree::update(1, fr[i], i);
		for (auto p : qry[i]) ans[p.i] = segtree::query(1, p.l);
	}
	for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);

	return 0;
}