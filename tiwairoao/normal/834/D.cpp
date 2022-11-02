#include <cstdio>
const int MAXN = 35000;
struct segtree{
	struct node{
		int tag;
		node *ch[2];
	}pl[40*MAXN + 5], *ncnt, *NIL;
	segtree() {
		ncnt = NIL = pl;
		NIL->ch[0] = NIL->ch[1] = NIL, NIL->tag = 0;
	}
	node *add(node *p, int l, int r, int ql, int qr) {
		if( ql > r || qr < l )
			return p;
		node *x = (++ncnt); (*x) = (*p);
		if( ql <= l && r <= qr ) {
			x->tag++;
			return x;
		}
		int m = (l + r) >> 1;
		x->ch[0] = add(p->ch[0], l, m, ql, qr);
		x->ch[1] = add(p->ch[1], m + 1, r, ql, qr);
		return x;
	}
	int query(node *x, int l, int r, int p) {
		if( l == r ) return x->tag;
		int m = (l + r) >> 1;
		if( p <= m ) return query(x->ch[0], l, m, p) + x->tag;
		else return query(x->ch[1], m + 1, r, p) + x->tag;
	}
}T;
int n, k;
segtree::node *rt[MAXN + 5];
int a[MAXN + 5], b[MAXN + 5], lst[MAXN + 5];
int f[MAXN + 5], g[MAXN + 5];
void solve(int *A, int *B, int opl, int opr, int l, int r) {
	if( l > r ) return ;
	int m = (l + r) >> 1, opm = opl;
	for(int i=opl;i<=opr&&i<=m;i++) {
		int v = T.query(rt[m], 1, n, i) + B[i-1];
		if( v > A[m] ) A[m] = v, opm = i;
	}
	solve(A, B, opl, opm, l, m - 1);
	solve(A, B, opm, opr, m + 1, r);
}
int main() {
	scanf("%d%d", &n, &k);
	rt[0] = T.NIL;
	for(int i=1;i<=n;i++) {
		scanf("%d", &a[i]);
		lst[i] = b[a[i]], b[a[i]] = i;
		rt[i] = T.add(rt[i-1], 1, n, lst[i] + 1, i);
	}
	for(int i=1;i<=k;i++) {
		for(int j=1;j<=n;j++) g[j] = f[j], f[j] = 0;
		solve(f, g, 1, n, 1, n);
	}
	printf("%d\n", f[n]);
}