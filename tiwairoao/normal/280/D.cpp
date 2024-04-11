#include<cstdio>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 100000;
const int INF = int(1E8);
int a[MAXN + 5];
struct node2{
	int l, r, s;
	node2(int _l=0, int _r=0, int _s=0):l(_l), r(_r), s(_s) {}
	friend bool operator < (const node2 &a, const node2 &b) {
		return a.s < b.s;
	}
};
struct node{
	int sum; node2 smn, smx;
	pii lmn, rmn, lmx, rmx;
};
struct segtree{
	#define lch (x<<1)
	#define rch (x<<1|1)
	#define mp make_pair
	#define fi first
	#define se second
	int le[4*MAXN + 5], ri[4*MAXN + 5], tg[4*MAXN + 5];
	node t[4*MAXN + 5];
	void func(const pii &a, const pii &b, pii &c, const int &k, bool type) {
		if( type == 0 ) c = min(a, mp(k + b.fi, b.se));
		else c = max(a, mp(k + b.fi, b.se));
	}
	node merge(const node &a, const node &b) {
		node c; c.sum = a.sum + b.sum;
		func(a.lmn, b.lmn, c.lmn, a.sum, 0), func(a.lmx, b.lmx, c.lmx, a.sum, 1);
		func(b.rmn, a.rmn, c.rmn, b.sum, 0), func(b.rmx, a.rmx, c.rmx, b.sum, 1);
		c.smx = max(node2(a.rmx.se, b.lmx.se, a.rmx.fi + b.lmx.fi), max(a.smx, b.smx));
		c.smn = min(node2(a.rmn.se, b.lmn.se, a.rmn.fi + b.lmn.fi), min(a.smn, b.smn));
		return c;
	}
	void get(int x, int k) {
		t[x].sum = a[k];
		t[x].lmn = t[x].lmx = t[x].rmn = t[x].rmx = mp(a[k], k);
		t[x].smn = t[x].smx = node2(k, k, a[k]);
	}
	void pushup(int x) {t[x] = merge(t[lch], t[rch]);}
	void maintain(int x) {
		tg[x] ^= 1;
		t[x].sum *= -1, t[x].smn.s *= -1, t[x].smx.s *= -1;
		t[x].lmn.fi *= -1, t[x].rmn.fi *= -1, t[x].lmx.fi *= -1, t[x].rmx.fi *= -1;
		swap(t[x].smn, t[x].smx), swap(t[x].lmn, t[x].lmx), swap(t[x].rmn, t[x].rmx);
	}
	void pushdown(int x) {
		if( tg[x] ) {
			maintain(lch), maintain(rch);
			tg[x] = false;
		}
	}
	void build(int x, int l, int r) {
		le[x] = l, ri[x] = r, tg[x] = false;
		if( l == r ) {
			get(x, l);
			return ;
		}
		int mid = (l + r) >> 1;
		build(lch, l, mid), build(rch, mid + 1, r);
		pushup(x); 
	}
	void modify(int x, int l, int r) {
		if( l <= le[x] && ri[x] <= r ) {
			maintain(x);
			return ;
		}
		if( l > ri[x] || r < le[x] )
			return ;
		pushdown(x);
		modify(lch, l, r);
		modify(rch, l, r);
		pushup(x);
	}
	void update(int x, int p) {
		if( p > ri[x] || p < le[x] )
			return ;
		if( le[x] == ri[x] ) {
			get(x, le[x]);
			return ;
		}
		pushdown(x);
		update(lch, p);
		update(rch, p);
		pushup(x);
	}
	node query(int x, int l, int r) {
		if( l <= le[x] && ri[x] <= r )
			return t[x];
		pushdown(x);
		int mid = (le[x] + ri[x]) >> 1;
		if( l > mid ) return query(rch, l, r);
		else if( r <= mid ) return query(lch, l, r);
		else return merge(query(lch, l, r), query(rch, l, r));
	}
}T;
int dfs(int l, int r, int k) {
	if( k == 0 ) return 0;
	node p = T.query(1, l, r);
	T.modify(1, p.smx.l, p.smx.r);
	int ret = dfs(l, r, k - 1);
	T.modify(1, p.smx.l, p.smx.r);
	return p.smx.s + max(0, ret);
}
int n, m;
int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &a[i]);
	T.build(1, 1, n);
	scanf("%d", &m);
	for(int i=1;i<=m;i++) {
		int op; scanf("%d", &op);
		if( op == 0 ) {
			int x, val; scanf("%d%d", &x, &val);
			a[x] = val, T.update(1, x);
		}
		else {
			int l, r, k; scanf("%d%d%d", &l, &r, &k);
			printf("%d\n", max(0, dfs(l, r, k)));
		}
	}
}