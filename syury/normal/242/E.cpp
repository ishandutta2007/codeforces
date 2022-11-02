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
#define y1 adjf

const int NB = 20;

struct bitm{
	int cnt[NB];
	bitm(){
		fi0(cnt);
	}
};

struct node{
	bitm val;
	int x = 0;
	node *l = NULL, *r = NULL;
	int sz;
	void ap(int y){
		F(i, 0, NB)
			if((1 << i)&y){
				val.cnt[i] = sz - val.cnt[i];
			}
	}
};

int n;
vector<int> a;
bitm zero;

bitm operator + (const bitm & a, const bitm & b){
	bitm res;
	F(i, 0, NB)
		res.cnt[i] = a.cnt[i] + b.cnt[i];
	ret res;
}

node * build(int l, int r){
	node * v = new node;
	v->sz = r - l + 1;
	if(l == r){
		F(i, 0, NB)
			if(a[l]&(1 << i)){v->val.cnt[i] = 1;}
		ret v;
	}
	int mid = (l + r) >> 1;
	v->l = build(l, mid);
	v->r = build(mid + 1, r);
	v->val = v->l->val + v->r->val;
	ret v;
}

void push(node * v){
	if(v->x == 0)ret;
	//v->ap();
	if(v->l){v->l->ap(v->x); v->l->x ^= v->x;}
	if(v->r){v->r->ap(v->x); v->r->x ^= v->x;}
	v->x = 0;
}

void upd(node * v, int l, int r, int ul, int ur, int nv){
	if(ul > ur)ret;
	push(v);
	if(l == ul && r == ur){v->ap(nv); v->x ^= nv; ret;}
	int mid = (l + r) >> 1;
	upd(v->l, l, mid, ul, min(ur, mid), nv);
	upd(v->r, mid + 1, r, max(ul, mid + 1), ur, nv);
	v->val = v->l->val + v->r->val;
}

bitm get(node * v, int l, int r, int ul, int ur){
	if(ul > ur)ret zero;
	push(v);
	if(l == ul && r == ur)ret v->val;
	int mid = (l + r) >> 1;
	bitm ans;
	ans = ans + get(v->l, l, mid, ul, min(ur, mid));
	ans = ans + get(v->r, mid + 1, r, max(ul, mid + 1), ur);
	ret ans;
}

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &n);
	a.rs(n);
	F(i, 0, n)scanf("%d", &a[i]);
	node * root = build(0, n - 1);
	int m;
	scanf("%d", &m);
	F(i, 0, m){
		int tp, l, r;
		scanf("%d%d%d", &tp, &l, &r); l--; r--;
		if(tp == 1){
			bitm ans = get(root, 0, n - 1, l, r);
			lint out = 0ll;
			F(i, 0, 20){
				out += ans.cnt[i] * 1ll * (1 << i);
			}
			printf("%lld\n", out);
		}
		else{
			int x;
			scanf("%d", &x);
			upd(root, 0, n - 1, l, r, x);
		}
	}
	ret 0;
}