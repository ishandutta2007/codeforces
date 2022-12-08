#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
using pii = pair<int,int>; 
using db = double; 
using vi = vector<int>; 
using vl = vector<ll>; 
#define fir first
#define sec second
#define pb push_back
#define lowbit(x) ((x)&(-(x))) 

const int maxn = 500006; 
const ll oo = 0x3f3f3f3f3f3f3f3fll; 

struct node {
	ll add, mind; 
}e[maxn*4]; 
struct data {
	int l, r, id; 
};
vector< pair<int,ll> > q[maxn]; 
ll d[maxn]; 
vector<data> que[maxn]; 
ll ans[maxn]; 
int en[maxn]; 
int n, m;

void down(int T) {
	e[T*2].add += e[T].add; 
	e[T*2+1].add += e[T].add; 
	e[T*2].mind += e[T].add; 
	e[T*2+1].mind += e[T].add; 
	e[T].add = 0; 
}

void up(int T) {
	e[T].mind = min(e[T*2].mind, e[T*2+1].mind)+e[T].add; 
}

void add(int T, int l, int r, int a, int b, ll c) {
	if (a <= l && b >= r) {
		e[T].add += c; 
		e[T].mind += c; 
		return; 
	}
	int m = (l+r)/2; 
	down(T); 
	if (a <= m) add(T*2,l,m,a,b,c); 
	if (b > m) add(T*2+1,m+1,r,a,b,c); 
	up(T); 
}

ll getmin(int T, int l, int r, int a, int b) {
	if (a <= l && b >= r) {
		//cout<<l<<' '<<r<<' '<<e[T].mind<<endl; 
		return e[T].mind; 
	}
	int m = (l+r)/2; 
	ll ret = oo;
	down(T);  
	if (a <= m) ret = min(ret, getmin(T*2,l,m,a,b)); 
	if (b > m) ret = min(ret, getmin(T*2+1,m+1,r,a,b)); 
	return ret; 
}

void dfs(int x) {
	en[x] = x; 
	for (auto i : q[x]) {
		d[i.fir] = d[x] + i.sec; 
		dfs(i.fir); 
		en[x] = en[i.fir]; 
	}
}

void solve(int x, int f) {
	ll tmp = (-d[x])*2-(-d[f])*2; 
	add(1, 1, n, x, en[x], tmp); 
	for (auto i : que[x]) {
		ans[i.id] = getmin(1,1,n,i.l,i.r)+d[x]; 
	}
	for (auto i : q[x]) solve(i.fir, x); 
	add(1, 1, n, x, en[x], -tmp); 
}

int main() { 
	scanf( "%d%d", &n, &m ); 
	for (int i = 2; i <= n; ++i) {
		int x, w; 
		scanf( "%d%d", &x, &w ); 
		q[x].pb({i,w}); 
	}
	for (int i = 1; i <= m; ++i) {
		int l, r, v; 
		scanf( "%d%d%d", &v, &l, &r ); 
		que[v].pb({l,r,i}); 
	}
	memset(e, 0, sizeof(e)); 
	d[0] = 0; 
	dfs(1); 
	for (int i = 1; i <= n; ++i) 
		if (q[i].empty()) add(1,1,n,i,i,d[i]); 
		else add(1,1,n,i,i,oo); 
	d[0] = 0; 
	solve(1,0); 
	for (int i = 1; i <= m; ++i) printf( "%lld\n", ans[i] ); 
}