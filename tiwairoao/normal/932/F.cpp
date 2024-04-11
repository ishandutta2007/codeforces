#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 100000;
const ll INF = (1LL<<60);
struct line{
	ll k, b;
	line(ll _k=0, ll _b=0) : k(_k), b(_b) {}
	ll get(ll x) {return k * x + b;}
};
ll a[MAXN + 5], b[MAXN + 5], f[MAXN + 5];
struct segtree{
	struct node{
		line l;
		node *ch[2];
	}pl[60*MAXN + 5], *ncnt, *NIL;
	segtree() {
		NIL = ncnt = pl;
		NIL->ch[0] = NIL->ch[1] = NIL;
	}
	node *newnode(line l) {
		node *p = (++ncnt);
		p->ch[0] = p->ch[1] = NIL, p->l = l;
		return p;
	}
	void insert(node *&rt, int l, int r, line ln) {
		if( rt == NIL ) {
			rt = newnode(ln);
			return ;
		}
		int m = (int)floor(1.0*(l + r)/2);
		if( rt->l.get(l) > ln.get(l) ) swap(rt->l, ln);
		if( rt->l.get(m) > ln.get(m) )
			swap(rt->l, ln), insert(rt->ch[0], l, m, ln);
		else if( rt->l.get(r) > ln.get(r) )
			insert(rt->ch[1], m + 1, r, ln);
	}
	ll query(node *rt, int l, int r, ll p) {
		if( rt == NIL ) return INF;
		if( l == r ) return rt->l.get(p);
		int m = (int)floor(1.0*(l + r)/2);
		if( p <= m ) return min(rt->l.get(p), query(rt->ch[0], l, m, p));
		else return min(rt->l.get(p), query(rt->ch[1], m + 1, r, p));
	}
	node *merge(node *rt1, node *rt2, int l, int r) {
		if( rt1 == NIL ) return rt2;
		if( rt2 == NIL ) return rt1;
		int m = (int)floor(1.0*(l + r)/2);
		rt1->ch[0] = merge(rt1->ch[0], rt2->ch[0], l, m);
		rt1->ch[1] = merge(rt1->ch[1], rt2->ch[1], m + 1, r);
		insert(rt1, l, r, rt2->l);
		return rt1;
	}
}T;
struct edge{
	int to; edge *nxt;
}edges[2*MAXN + 5], *adj[MAXN + 5], *ecnt = edges;
void addedge(int u, int v) {
	edge *p = (++ecnt);
	p->to = v, p->nxt = adj[u], adj[u] = p;
	p = (++ecnt);
	p->to = u, p->nxt = adj[v], adj[v] = p;
}
segtree::node *rt[MAXN + 5];
void dfs(int x, int fa) {
	rt[x] = T.NIL;
	for(edge *p=adj[x];p;p=p->nxt)
		if( p->to != fa )
			dfs(p->to, x), rt[x] = T.merge(rt[x], rt[p->to], -MAXN, MAXN);
	if( rt[x] == T.NIL ) f[x] = 0;
	else f[x] = T.query(rt[x], -MAXN, MAXN, a[x]);
	T.insert(rt[x], -MAXN, MAXN, line(b[x], f[x]));
}
int main() {
	int n; scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%lld", &a[i]);
	for(int i=1;i<=n;i++) scanf("%lld", &b[i]);
	for(int i=1;i<n;i++) {
		int u, v; scanf("%d%d", &u, &v);
		addedge(u, v);
	}
	dfs(1, 0);
	for(int i=1;i<=n;i++) printf("%lld%c", f[i], i == n ? '\n' : ' ');
}