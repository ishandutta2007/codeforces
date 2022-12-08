//hello guys
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define nil mem
#define mp make_pair
const int mxv = 1000000; 
using Key = int; 
struct Node {int fit; Node *l, *r; Key key; Key add; 
} mem[mxv]; 
int sz; using ptr = Node*;
#define NEW(arg...) new(mem+ ++sz)Node{rand(),nil,nil,arg}
ptr down(ptr x) {
	if (x->add > 0) {
		(x->l)->add += x->add; 
		(x->r)->add += x->add; 
		x->key += x->add; 
		x->add = 0; 
	} 
	return x;
}
pair<ptr,ptr> split(ptr x, Key key) {
	ptr t; if (x == nil) return {nil, nil};
	x = down(x);
	return x->key >= key // 
		? (tie(t, x->l) = split(x->l, key), mp(t, x))
		: (tie(x->r, t) = split(x->r, key), mp(x, t));
}
ptr merge(ptr x, ptr y) {
	if (x == nil) return y;
	if (y == nil) return x;
	return x->fit < y->fit // rand() % (X.cnts + Y.cnts) < X.cnts
		? (x = down(x), x->r = merge(x->r, y), x)
		: (y = down(y), y->l = merge(x, y->l), y);
}
ptr del(ptr x) {
	if (x->l == nil) return x->r; 
	else {
		x->l = del(x->l); 
		return x; 
	}
}
int countnum(ptr x) {
	if (x == nil) return 0; 
	return countnum(x->l)+countnum(x->r)+1; 
}


int n; 

int main() {
	*nil = {0, nil, nil};
	scanf( "%d", &n ); 
	ptr T = NEW(0,0);
	for (int i = 1; i <= n; ++i) {
		int l, r; 
		scanf("%d%d", &l, &r); 
		ptr a, b, c; 
		tie(a,b) = split(T, l); 
		tie(b,c) = split(b, r); 
		if (c != nil) c = del(c); 
		if (b != nil) b->add++; 
		b = merge(NEW(l,0),b); 
		T = merge(merge(a,b),c);  
	}
	cout<<countnum(T)-1<<endl; 
}