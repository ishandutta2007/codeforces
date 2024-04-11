#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
#define mp make_pair
#define fi first
#define se second

const int MAXN = 150000;

int n, m, p, q;

struct node{
	pii a[5]; int s;
	node() {s = 0;}
	node(pii x) {a[0] = x, s = 1;}
	friend node insert(const node &A, const pii &x) {
		node B = A;
		for(int i=0;i<B.s;i++)
			if( B.a[i].se == x.se ) {
				B.a[i].fi += x.fi;
				return B;
			}
		if( B.s < q )
			B.a[B.s++] = x;
		else {
			int mn = 0;
			for(int i=0;i<B.s;i++)
				if( B.a[i].fi < B.a[mn].fi ) mn = i;
			if( B.a[mn].fi >= x.fi ) {
				for(int i=0;i<B.s;i++)
					B.a[i].fi -= x.fi;
			}
			else {
				pii y = B.a[mn]; B.a[mn] = x;
				for(int i=0;i<B.s;i++)
					B.a[i].fi -= y.fi;
			}
		}
		return B;
	}
	friend node merge(const node &A, const node &B) {
		if( A.s == 0 ) return B;
		if( B.s == 0 ) return A;
		node C = A;
		for(int i=0;i<B.s;i++)
			C = insert(C, B.a[i]);
		return C;
	}
};

int a[MAXN + 5];
struct segtree{
	#define lch (x << 1)
	#define rch (x << 1 | 1)
	
	int le[4*MAXN + 5], ri[4*MAXN + 5], tg[4*MAXN + 5];
	node nd[4*MAXN + 5];
	void pushup(int x) {
		nd[x] = merge(nd[lch], nd[rch]);
	}
	void pushdown(int x) {
		if( tg[x] ) {
			nd[lch] = node(mp(ri[lch]-le[lch]+1, tg[x]));
			nd[rch] = node(mp(ri[rch]-le[rch]+1, tg[x]));
			tg[lch] = tg[rch] = tg[x], tg[x] = 0;
		}
	}
	void build(int x, int l, int r) {
		le[x] = l, ri[x] = r, tg[x] = 0;
		if( l == r ) {
			nd[x] = node(mp(1, a[l]));
			return ;
		}
		int m = (l + r) >> 1;
		build(lch, l, m), build(rch, m + 1, r);
		pushup(x);
	}
	void modify(int x, int l, int r, int k) {
		if( l > ri[x] || r < le[x] )
			return ;
		if( l <= le[x] && ri[x] <= r ) {
			nd[x] = node(mp(ri[x]-le[x]+1, k)), tg[x] = k;
			return ;
		}
		pushdown(x);
		modify(lch, l, r, k), modify(rch, l, r, k);
		pushup(x);
	}
	node query(int x, int l, int r) {
		if( l > ri[x] || r < le[x] )
			return node();
		if( l <= le[x] && ri[x] <= r )
			return nd[x];
		pushdown(x);
		return merge(query(lch, l, r), query(rch, l, r));
	}
}T;

void solve(int l, int r) {
	node nd = T.query(1, l, r);
	printf("%d", nd.s);
	for(int i=0;i<nd.s;i++)
		printf(" %d", nd.a[i].se);
	puts("");
}

int main() {
	scanf("%d%d%d", &n, &m, &p), q = 100 / p;
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	T.build(1, 1, n);
	for(int i=1;i<=m;i++) {
		int op; scanf("%d", &op);
		if( op == 1 ) {
			int l, r, id; scanf("%d%d%d", &l, &r, &id);
			T.modify(1, l, r, id);
		}
		else {
			int l, r; scanf("%d%d", &l, &r);
			solve(l, r);
		}
	}
}