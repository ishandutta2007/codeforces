#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

const int MAXN = 200000;
const int MAXM = 1000000;
const int INF = int(2E9);

int tmp[MAXM + 5]; pii a[MAXN + 5], b[MAXN + 5];
namespace segtree{
	#define lch (x << 1)
	#define rch (x << 1 | 1)
	
	int le[4*MAXM + 5], ri[4*MAXM + 5];
	int mx[4*MAXM + 5], tg[4*MAXM + 5];
	void pushup(int x) {
		mx[x] = max(mx[lch], mx[rch]) + tg[x];
	}
	void build(int x, int l, int r) {
		le[x] = l, ri[x] = r, tg[x] = 0;
		if( l == r ) {
			mx[x] = tmp[l];
			return ;
		}
		int m = (l + r) >> 1;
		build(lch, l, m), build(rch, m + 1, r);
		pushup(x);
	}
	void modify(int x, int l, int r, int d) {
		if( l > ri[x] || r < le[x] )
			return ;
		if( l <= le[x] && ri[x] <= r ) {
			tg[x] += d, mx[x] += d;
			return ;
		}
		modify(lch, l, r, d), modify(rch, l, r, d);
		pushup(x);
	}
}

struct node{
	pii a; int c;
	friend bool operator < (node x, node y) {
		return (x.a == y.a) ? x.c < y.c : x.a < y.a;
	}
}c[MAXN + 5];

int n, m, p;
int main() {
	scanf("%d%d%d", &n, &m, &p);
	for(int i=1;i<=n;i++) scanf("%d%d", &a[i].fi, &a[i].se);
	for(int i=1;i<=m;i++) scanf("%d%d", &b[i].fi, &b[i].se);
	for(int i=1;i<=p;i++) scanf("%d%d%d", &c[i].a.fi, &c[i].a.se, &c[i].c);
	sort(a + 1, a + n + 1), sort(b + 1, b + m + 1), sort(c + 1, c + p + 1);
	
	for(int i=1;i<=MAXM;i++) tmp[i] = -INF;
	for(int i=1;i<=m;i++) tmp[b[i].fi] = max(tmp[b[i].fi], -b[i].se);
	segtree::build(1, 1, MAXM);
	
	int k = 0, ans = -INF;
	for(int i=1;i<=n;i++) {
		while( k < p && c[k + 1].a.fi < a[i].fi )
			k++, segtree::modify(1, c[k].a.se + 1, MAXM, c[k].c);
		ans = max(ans, segtree::mx[1] - a[i].se);
	}
	printf("%d\n", ans);
}