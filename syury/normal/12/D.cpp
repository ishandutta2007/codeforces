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
#define tm dhgdg

int szf = 0, szsf = 0, szss = 0;

char mem[220 * 1000 * 1000];
size_t mem_ptr = 0;

inline void* operator new(size_t len){
	mem_ptr += len;
	ret mem + mem_ptr - len;
}

inline void operator delete(void*){}

struct node{
	int val = 0;
	node *l, *r;
};

vector<pair<int, pair<int, int> > > a;
int n;
set<int> ss;
map<int, int> mp;

node * root;

node * build(int l, int r){
	node * v = new node;
	if(l == r)ret v;
	int mid = (l + r) >> 1;
	v->l = build(l, mid);
	v->r = build(mid + 1, r);
	ret v;
}

int get(node * v, int l, int r, int ul, int ur){
	if(ul > ur)ret 0;
	if(ul == l && ur == r)ret v->val;
	int mid = (l + r) >> 1;
	ret max(get(v->l, l, mid, ul, min(ur, mid)), get(v->r, mid + 1, r, max(ul, mid + 1), ur));
}

void upd(node * v, int l, int r, int pos, int nv){
	v->val = max(v->val, nv);
	if(l == r)ret;
	int mid = (l + r) >> 1;
	if(pos <= mid)upd(v->l, l, mid, pos, nv);
	else upd(v->r, mid + 1, r, pos, nv);
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &n); a.rs(n);
	F(i, 0, n){scanf("%d", &a[i].X); ss.ins(a[i].X);}
	I(v, ss)mp[v] = szf++;
	F(i, 0, n)a[i].X = mp[a[i].X];
	ss.clear(); mp.clear();
	F(i, 0, n){scanf("%d", &a[i].Y.X); ss.ins(a[i].Y.X);}
	I(v, ss)mp[v] = szsf++;
	F(i, 0, n)a[i].Y.X = mp[a[i].Y.X];
	ss.clear(); mp.clear();
	F(i, 0, n)scanf("%d", &a[i].Y.Y), ss.ins(a[i].Y.Y);
	I(v, ss)mp[v] = szss++;
	F(i, 0, n)a[i].Y.Y = mp[a[i].Y.Y];
	ss.clear(); mp.clear();
	sort(all(a));
	lint ans = 0ll;
	int le = n - 1;
	int prv = a[n - 1].X;
	root = build(0, szsf - 1);
	Df(i, n - 1, -1){
		if(prv != a[i].X){
			Df(j, le, i){
				upd(root, 0, szsf - 1, a[j].Y.X, a[j].Y.Y);
			}
			le = i; prv = a[i].X;
		}
		if(get(root, 0, szsf - 1, a[i].Y.X + 1, szsf - 1) > a[i].Y.Y)ans++;
	}
	printf("%lld", ans);
	ret 0;
}