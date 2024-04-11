#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 200000;

struct edge{
	int to; edge *nxt;
}edges[2*MAXN + 5], *adj[2*MAXN + 5], *ecnt;
void addedge(int u, int v) {
	edge *p = (++ecnt);
	p->to = v, p->nxt = adj[u], adj[u] = p;
}

struct node{
	int pos, len;
	node *ch[26], *fa;
}pl[2*MAXN + 5], *ncnt, *root, *lst;
void extend(int x, int pos) {
	node *p = lst, *cur = (++ncnt); lst = cur;
	cur->pos = pos, cur->len = p->len + 1;
	while( p && p->ch[x] == NULL )
		p->ch[x] = cur, p = p->fa;
	if( !p ) cur->fa = root;
	else {
		node *q = p->ch[x];
		if( p->len + 1 == q->len )
			cur->fa = q;
		else {
			node *nq = (++ncnt); (*nq) = (*q);
			nq->len = p->len + 1, nq->pos = -1;
			q->fa = cur->fa = nq;
			while( p && p->ch[x] == q )
				p->ch[x] = nq, p = p->fa;
		}
	}
}
struct segtree{
	struct node{
		int mx;
		node *ch[2];
	}pl[80*MAXN + 5], *ncnt, *NIL;
	segtree() {
		ncnt = NIL = pl;
		NIL->ch[0] = NIL->ch[1] = NIL;
		NIL->mx = -1;
	}
	void pushup(node *x) {x->mx = max(x->ch[0]->mx, x->ch[1]->mx);}
	node *insert(int l, int r, int ps) {
		node *p = (++ncnt); p->mx = ps, p->ch[0] = p->ch[1] = NIL;
		if( l == r ) return p;
		int m = (l + r) >> 1;
		if( ps <= m ) p->ch[0] = insert(l, m, ps);
		else p->ch[1] = insert(m + 1, r, ps);
		return p;
	}
	node *merge(node *x, node *y) {
		if( x == NIL ) return y;
		if( y == NIL ) return x;
		node *p = (++ncnt);
		p->ch[0] = merge(x->ch[0], y->ch[0]);
		p->ch[1] = merge(x->ch[1], y->ch[1]);
		pushup(p); return p;
	}
	int query(node *x, int l, int r, int p) {
		if( l == r ) return p >= r ? x->mx : -1;
		int m = (l + r) >> 1;
		if( p <= m ) return query(x->ch[0], l, m, p);
		else return max(x->ch[0]->mx, query(x->ch[1], m + 1, r, p));
	}
}T;
int n;
segtree::node *rt[2*MAXN + 5];
void dfs1(int x, int fa) {
	if( pl[x].pos != -1 ) rt[x] = T.insert(1, n, pl[x].pos);
	else rt[x] = T.NIL;
	for(edge *p=adj[x];p;p=p->nxt) {
		if( p->to == fa ) continue;
		dfs1(p->to, x);
		rt[x] = T.merge(rt[x], rt[p->to]);
	}
}
int a[2*MAXN + 5], cnt, nw;
int f[2*MAXN + 5];
void dfs2(int x, int fa) {
	a[++cnt] = x;
	int tmp = nw;
	if( fa != -1 ) {
		int q = rt[x]->mx;
		while( true ) {
			int p = T.query(rt[a[nw]], 1, n, q - 1);
			if( !(q - pl[x].len <= p - pl[a[nw]].len) ) break;
			else nw++;
		}
		f[x] = f[a[nw - 1]]+1;
	}
	for(edge *p=adj[x];p;p=p->nxt) {
		if( p->to == fa ) continue;
		dfs2(p->to, x);
	}
	nw = tmp;
	a[cnt--] = 0;
}
void init() {ncnt = root = lst = pl, ecnt = edges; root->pos = -1;}
char s[MAXN + 5];
int main() {
	init(), scanf("%d%s", &n, s + 1);
	for(int i=1;i<=n;i++) extend(s[i] - 'a', i);
	for(int i=1;i<=ncnt-pl;i++) addedge(pl[i].fa-pl, i);
	dfs1(root - pl, -1), nw = 1, dfs2(root - pl, -1);
	int ans = 0;
	for(int i=1;i<=ncnt-pl;i++)
		ans = max(ans, f[i]);
	printf("%d\n", ans);
}