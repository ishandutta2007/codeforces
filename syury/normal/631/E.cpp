#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll inf = 1ll<<62;

struct Line{
	ll k, b;
	Line(){}
	Line(ll _k, ll _b):k(_k),b(_b){}
	ll operator () (const ll & x)const{return k * x + b;}
};

struct LiChao{
	//finds minimum
	vector<Line> t;
	int n;
	LiChao(){}
	LiChao(int _n):n(_n){t.resize(4*n + 3); t.assign(4*n + 3, Line(0, inf));}
	void add_line(int v, int l, int r, Line ln){
		int mid = (l + r)/2;
		bool le = ln(l) < t[v](l), mi = ln(mid) < t[v](mid);
		if(mi)swap(t[v], ln);
		if(l == r)return;
		if(le != mi)add_line(2*v, l, mid, ln);
		else add_line(2*v + 1, mid + 1, r, ln);
	}
	void add_line(Line ln){add_line(1, 0, n - 1, ln);}
	ll eval(int v, int l, int r, ll x){
		if(l == r)return t[v](x);
		int mid = (l + r)/2;
		if(x <= mid)return min(t[v](x), eval(2*v, l, mid, x));
		else return min(t[v](x), eval(2*v + 1, mid + 1, r, x));
	}
	ll eval(ll x){return eval(1, 0, n - 1, x);}
};

struct LiChaoDynamic{
	//finds minimum
	struct node{
		Line val;
		node *l = NULL, *r = NULL;
		node(){}
		node(Line _val):val(_val){}
	};
	node * root = NULL;
	ll MINX, MAXX;
	LiChaoDynamic(){}
	LiChaoDynamic(ll _mi, ll _ma):MINX(_mi),MAXX(_ma){}
	void add_line(node* & v, ll l, ll r, Line ln){
		if(v == NULL){v = new node(ln);}
		ll mid = (l + r < 0) ? (l + r - 1)/2 : (l + r)/2;
		bool le = ln(l) < v->val(l), mi = ln(mid) < v->val(mid);
		if(mi){swap(v->val, ln);}
		if(l == r)return;
		if(le != mi)add_line(v->l, l, mid, ln);
		else add_line(v->r, mid + 1, r, ln);
	}
	void add_line(Line ln){add_line(root, MINX, MAXX, ln);}
	ll eval(node* v, ll l, ll r, ll x){
		if(v == NULL)return inf;
		if(l == r)return v->val(x);
		ll mid = (l + r < 0) ? (l + r - 1)/2 : (l + r)/2;
		if(x <= mid)return min(v->val(x), eval(v->l, l, mid, x));
		else return min(v->val(x), eval(v->r, mid + 1, r, x));
	}
	ll eval(ll x){return eval(root, MINX, MAXX, x);}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<int> a;
	int n;
	cin >> n;
	a.resize(n);
	for(int i = 0; i < n; i++)cin >> a[i];
	LiChaoDynamic t(-1e9-1, 1e9+1);
	ll pref = 0;
	ll ans = 0;
	for(int i = 0; i < n; i++)ans += a[i] * 1ll * (i+1);
	ll alls = ans;
	ll su = 0;
	for(int i = 0; i < n; i++){
		ll curr = -t.eval(a[i]) - a[i] * 1ll * (i + 1) + alls + su;
		ans = max(ans, curr);
		t.add_line(Line(-(i+1), su));
		su += a[i];
		pref += a[i] * 1ll * (i + 1);
	}
	t = LiChaoDynamic(-1e9-1, 1e9+1);
	pref = 0; su = 0;
	for(int i = n - 1; i >= 0; i--){
		ll curr = -t.eval(a[i]) - a[i] * 1ll * (i + 1) - su + alls;
		ans = max(ans, curr);
		t.add_line(Line(-(i+1), -su));
		su += a[i];
		pref += a[i] * 1ll * (i + 1);
	}
	cout << ans;
	return 0;
}