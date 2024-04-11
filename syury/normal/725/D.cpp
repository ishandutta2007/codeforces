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
#define y1 adjf
#define ws wejgnjn
#define left fhgfj

const lint inf = 1e18 + 40;

int n;
vector<pair<lint, lint> > a;
vector<lint> d;
lint t0, w0;
int best = 1e9;

auto comp = [](const pair<lint, lint> & f, const pair<lint, lint> & s)->bool{
	if(f.X > s.X)ret true;
	if(f.X == s.X && f.Y > s.Y)ret true;
	ret false;
};

struct node{
	pair<lint, int> val;
	node *l, *r;
};

node * root;

node * build(int l, int r){
	node * v = new node;
	if(l == r){v->val = mk(d[l], l); ret v;}
	int mid = (l + r) >> 1;
	v->l = build(l, mid);
	v->r = build(mid + 1, r);
	if(v->l->val.X < v->r->val.X){v->val = v->l->val;}
	else{v->val = v->r->val;}
	ret v;
}

pair<lint, int> get(node * v, int l, int r, int ul, int ur){
	if(ul > ur){ret mk(inf, -1);}
	if(l == ul && r == ur)ret v->val;
	int mid = (l + r) >> 1;
	pair<lint, int> al, ar;
	al = get(v->l, l, mid, ul, min(ur, mid));
	ar = get(v->r, mid + 1, r, max(ul, mid + 1), ur);
	if(al.X < ar.X)ret al;
	else ret ar;
}

void upd(node * v, int l, int r, int pos){
	if(l == r){v->val = mk(inf, -1); ret;}
	int mid = (l + r) >> 1;
	if(pos <= mid)
		upd(v->l, l, mid, pos);
	else
		upd(v->r, mid + 1, r, pos);
	if(v->l->val.X < v->r->val.X){v->val = v->l->val;}
	else{v->val = v->r->val;}

}

int main(){
//	freopen("input.txt", "r", stdin);
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
	scanf("%d", &n);
	n--;
	scanf("%lld%lld", &t0, &w0);
	a.rs(n); d.rs(n);
	F(i, 0, n){
		scanf("%lld%lld", &a[i].X, &a[i].Y);
	}
	sort(all(a));
	reverse(all(a));
	F(i, 0, n)
		d[i] = a[i].Y - a[i].X + 1;
	root = build(0, n - 1);
	int pos = 0;
	int gr = 0;
	int eq = 0;
	while(pos < n && a[pos].X >= t0){
		if(a[pos].X > t0)gr++;
		else eq++;
		pos++;
	}
	best = gr + 1;
	while(true){
		pair<lint, int> cv = get(root, 0, n - 1, 0, pos - 1);
		if(cv.Y == -1)brk;
		if(t0 < cv.X)brk;
		t0 -= cv.X;
		upd(root, 0, n - 1, cv.Y);
		gr = gr + eq - 1;
		eq = 0;
		while(pos < n && a[pos].X >= t0){
			if(a[pos].X > t0)gr++;
			else eq++;
			pos++;
		}
		best = min(best, gr + 1);
	}
	printf("%d", best);
	ret 0;
}