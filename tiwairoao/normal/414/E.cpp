#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 200000;
struct Splay{
	struct node{
		node *fa, *ch[2];
		int num, key, mx, mn, tg;
	}pl[2*MAXN + 5], *root, *NIL;
	Splay() {
		root = NIL = &pl[0];
		NIL->ch[0] = NIL->ch[1] = NIL->fa = NIL;
		NIL->mx = -MAXN, NIL->mn = MAXN, NIL->tg = 0;
	}
	void set_child(node *x, node *y, int d) {
		if( x != NIL ) x->ch[d] = y;
		if( y != NIL ) y->fa = x;
	}
	void pushdown(node *x) {
		if( x->tg ) {
			if( x->ch[0] != NIL )
				x->ch[0]->key += x->tg, x->ch[0]->mx += x->tg, x->ch[0]->mn += x->tg, x->ch[0]->tg += x->tg;
			if( x->ch[1] != NIL )
				x->ch[1]->key += x->tg, x->ch[1]->mx += x->tg, x->ch[1]->mn += x->tg, x->ch[1]->tg += x->tg;
			x->tg = 0;
		}
	}
	void pushup(node *x) {
		x->mn = min(x->key, min(x->ch[0]->mn, x->ch[1]->mn));
		x->mx = max(x->key, max(x->ch[0]->mx, x->ch[1]->mx));
	}
	void rotate(node *x) {
		node *y = x->fa; int d = (y->ch[1] == x);
		pushdown(y), pushdown(x);
		if( y->fa != NIL ) set_child(y->fa, x, y->fa->ch[1] == y);
		else x->fa = y->fa;
		set_child(y, x->ch[!d], d);
		set_child(x, y, !d);
		if( y == root ) root = x;
		pushup(y);
	}
	void splay(node *x, node *rt) {
		pushdown(x);
		while( x->fa != rt ) {
			node *y = x->fa;
			if( y->fa == rt )
				rotate(x);
			else {
				if( (y->fa->ch[1] == y) == (y->ch[1] == x) )
					rotate(y);
				else rotate(x);
				rotate(x);
			}
		}
		pushup(x);
	}
	void debug(node *x) {
		if( x == NIL ) return ;
		pushdown(x);
		debug(x->ch[0]);
		printf("%d : %d %d %d | %d %d\n", x-pl, x->ch[0]-pl, x->ch[1]-pl, x->fa-pl, x->num, x->key);
		debug(x->ch[1]);
	}
	int dist(node *x, node *y) {
		splay(x, NIL), splay(y, root);
		if( x->ch[0] == y ) {
			int d = min(min(x->key, y->key), x->ch[0]->ch[1]->mn);
			return x->key + y->key - 2*d;
		}
		else {
			int d = min(min(x->key, y->key), x->ch[1]->ch[0]->mn);
			return x->key + y->key - 2*d;
		}
	}
	node *query(node *x, int d) {
		pushdown(x);
		if( x->ch[1]->mn <= d && d <= x->ch[1]->mx )
			return query(x->ch[1], d);
		else if( x->key == d ) {
			splay(x, NIL);
			return x;
		}
		else return query(x->ch[0], d);
	}
	node *prev(node *x, node *rt) {
		splay(x, rt);
		node *ret = x->ch[0];
		while( ret->ch[1] != NIL )
			ret = ret->ch[1];
		splay(ret, rt);
		return ret;
	}
	node *next(node *x, node *rt) {
		splay(x, rt);
		node *ret = x->ch[1];
		while( ret->ch[0] != NIL )
			ret = ret->ch[0];
		splay(ret, rt);
		return ret;
	}
}T;
Splay::node *fir[MAXN + 5], *bac[MAXN + 5];
int n, m, root;
vector<int>G[MAXN + 5];
void addedge(int u, int v) {
	G[u].push_back(v);
}
int dep[MAXN + 5], dfn[2*MAXN + 5], dcnt;
void newnode(Splay::node *nw, int x, int k) {
	nw->ch[0] = nw->ch[1] = nw->fa = T.NIL;
	nw->num = x, nw->key = nw->mn = nw->mx = k, nw->tg = 0;
}
void dfs(int x) {
	dfn[++dcnt] = x, fir[x] = bac[x] = &T.pl[dcnt], newnode(&T.pl[dcnt], x, dep[x]);
	for(int i=0;i<G[x].size();i++) {
		int p = G[x][i];
		dep[p] = dep[x] + 1, dfs(p);
		dfn[++dcnt] = x, bac[x] = &T.pl[dcnt], newnode(&T.pl[dcnt], x, dep[x]);
	}
}
Splay::node *build(int l, int r) {
	if( l > r ) return T.NIL;
	int mid = (l + r) >> 1;
	Splay::node *p = &T.pl[mid];
	p->ch[0] = build(l, mid - 1);
	if( p->ch[0] != T.NIL ) p->ch[0]->fa = p;
	p->ch[1] = build(mid + 1, r);
	if( p->ch[1] != T.NIL ) p->ch[1]->fa = p;
	T.pushup(p);
	return p;
}
bool tag[MAXN + 5];
int main() {
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++) {
		int l; scanf("%d", &l);
		for(int j=1;j<=l;j++) {
			int x; scanf("%d", &x);
			addedge(i, x); tag[x] = true;
		}
	}
	for(int i=1;i<=n;i++)
		if( !tag[i] ) root = i;
	newnode(&T.pl[++dcnt], 0, -1), dfs(root), newnode(&T.pl[++dcnt], 0, -1);
	T.root = build(1, dcnt);
	for(int i=1;i<=m;i++) {
		int op; scanf("%d", &op);
		if( op == 1 ) {
			int v, u; scanf("%d%d", &v, &u);
			printf("%d\n", T.dist(fir[v], fir[u]));
		}
		else if( op == 2 ) {
			int v, h; scanf("%d%d", &v, &h);
			T.splay(fir[v], T.NIL); Splay::node *u = T.query(fir[v]->ch[0], fir[v]->key-h);
			Splay::node *l = T.prev(fir[v], T.NIL), *r = T.next(bac[v], T.root);
			if( bac[l->num] == r ) bac[l->num] = l;
			T.set_child(l, r->ch[1], 1);
			Splay::node *p = r->ch[0];
			newnode(r, u->num, u->key), r->ch[0] = p;
			r->tg += 1-h, T.pushdown(r), T.pushup(r);
			T.next(bac[u->num], T.NIL), T.splay(bac[u->num], T.root);
			bac[u->num] = r;
			T.set_child(T.root->ch[0], r, 1);
		}
		else if( op == 3 ) {
			int k; scanf("%d", &k);
			printf("%d\n", T.query(T.root, k)->num);
		}
	}
}