#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define pb push_back
#define rs resize
#define mk make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase
#define fi0(x) memset(x, 0, sizeof(x))
#define y1 adjf

int n, m;
vector<int> a;

struct node{
	node *l, *r;
	int val;
};

node * build(int l, int r, bool isor){
	node * v = new node;
	if(l == r){v->val = a[l]; ret v;}
	int mid = (l + r) >> 1;
	v->l = build(l, mid, !isor);
	v->r = build(mid + 1, r, !isor);
	if(isor){v->val = v->l->val | v->r->val;}
	else{v->val = v->l->val ^ v->r->val;}
	ret v;
}

void upd(node * v, int l, int r, int pos, int nv, bool isor){
	if(l == r){v->val = nv; ret;}
	int mid = (l + r) >> 1;
	if(pos <= mid)
		upd(v->l, l, mid, pos, nv, !isor);
	else
		upd(v->r, mid + 1, r, pos, nv, !isor);
	if(isor){v->val = v->l->val | v->r->val;}
	else{v->val = v->l->val ^ v->r->val;}
}

int main(){
	scanf("%d%d", &n, &m);
	bool fv = false;
	if(n&1){fv = true;}
	n = 1 << n;
	a.rs(n);
	F(i, 0, n)
		scanf("%d", &a[i]);
	node * root = build(0, n - 1, fv);
	F(i, 0, m){
		int pos, x;
		scanf("%d%d", &pos, &x);
		pos--;
		upd(root, 0, n - 1, pos, x, fv);
		printf("%d\n", root->val);
	}
	ret 0;
}