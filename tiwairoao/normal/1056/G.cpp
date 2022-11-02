#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<iostream>
using namespace std;
typedef long long ll;
const int MAXN = 100000;
struct treap{
	struct node{
		int key, siz;
		node *ch[2];
	}pl[30*MAXN + 5], *ncnt, *NIL;
	typedef pair<node*, node*> Droot;
	treap() {
		NIL = &pl[0];
		NIL->ch[0] = NIL->ch[1] = NIL;
		NIL->key = NIL->siz = 0;
	}
	void trans(int *f, node *x, int k) {
		if( x == NIL ) return ;
		f[x->ch[0]->siz + k + 1] = x->key;
		trans(f, x->ch[0], k);
		trans(f, x->ch[1], x->ch[0]->siz + k + 1);
	}
	void pushup(node *x) {
		x->siz = x->ch[0]->siz + x->ch[1]->siz + 1;
	}
	node *build(int *f, int l, int r) {
		if( l > r ) return NIL;
		int mid = (l + r) >> 1;
		node *p = (++ncnt); p->key = f[mid];
		p->ch[0] = build(f, l, mid - 1);
		p->ch[1] = build(f, mid + 1, r);
		pushup(p);
		return p;
	}
	node *build(int *f, int n) {
		ncnt = &pl[0];
		return build(f, 1, n);
	}
	Droot split(node *x, int k) {
		if( x == NIL ) return make_pair(NIL, NIL);
		node *p = (++ncnt); (*p) = (*x);
		if( x->ch[0]->siz >= k ) {
			Droot q = split(x->ch[0], k);
			p->ch[0] = q.second; pushup(p);
			return make_pair(q.first, p);
		}
		else {
			Droot q = split(x->ch[1], k - x->ch[0]->siz - 1);
			p->ch[1] = q.first; pushup(p);
			return make_pair(p, q.second);
		}
	}//first k elements
	node *merge(node *x, node *y) {
		if( x == NIL ) return y;
		if( y == NIL ) return x;
		node *p = (++ncnt);
		if( rand() & 1 ) {
			(*p) = (*x), p->ch[1] = merge(x->ch[1], y);
			pushup(p);
		}
		else {
			(*p) = (*y), p->ch[0] = merge(x, y->ch[0]);
			pushup(p);
		}
		return p;
	}
}T;
treap::node *root;
int f[MAXN + 5];
int nxt[45][MAXN + 5];
int main() {
	int n, m, s; ll t;
	scanf("%d%d%d%lld", &n, &m, &s, &t);
	srand(20041112 ^ n ^ m ^ s);
	for(int i=1;i<=n;i++) f[i] = i;
	root = T.build(f, n);
	for(int i=1;i<=n;i++) {
		if( i % 300 == 0 )
			T.trans(f, root, 0), root = T.build(f, n);
		treap::node *p, *q;
		treap::node *tmp = T.split(root, i).second;
		if( tmp->siz >= m )
			p = T.split(tmp, m).first;
		else p = T.merge(tmp, T.split(root, m-tmp->siz).first);
		tmp = T.split(root, n - i).first;
		if( tmp->siz >= n-m )
			q = T.split(tmp, tmp->siz-(n-m)).second;
		else q = T.merge(T.split(root, n-((n-m)-tmp->siz)).second, tmp);
		root = T.merge(p, q);
	}
	T.trans(f, root, 0);
	while( t % n ) {
		if( s <= m ) s = (s - 1 + t) % n + 1;
		else s = ((s - 1 - t) % n + n) % n + 1;
		t--;
	}
	for(int i=1;i<=n;i++) nxt[0][i] = f[i];
	for(int j=1;j<45;j++)
		for(int i=1;i<=n;i++)
			nxt[j][i] = nxt[j-1][nxt[j-1][i]];
	int x = t/n;
	for(int i=44;i>=0;i--)
		if( (1LL<<i) & x ) s = nxt[i][s];
	printf("%d\n", s);
}