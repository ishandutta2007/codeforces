#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define I(i, a) for(auto i : a)
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
#define finf(x) memset(x, 127, sizeof(x))
#define y1 adjf
#define tm afhdhn

struct node{
	node *l = 0, *r = 0;
	int val;
};

struct segtree{
	node * root;
	int sz;
	node * build(int l, int r){
		node * v = new node;
		v->val = -1;
		if(l == r)ret v;
		int mid = (l + r) >> 1;
		v->l = build(l, mid);
		v->r = build(mid + 1, r);
		ret v;
	}
	void init(int n){
		sz = n;
		root = build(0, n - 1);
	}
	void upd(node * v, int l, int r, int pos, int nv){
		if(l == r){v->val = max(v->val, nv); ret;}
		int mid = (l + r) >> 1;
		if(pos <= mid)upd(v->l, l, mid, pos, nv);
		else upd(v->r, mid + 1, r, pos, nv);
		v->val = max(v->l->val, v->r->val);
	}
	int get(node * v, int l, int r, int ul, int ur){
		if(ul > ur)ret -1;
		if(l == ul && r == ur)ret v->val;
		int mid = (l + r) >> 1;
		ret max(get(v->l, l, mid, ul, min(ur, mid)), get(v->r, mid + 1, r, max(ul, mid + 1), ur));
	}
	void upd(int pos, int nv){
		upd(root, 0, sz - 1, pos, nv);
	}
	int get(int l, int r){
		ret get(root, 0, sz - 1, l, r);
	}
};

const int inf = 1e9;

int n;
vector<int> a;
segtree up, rn;
vector<int> kl;

int main(){
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &n); a.rs(n);
	F(i, 0, n)scanf("%d", &a[i]);
	up.init(n); rn.init(n);
	kl.rs(n); kl.asg(n, inf);
	int ans = 0;
	F(i, 0, n){
		int pos = up.get(a[i] - 1, n - 1);
		up.upd(a[i] - 1, i);
		if(pos == -1){
			rn.upd(i, kl[i]); cont;
		}
		int kt; 
		if(pos < i - 1)kt = rn.get(pos + 1, i - 1); else kt = 0;
		if(kt != inf)kl[i] = kt + 1;
		rn.upd(i, kl[i]);
		if(kl[i] != inf)ans = max(ans, kl[i]);
	}
	printf("%d", ans);
	ret 0;
}