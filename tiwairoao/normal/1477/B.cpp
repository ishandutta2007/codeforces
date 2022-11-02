#include <bits/stdc++.h>

const int N = 200000;

namespace segtree{
	#define lch (x << 1)
	#define rch (x << 1 | 1)
	
	int le[4*N + 5], ri[4*N + 5], tag[4*N + 5], sum[4*N + 5];
	
	void pushup(int x) {sum[x] = sum[lch] + sum[rch];}
	void pushdown(int x) {
		if( tag[x] != -1 ) {
			if( tag[x] ) {
				int m = (le[x] + ri[x]) >> 1;
				sum[lch] = (m - le[x] + 1), sum[rch] = (ri[x] - m);
			} else sum[lch] = sum[rch] = 0;
			tag[lch] = tag[rch] = tag[x], tag[x] = -1;
		}
	}
	void build(int x, int l, int r, char *s) {
		le[x] = l, ri[x] = r, tag[x] = -1;
		if( l == r ) {
			sum[x] = s[l] - '0';
			return ;
		}
		int m = (l + r) >> 1;
		build(lch, l, m, s), build(rch, m + 1, r, s);
		pushup(x);
	}
	void update(int x, int l, int r, int t) {
		if( l > ri[x] || r < le[x] ) return ;
		if( l <= le[x] && ri[x] <= r ) {
			if( t ) sum[x] = (ri[x] - le[x] + 1);
			else sum[x] = 0;
			tag[x] = t;
			return ;
		}
		pushdown(x);
		update(lch, l, r, t), update(rch, l, r, t);
		pushup(x);
	}
	int query(int x, int l, int r) {
		if( l > ri[x] || r < le[x] ) return 0;
		if( l <= le[x] && ri[x] <= r ) return sum[x];
		pushdown(x); return query(lch, l, r) + query(rch, l, r);
	}
	bool check(int x, char *s) {
		if( le[x] == ri[x] ) {
			return sum[x] == s[le[x]] - '0';
		}
		pushdown(x);
		return check(lch, s) && check(rch, s);
	}
}

char s[N + 5], f[N + 5];
int l[N + 5], r[N + 5], n, q;

void solve() {
	scanf("%d%d%s%s", &n, &q, s + 1, f + 1);
	segtree::build(1, 1, n, f);
	for(int i=1;i<=q;i++) scanf("%d%d", &l[i], &r[i]);
	for(int i=q;i>=1;i--) {
		int t = segtree::query(1, l[i], r[i]);
		if( (r[i] - l[i] + 1) % 2 == 0 && t == (r[i] - l[i] + 1) / 2 ) {
			puts("NO"); return ;
		} else segtree::update(1, l[i], r[i], 2*t > (r[i] - l[i] + 1));
	}
	puts(segtree::check(1, s) ? "YES" : "NO");
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}