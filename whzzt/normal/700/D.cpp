#include<bits/stdc++.h>

using namespace std;

const int N = 100005, S = 320, T = N / S + 5, WS = 1023;

int c[N], n, q, w[N], Right[T], bl[N], a[N], ans[N];
set <int> lot;
struct Query {
	int l, r, id;
	friend bool operator < (const Query &x, const Query &y) {
		return bl[x.l] == bl[y.l] ? x.r < y.r : bl[x.l] < bl[y.l];
	}
} ask[N];

void update (int x, int u) {
	if (u == 1 && c[x] == WS) lot.insert (x);
	w[c[x]] --, c[x] += u, w[c[x]] ++;
	if (u == -1 && c[x] == WS) lot.erase (x);
}

int t[WS + 5];
map <int, int> data;

void work (int p, int &q, int &rem, int &ans) {
	if (rem) {
		q --, ans += p + rem;
		if (p + rem <= WS) t[p + rem] ++;
		else data[p + rem] ++;
		rem = 0;
	}
	if (q > 1) {
		ans += (q >> 1) * (p << 1);
		if (p << 1 <= WS) t[p << 1] += q >> 1;
		else data[p << 1] += q >> 1;
		q &= 1;
	}
	if (q) rem = p, q = 0;
}

int check () {
	int ret = 0, rem = 0;
	memcpy (t + 1, w + 1, WS << 2);
	for (int p : lot) data[c[p]] ++;
	for (int p = 1; p <= WS; p ++) if (t[p]) work (p, t[p], rem, ret);
	while (data.size()) {
		auto it = data.begin();
		work (it -> first, it -> second, rem, ret);
		data.erase (it);
	}
	return ret;
}

int main(){
	scanf ("%d", &n);
	for (int i = 1; i <= n; i ++) scanf ("%d", &a[i]);
	for (int i = 1; i <= n; i ++) bl[i] = i / S, Right[bl[i]] = i;
	scanf ("%d", &q);
	for (int i = 1; i <= q; i ++) scanf ("%d %d", &ask[i].l, &ask[i].r), ask[i].id = i;
	sort (ask + 1, ask + q + 1), w[0] = 1E5;
	for (int i = 1, j = 1; i <= q; i = j) {
		while (j <= q && bl[ask[j].l] == bl[ask[i].l]) j ++;
		int k = i, lim = Right[bl[ask[i].l]];
		while (k < j && ask[k].r <= lim) {
			for (int p = ask[k].l; p <= ask[k].r; p ++) update (a[p], 1);
			ans [ask[k].id] = check ();
			for (int p = ask[k].l; p <= ask[k].r; p ++) update (a[p], -1);
			k ++;
		}
		int lp = lim, rp = lim - 1;
		while (k < j) {
			while (rp < ask[k].r) update (a[++ rp], 1);
			while (lp <= ask[k].l) update (a[lp ++], -1);
			while (lp > ask[k].l) update (a[-- lp], 1);
			ans[ask[k ++].id] = check();
		}
		while (lp <= rp) update (a[lp ++], -1);
	}
	for (int i = 1; i <= q; i ++) printf ("%d\n", ans[i]);
	return 0;
}