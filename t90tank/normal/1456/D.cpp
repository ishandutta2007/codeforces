#include <bits/stdc++.h>
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
using namespace std; 
using ll = long long;

const int maxn = 5006; 

struct data {
	ll t,x; 
}a[maxn];

bool cmp(data a, data b) {
	return a.t < b.t; 
}

int Abs(ll x) {
	return x>0?x:-x; 
}

bool canget(data a, data b) {
	return Abs(a.x-b.x) <= b.t-a.t; 
}

int n; 

bool f[maxn][maxn]; 
ll g[maxn]; 

int main() {
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) scanf( "%lld%lld", &a[i].t, &a[i].x ); 
//	sort(a+1, a+n+1, cmp); 
	a[0].t = 0; a[0].x = 0;
	for (int i = 1; i <= n; ++i) 
		if (a[i].t == 0) f[0][i] = true; 
	f[0][0] = true; 
	g[0] = 0; 
	for (int i = 1; i <= n; ++i) 
		g[i] = 0x3f3f3f3f3f3f3f3fll; 
	for (int i = 0; i < n; ++i) {
		if (g[i] <= a[i].t) {
			f[i][0] = true; 
			g[i+1] = min(g[i+1], max(g[i]+Abs(a[i+1].x-a[i].x), a[i].t)); 
			for (int k = i+2; k <= n; ++k)
				if (max(g[i]+Abs(a[i].x-a[k].x),a[i].t) + Abs(a[k].x-a[i+1].x)<= a[i+1].t) 
					f[i+1][k] = true; 
		}
		for (int j = i+2; j <= n; ++j) 
			if (f[i][j]) {
				if (canget(a[i], a[i+1])) 
				 	f[i+1][j] = true; 
			}
		if (f[i][0]) {
			if (canget(a[i], a[i+1])) {
				f[i+1][0] = true; 
				g[i+1] = min(g[i+1], a[i].t+Abs(a[i+1].x-a[i].x));
				for (int k = i+2; k <= n; ++k) 
					if (Abs(a[i].x-a[k].x) + Abs(a[k].x-a[i+1].x) <= a[i+1].t - a[i].t) 
						f[i+1][k] = true; 
			}
		}
		if (f[i][i+1]) {
			if (i+1 == n) { printf( "YES\n" ); return 0; }
			if (canget(a[i], a[i+2])) {
				f[i+2][0] = true; 
				g[i+2] = min(g[i+2], max(a[i].t+Abs(a[i+2].x-a[i].x), a[i+1].t)); 
				for (int k = i+3; k <= n; ++k) 
					if (max(a[i].t+Abs(a[i].x-a[k].x), a[i+1].t) + Abs(a[k].x-a[i+2].x) <= a[i+2].t) 
						f[i+2][k] = true; 
			}
		}
	}
	if (f[n][0] || g[n] <= a[n].t) printf( "YES\n" );
	else printf( "NO\n" ); 
}