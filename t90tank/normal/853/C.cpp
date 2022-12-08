#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second
const int maxn = 200006; 

#define lowbit(x) ((x)&(-(x)))

struct Arr {
	int g[maxn]; 
	int n; 
	void clear(int n) {
		this->n = n; 
		fill(g, g+n+1, 0); 
	}
	void ud(int x) {
		for (int i = x; i <= n; i += lowbit(i)) 
			g[i]++; 
	}
	int ask(int x) {
		int ret = 0; 
		for (int i = x; i >= 1; i -= lowbit(i))
			ret += g[i]; 
		return ret; 
	}
}g; 

ll val[maxn]; 
ll ans[maxn]; 

struct data {
	int x, y, d; 
	bool operator<(const data &b) const {
		return tie(x,d) < tie(b.x,b.d); 
	}
}; 

int n, Q; 
int p[maxn]; 
int l[maxn], d[maxn], r[maxn], u[maxn]; 
vector<data> q; 
void solve() {
	sort(q.begin(), q.end()); 
	g.clear(n); 
	for (auto i : q) {
		if (i.d == 0) g.ud(i.y); 
		else val[i.d] = g.ask(i.y); 
	}
	//for (auto i : q) printf( "%d,%d,%d\n", i.x, i.y, i.d ); 
	//cout<<val[1]<<endl; 
}

ll sum(ll n) {
	return n * (n-1) / 2; 
}

int main() {
	scanf( "%d%d", &n, &Q ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &p[i] ); 
	for (int i = 1; i <= Q; ++i) {
		scanf( "%d%d%d%d", &l[i], &d[i], &r[i], &u[i] ); 
		ans[i] = sum(n) - sum(l[i]-1) - sum(n-r[i]) - sum(d[i]-1) - sum(n-u[i]); 
	}
	
	q.clear(); 
	for (int i = 1; i <= n; ++i) q.pb({p[i],i,0}); 
	for (int i = 1; i <= Q; ++i) q.pb({d[i]-1,l[i]-1,i}); 
	solve(); 
	for (int i = 1; i <= Q; ++i) ans[i] += sum(val[i]); 
	q.clear(); 
	for (int i = 1; i <= n; ++i) q.pb({n-p[i]+1,i,0}); 
	for (int i = 1; i <= Q; ++i) q.pb({n-u[i],l[i]-1,i}); 
	solve(); 
	for (int i = 1; i <= Q; ++i) ans[i] += sum(val[i]); 
	q.clear(); 
	for (int i = 1; i <= n; ++i) q.pb({p[i],n-i+1,0}); 
	for (int i = 1; i <= Q; ++i) q.pb({d[i]-1,n-r[i],i}); 
	solve(); 
	for (int i = 1; i <= Q; ++i) ans[i] += sum(val[i]); 
	q.clear(); 
	for (int i = 1; i <= n; ++i) q.pb({n-p[i]+1,n-i+1,0}); 
	for (int i = 1; i <= Q; ++i) q.pb({n-u[i],n-r[i],i}); 
	solve(); 
	for (int i = 1; i <= Q; ++i) ans[i] += sum(val[i]); 
	
	for (int i = 1; i <= Q; ++i) 
		printf( "%lld\n", ans[i] ); 
}