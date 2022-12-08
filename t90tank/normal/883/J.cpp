#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int maxn = 100006;

int n, m;
int a[maxn];
ll s[maxn]; 
pair<ll,ll> q[maxn]; 
vector<pair<ll,ll>> p;

struct Val {
	ll add, mind; 
}; 

struct SegTree { 
	Val e[maxn*5]; 
	void up(int T) {
		e[T].mind = e[T].add + min(e[T*2].mind, e[T*2+1].mind); 
	}
	
	void down(int T) {
		e[T*2].add += e[T].add; 
		e[T*2].mind += e[T].add; 
		e[T*2+1].add += e[T].add; 
		e[T*2+1].mind += e[T].add; 
		e[T].add = 0; 
	}
	
	void build(int T, int l, int r) {
		e[T].add = 0; 
		if (l == r) {
			e[T].mind = s[l]; 
			return; 
		}
		int m = (l + r) / 2; 
		build(T*2, l, m); 
		build(T*2+1, m+1, r); 
		up(T); 
	}
	
	void update(int T, int l, int r, int a, int b, ll c) {
		if (a <= l && b >= r) {
			e[T].add += c; 
			e[T].mind += c; 
			return; 
		}
		int m = (l + r) / 2; 
		down(T); 
		if (a <= m) update(T*2, l, m, a, b, c);
		if (b > m) update(T*2+1, m+1, r, a, b, c); 
		up(T); 
	}
	
	ll getmin(int T, int l, int r, int a, int b) {
		if (a <= l && b >= r) return e[T].mind; 
		ll ret = 0x3f3f3f3f3f3f3f3fll; 
		int m = (l + r) / 2; 
		down(T); 
		if (a <= m) ret = min(ret, getmin(T*2, l, m, a, b));
		if (b > m) ret = min(ret, getmin(T*2+1, m+1, r, a, b)); 
		return ret; 
	}
}S; 

int main() {
	scanf( "%d%d", &n, &m ); 
	s[0] = 0; 
	for (int i = 1; i <= n; ++i) {
		scanf( "%d", &a[i] ); 
		s[i] = s[i-1] + a[i]; 
	}
	for (int i = 1; i <= m; ++i) 
		scanf("%lld", &q[i].fir); 
	for (int i = 1; i <= m; ++i) 
		scanf("%lld", &q[i].sec); 
	sort(q+1, q+m+1); 
	int j = 1; 
	p.clear(); 
	for (int i = n; i >= 1; --i) 
		while (j <= m && q[j].fir <= a[i]) {
			p.pb({q[j].sec, i}); 
			j++; 
		}
	sort(p.begin(), p.end()); 
	S.build(1,1,n); 
	int ans = 0; 
	for (auto i : p) 
		if (S.getmin(1,1,n,i.sec,n) >= i.fir) {
			ans++; 
			S.update(1,1,n,i.sec,n,-i.fir); 
		}
	cout<<ans<<endl; 
}