#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
using pii = pair<int,int>; 
using db = double; 
using vi = vector<int>; 
#define fir first
#define sec second
#define pb push_back
#define lowbit(x) ((x)&(-(x))) 

const int maxn = 200006; 
const ll oo = 0x3f3f3f3f3f3f3f3fll; 

struct val {
	ll add, mind; 
}; 

struct Seg {
	val e[maxn*4]; 
	void clear() {
		memset(e, 0, sizeof(e)); 
	}
	void upd(int T) {
		e[T].mind = min(e[T*2].mind+e[T*2].add, e[T*2+1].mind+e[T*2+1].add); 
	}
	void down(int T) {
		e[T*2].add += e[T].add; 
		e[T*2+1].add += e[T].add; 
		e[T].mind += e[T].add; 
		e[T].add = 0; 
	}
	void add(int T, int l, int r, int a, int b, ll c) {
		if (a <= l && b >= r) {
			e[T].add += c; 
			return; 
		}
		int m = (l+r)/2; 
		down(T); 
		if (a <= m) add(T*2,l,m,a,b,c); 
		if (b > m) add(T*2+1,m+1,r,a,b,c); 
		upd(T); 
	}
	ll ask(int T, int l, int r, int a, int b) {
		if (a <= l && b >= r) return e[T].mind +e[T].add; 
		int m = (l+r)/2; 
		down(T); 
		ll ret = oo; 
		if (a <= m) ret = min(ret, ask(T*2,l,m,a,b)); 
		if (b > m) ret = min(ret, ask(T*2+1,m+1,r,a,b)); 
		return ret; 
	}
}S; 

vector<pair<int,ll>> e[maxn]; 
int n, q; 
ll f[maxn]; 
int be[maxn], en[maxn]; 
int tot; 
int a[maxn*2], b[maxn*2], c[maxn*2]; 

void dfs(int x, ll l) {
	tot++; be[x]=tot; 
	S.add(1,1,n,tot,tot,l+f[x]); 
	for (auto p : e[x]) 
		dfs(p.fir, l+p.sec);
	en[x] = tot;  
}

ll path(int x) {
	return S.ask(1,1,n,be[x],be[x])-f[x]; 
}

int main() {
	scanf( "%d%d", &n, &q ); 
	for (int i = 1; i <= n-1; ++i) {
		scanf( "%d%d%d", &a[i], &b[i], &c[i] ); 
		e[a[i]].pb({b[i],c[i]}); 
	}
	for (int i = n; i <= 2*n-2; ++i) {
		scanf( "%d%d%d", &a[i], &b[i], &c[i] ); 
		f[a[i]] = c[i]; 
	}
	tot = 0; 
	dfs(1, 0); 
	for (int i = 1; i <= q; ++i) {
		int op, x, y; 
		scanf( "%d%d%d", &op, &x, &y ); 
		if (op == 1) {
			if (x <= n-1) 
				S.add(1,1,n,be[b[x]],en[b[x]],y-c[x]);
			else {
				S.add(1,1,n,be[a[x]],be[a[x]],y-c[x]); 
				f[a[x]] = y; 
			}
			c[x] = y; 
		}
		else {
			ll px = path(x), py = path(y); 
			if (be[y] >= be[x] && en[y] <= en[x]) 
				printf( "%lld\n", py-px ); 
			else printf( "%lld\n", S.ask(1,1,n,be[x],en[x])-px+py ); 
		}
	}
}