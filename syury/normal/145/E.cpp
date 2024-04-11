#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define I(x, a) for(auto x : a)
#define F(i, l, r) for(auto i = l; i < r; ++i)
#define E(i, l, r) for(auto i = l; i <= r; ++i)
#define DF(i, l, r) for(auto i = l; i >= r; --i)
#define clean(a) memset((a),0,sizeof (a))
#define sync ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) (x).begin(),(x).end()
#define ret return
#define cont continue
#define brk break
#define ins insert

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef long double dbl;

struct node{
	int ans, mn;
	int add = 0;
	int pushmul = 1;
	void apply(int cadd, int mul){
		if(mul == -1){
			int tmp = mn;
			mn = -ans + cadd;
			ans = -tmp + cadd;
			add = -add + cadd;
		}
		else{
			mn = mn + cadd;
			ans = ans + cadd;
			add += cadd;
		}
		pushmul *= mul;
	}
};

const int maxn = (int)1e6 + 6;

node t[4*maxn];
int a[maxn];
int c0[maxn], c1[maxn];
int n, m;

void push(int v){
	t[2*v].apply(t[v].add, t[v].pushmul);
	t[2*v+1].apply(t[v].add, t[v].pushmul);
	t[v].add = 0;
	t[v].pushmul = 1;
}

void add(int v, int l, int r, int ul, int ur, int a0, int a1, int coeff){
	if(ul > ur)ret;
	if(l != r)push(v);
	if(l == ul && r == ur){
		t[v].apply(a0 + a1, coeff);
		ret;
	}
	int mid = (l + r)/2;
	add(2*v, l, mid, ul, min(ur, mid), a0, a1, coeff);
	add(2*v + 1, mid + 1, r, max(ul, mid + 1), ur, a0, a1, coeff);
	t[v].ans = max(t[2*v].ans, t[2*v+1].ans);
	t[v].mn = min(t[2*v].mn, t[2*v+1].mn);
}

int get(int v, int l, int r, int pos){
	if(l == r)ret t[v].ans;
	push(v);
	int mid = (l + r)/2;
	if(pos <= mid)
		ret get(2*v, l, mid, pos);
	else
		ret get(2*v + 1, mid + 1, r, pos);
	t[v].ans = max(t[2*v].ans, t[2*v+1].ans);
	t[v].mn = min(t[2*v].mn, t[2*v+1].mn);
}

void build(int v, int l, int r){
	if(l == r){
		t[v].ans = t[v].mn = c0[l] + c1[l];
		ret;
	}
	int mid = (l + r)/2;
	build(2*v, l, mid);
	build(2*v + 1, mid + 1, r);
	t[v].ans = max(t[2*v].ans, t[2*v+1].ans);
	t[v].mn = min(t[2*v].mn, t[2*v+1].mn);
}

signed main(){
	sync;
	cin >> n >> m;
	F(i, 0, n){
		char c;
		cin >> c;
		if(c == '4')a[i] = 0;
		else a[i] = 1;
	}
	int curr = 0;
	F(i, 0, n + 1){
		c0[i] = curr;
		if(i != n)curr += a[i] == 0 ? 1 : 0;
	}
	curr = 0;
	DF(i, n, 0){
		c1[i] = curr;
		if(i)curr += a[i-1];
	}
	build(1, 0, n);
	F(i, 0, m){
		string tp;
		cin >> tp;
		if(tp == "count"){cout << t[1].ans << '\n'; cont;}
		int l, r;
		cin >> l >> r;
		--l; --r;
		++r;
		auto a0 = get(1, 0, n, l), a1 = get(1, 0, n, r);
//		int a0 = pl.X + pl.Y, a1 = pr.X + pr.Y;
		add(1, 0, n, l, r, a0, a1, -1);
		add(1, 0, n, 0, l - 1, -a0, a1, 1);
		add(1, 0, n, r + 1, n, a0, -a1, 1);
	}
	ret 0;
}