#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
#define mp make_pair
#define fi first
#define se second
const int MAXN = 200000;
int lg[2*MAXN + 5];
struct tree{
	struct edge{
		int to; edge *nxt;
	}edges[MAXN + 5], *adj[MAXN + 5], *ecnt;
	int tid[MAXN + 5], dep[MAXN + 5], siz[MAXN + 5], dcnt;
	int fir[MAXN + 5], dfn[2*MAXN + 5], st[20][2*MAXN + 5], dcnt1;
	tree() {ecnt = &edges[0], dcnt = dcnt1 = 0;}
	void addedge(int u, int v) {
		edge *p = (++ecnt);
		p->to = v, p->nxt = adj[u], adj[u] = p;
	}
	void dfs(int x, int f) {
		tid[x] = (++dcnt), dep[x] = dep[f] + 1, siz[x] = 1;
		dfn[++dcnt1] = x, fir[x] = dcnt1;
		for(edge *p=adj[x];p;p=p->nxt)
			dfs(p->to, x), dfn[++dcnt1] = x, siz[x] += siz[p->to];
	}
	void get_st() {
		for(int i=2;i<=dcnt1;i++) lg[i] = lg[i>>1] + 1;
		for(int i=1;i<=dcnt1;i++) st[0][i] = dfn[i];
		for(int j=1;j<20;j++) {
			int t = (1<<(j-1));
			for(int i=1;i+t<=dcnt1;i++)
				st[j][i] = (dep[st[j-1][i]] <= dep[st[j-1][i+t]]) ? st[j-1][i] : st[j-1][i+t];
		}
	}
	void build() {dfs(1, 0); get_st();}
	int lca(int u, int v) {
		int p = fir[u], q = fir[v];
		if( p > q ) swap(p, q);
		int l = lg[q - p + 1], k =(1<<l);
		return (dep[st[l][p]] <= dep[st[l][q-k+1]]) ? st[l][p] : st[l][q-k+1];
	}
	bool subtree(int x, int y) {return tid[x] <= tid[y] && tid[y] <= tid[x] + siz[x] - 1;}
	bool line(int u, int v, int x) {return subtree(v, x) && subtree(x, u);}
	bool line(int u, int v, int l, int x) {return line(u, l, x) || line(v, l, x);}
	bool check(int u, int v, int x, int y) {
		int l = lca(u, v);
		return line(u, v, l, x) && line(u, v, l, y);
	}
}T;
pii merge(pii a, pii b) {
	if( a.fi == 0 ) return b;
	if( b.fi == 0 ) return a;
	if( a.fi == -1 || b.fi == -1 ) return mp(-1, -1);
	if( T.check(a.fi, b.fi, a.se, b.se) ) return mp(a.fi, b.fi);
	if( T.check(a.fi, b.se, a.se, b.fi) ) return mp(a.fi, b.se);
	if( T.check(a.se, b.fi, a.fi, b.se) ) return mp(a.se, b.fi);
	if( T.check(a.se, b.se, a.fi, b.fi) ) return mp(a.se, b.se);
	if( T.check(a.fi, a.se, b.fi, b.se) ) return mp(a.fi, a.se);
	if( T.check(b.fi, b.se, a.fi, a.se) ) return mp(b.fi, b.se);
	return mp(-1, -1);
}
int p[MAXN + 5], a[MAXN + 5];
struct segtree{
	#define lch (x<<1)
	#define rch (x<<1|1)
	int le[4*MAXN + 5], ri[4*MAXN + 5];
	pii key[4*MAXN + 5];
	void pushup(int x) {key[x] = merge(key[lch], key[rch]);}
	void build(int x, int l, int r) {
		le[x] = l, ri[x] = r;
		if( l == r ) {
			key[x] = mp(a[l], a[l]);
			return ;
		}
		int mid = (l + r) >> 1;
		build(lch, l, mid), build(rch, mid + 1, r);
		pushup(x);
	}
	void update(int x, int p) {
		if( le[x] == ri[x] ) {
			key[x] = mp(a[p], a[p]);
			return ;
		}
		int mid = (le[x] + ri[x]) >> 1;
		if( p <= mid ) update(lch, p);
		else update(rch, p);
		pushup(x);
	}
	int query(int x, pii nw) {
		if( le[x] == ri[x] )
			return merge(nw, key[x]).fi != -1;
		pii p = merge(nw, key[lch]);
		int mid = (le[x] + ri[x]) >> 1;
		if( p.fi == -1 ) return query(lch, nw);
		else return query(rch, p) + (mid - le[x] + 1);
	}
	int query() {return query(1, mp(0, 0));}
}segT;
int n, q;
int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &p[i]), p[i]++, a[p[i]] = i;
	for(int i=2;i<=n;i++) {
		int d; scanf("%d", &d);
		T.addedge(d, i);
	}
	T.build();
	segT.build(1, 1, n);
	scanf("%d", &q);
	for(int i=1;i<=q;i++) {
		int op; scanf("%d", &op);
		if( op == 1 ) {
			int x, y; scanf("%d%d", &x, &y);
			swap(a[p[x]], a[p[y]]), swap(p[x], p[y]);
			segT.update(1, p[x]), segT.update(1, p[y]);
		}
		else printf("%d\n", segT.query());
	}
}