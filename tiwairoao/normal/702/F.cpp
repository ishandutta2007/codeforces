#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 200000;
struct treap{
	struct node{
		node *ch[2];
		int key, tg1;
		int sum, tg2;
		unsigned int pri;
	}pl[MAXN + 5], *ncnt, *NIL;
	#define mp make_pair
	#define fi first
	#define se second
	typedef pair<node*, node*> Droot;
	unsigned int get_rand() {return (rand() << 16) | rand();}
	treap() {
		NIL = ncnt = &pl[0];
		NIL->ch[0] = NIL->ch[1] = NIL;
		NIL->key = NIL->tg1 = NIL->sum = NIL->tg2 = 0;
		NIL->pri = -1;
	}
	node *newnode(int k) {
		node *p = (++ncnt);
		p->ch[0] = p->ch[1] = NIL;
		p->key = k, p->tg1 = p->sum = p->tg2 = 0;
		p->pri = get_rand();
		return p;
	}
	void maintain1(node *x, int k) {if( x != NIL ) x->key += k, x->tg1 += k;}
	void maintain2(node *x, int k) {if( x != NIL ) x->sum += k, x->tg2 += k;}
	void pushdown(node *rt) {
		if( rt->tg1 ) {
			maintain1(rt->ch[0], rt->tg1), maintain1(rt->ch[1], rt->tg1);
			rt->tg1 = 0;
		}
		if( rt->tg2 ) {
			maintain2(rt->ch[0], rt->tg2), maintain2(rt->ch[1], rt->tg2);
			rt->tg2 = 0;
		}
	}
	node *merge(node *x, node *y) {
		if( x == NIL ) return y;
		if( y == NIL ) return x;
		pushdown(x), pushdown(y);
		if( x->pri < y->pri ) {
			x->ch[1] = merge(x->ch[1], y);
			return x;
		}
		else {
			y->ch[0] = merge(x, y->ch[0]);
			return y;
		}
	}
	Droot split(node *rt, int k) {
		if( rt == NIL ) return mp(NIL, NIL);
		pushdown(rt);
		if( rt->key < k ) {
			Droot p = split(rt->ch[1], k);
			rt->ch[1] = p.fi; return mp(rt, p.se);
		}
		else {
			Droot p = split(rt->ch[0], k);
			rt->ch[0] = p.se; return mp(p.fi, rt);
		}
	}// < k, >= k
	node *insert(node *rt, node *x) {
		Droot p = split(rt, x->key);
		return merge(p.fi, merge(x, p.se));
	}
	void push(node *&rt, node *x) {
		if( x == NIL ) return ;
		pushdown(x);
		push(rt, x->ch[0]), push(rt, x->ch[1]);
		x->ch[0] = x->ch[1] = NIL;
		rt = insert(rt, x);
	}
	node *update(node *rt, int k) {
		Droot p = split(rt, k);
		if( p.se == NIL ) return merge(p.fi, p.se);
		p.se->key -= k, p.se->tg1 -= k;
		p.se->sum += 1, p.se->tg2 += 1;
		Droot q = split(p.se, k);
		if( q.fi != NIL ) push(p.fi, q.fi);
		return merge(p.fi, q.se);
	}
	void dfs(node *x) {
		if( x == NIL ) return ;
		pushdown(x);
		dfs(x->ch[0]), dfs(x->ch[1]);
	}
}T;
treap::node *nd[MAXN + 5], *rt;
struct Tshirt{
	int c, q;
	Tshirt(int _c=0, int _q=0):c(_c), q(_q) {}
	friend bool operator < (Tshirt a, Tshirt b) {
		return (a.q == b.q) ? a.c < b.c : a.q > b.q;
	}
}t[MAXN + 5];
int ans[MAXN + 5];
int read() {
	int x = 0; char ch = getchar();
	while( ch > '9' || ch < '0' ) ch = getchar();
	while( '0' <= ch && ch <= '9' ) x = 10*x + ch - '0', ch = getchar();
	return x;
}
int main() {
	int n = read(), k;
	srand(n ^ 0307);
	for(int i=1;i<=n;i++)
		t[i].c = read(), t[i].q = read();
	sort(t + 1, t + n + 1);
	k = read(), rt = T.NIL;
	for(int i=1;i<=k;i++)
		rt = T.insert(rt, nd[i] = T.newnode(read()));
	for(int i=1;i<=n;i++)
		rt = T.update(rt, t[i].c);
	T.dfs(rt);
	for(int i=1;i<=k;i++)
		printf("%d ", nd[i]->sum);
}