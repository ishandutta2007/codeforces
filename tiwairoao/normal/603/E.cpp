#include<set>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 100000;
const int MAXM = 300000;
struct node{
	int key, id, rev;
	int siz1, siz2, s;
	node *fa, *ch[2], *mx;
}tree[MAXN+MAXM+5], *ad[MAXN+MAXM+5];
struct edge{
	int u, v, w, id;
	edge(int _u=0, int _v=0, int _w=0, int _i=0):u(_u), v(_v), w(_w), id(_i){}
}e[MAXM + 5];
bool operator < (edge a, edge b) {
	if( a.w == b.w ) return a.id < b.id;
	return a.w < b.w;
}
set<edge>Set;
set<edge>::iterator it;
node *NIL, *ncnt;
void Init() {
	NIL = ncnt = &tree[0];
	NIL->fa = NIL->ch[0] = NIL->ch[1] = NIL->mx = NIL;
	NIL->key = -1;
}
bool IsRoot(node *x) {
	return (x->fa == NIL) || (x->fa->ch[0] != x && x->fa->ch[1] != x);
}
void SetChild(node *x, node *y, int d) {
	x->ch[d] = y;
	if( y != NIL ) y->fa = x;
}
node *NewNode(int k, int id, int s) {
	ncnt++;
	ncnt->key = k, ncnt->id = id, ncnt->s = ncnt->siz1 = s;
	ncnt->fa = ncnt->ch[0] = ncnt->ch[1] = NIL;
	ncnt->mx = ncnt;
	return ncnt;
}
void PushDown(node *x) {
	if( x->rev ) {
		swap(x->ch[0], x->ch[1]);
		if( x->ch[0] != NIL ) x->ch[0]->rev ^= 1;
		if( x->ch[1] != NIL ) x->ch[1]->rev ^= 1;
		x->rev = 0;
	}
}
void PushUp(node *x) {
	if( x->key > x->ch[0]->mx->key && x->key > x->ch[1]->mx->key )
		x->mx = x;
	else if( x->ch[0]->mx->key > x->ch[1]->mx->key )
		x->mx = x->ch[0]->mx;
	else x->mx = x->ch[1]->mx;
	x->siz1 = x->s + x->ch[0]->siz1 + x->ch[1]->siz1 + x->siz2;
}
void Rotate(node *x) {
	node *y = x->fa;
	PushDown(y), PushDown(x);
	int d = (y->ch[1] == x);
	if( IsRoot(y) ) x->fa = y->fa;
	else SetChild(y->fa, x, y->fa->ch[1] == y);
	SetChild(y, x->ch[!d], d);
	SetChild(x, y, !d);
	PushUp(y);
}
void Splay(node *x) {
	PushDown(x);
	while( !IsRoot(x) ) {
		node *y = x->fa;
		if( IsRoot(y) )
			Rotate(x);
		else {
			if( (y->fa->ch[1] == y) == (y->ch[1] == x) )
				Rotate(y);
			else Rotate(x);
			Rotate(x);
		}
	}
	PushUp(x);
}
void Access(node *x) {
	node *y = NIL;
	while( x != NIL ) {
		Splay(x);
		x->siz2 += x->ch[1]->siz1;
		x->ch[1] = y;
		x->siz2 -= x->ch[1]->siz1;
		PushUp(x);
		y = x, x = x->fa;
	}
}
void MakeRoot(node *x) {
	Access(x), Splay(x);
	x->rev ^= 1;
}
void Link(node *x, node *y) {
	MakeRoot(x); MakeRoot(y);
	x->fa = y; y->siz2 += x->siz1;
}
void Cut(node *x, node *y) {
	MakeRoot(x);
	Access(y), Splay(y);
	y->ch[0] = x->fa = NIL;
	PushUp(y);
}
node *FindRoot(node *x) {
	Access(x), Splay(x);
	node *ret = x;
	while( ret->ch[0] != NIL )
		ret = ret->ch[0];
	PushUp(ret);
	return ret;
}
node *LCA(node *x, node *y) {
	Access(x), Splay(x);
	Splay(y);
	while( y->fa != NIL ) {
		y = y->fa;
		Splay(y);
	}
	return y;
}
node *QueryMAX(node *x, node *y) {
	node *z = LCA(x, y);
	node *ret = z;
	Access(x), Splay(z);
	if( z->ch[1]->mx->key > ret->key )
		ret = z->ch[1]->mx;
	Access(y), Splay(z);
	if( z->ch[1]->mx->key > ret->key )
		ret = z->ch[1]->mx;
	return ret;
}
int n, m, stot;
void Debug() {
	for(it=Set.begin();it!=Set.end();it++)
		printf("(%d, %d, %d)\n", it->u, it->v, it->w);
}
int main() {
	Init();
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++)
		ad[i] = NewNode(-1, -1, 1);
	stot = n;
	for(int i=1;i<=m;i++) {
		e[i].id = i;
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
		if( e[i].u == e[i].v ) continue;
		ad[n+i] = NewNode(e[i].w, i, 0);
		Set.insert(e[i]);
		if( FindRoot(ad[e[i].u]) == FindRoot(ad[e[i].v]) ) {
			node *p = QueryMAX(ad[e[i].u], ad[e[i].v]); Splay(p);
			if( p->key > e[i].w ) {
				Set.erase(e[p->id]);
				Cut(p, ad[e[p->id].u]), Cut(p, ad[e[p->id].v]);
				Link(ad[e[i].u], ad[n+i]), Link(ad[e[i].v], ad[n+i]);
			}
			else Set.erase(e[i]);
		}
		else {
			MakeRoot(ad[e[i].u]), MakeRoot(ad[e[i].v]);
			if( ad[e[i].u]->siz1 % 2 == 1 && ad[e[i].v]->siz1 % 2 == 1 ) stot -= 2;
			Link(ad[e[i].u], ad[n+i]), Link(ad[e[i].v], ad[n+i]);
		}
		
		if( stot == 0 ) {
			it = Set.end(); it--;
			while( true ) {
				node *p = ad[n+it->id], *q = ad[e[it->id].u], *r = ad[e[it->id].v];
				MakeRoot(p); Access(q); Access(r);
				if( q->siz1 & 1 ) break;
				Access(q);
				if( r->siz1 & 1 ) break;
				Set.erase(it);
				it = Set.end(); it--;
			}
			it = Set.end(); it--;
			printf("%d\n", it->w);
		}
		else printf("-1\n");
	}
}