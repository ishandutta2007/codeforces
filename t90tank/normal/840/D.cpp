#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second
const int l = 20; 
const int maxn = 300006; 

int e[maxn][l]; 
int tote; 
map<int,int> S; 
int a[maxn]; 
int yy[maxn]; 
int rr[maxn]; 
int h[maxn][1000/l]; 
int n, q; 
int app[maxn]; 
int sum[maxn]; 

int Get(int a, int b) {
	return e[h[a][b/l]][b%l]; 
}

int main() {
	scanf( "%d%d", &n, &q ); 
	for (int i = 1; i <= n; ++i) {
		scanf( "%d", &a[i] ); 
		S[a[i]] = 0; 
	}
	int tot = 0; 
	for (auto &p : S) {
		rr[tot] = p.fir; 
		p.sec = tot; 
		tot++; 
	}
	for (int i = 1; i <= n; ++i) a[i] = S[a[i]]; 
	
	int m = (int)sqrt(n*5)+3; 
	for (int i = 1; i <= n; ++i) app[a[i]]++; 
	vi big; 
	for (int i = 0; i < tot; ++i) 
		if (app[i] > m/5-3) {
			big.pb(i);
			yy[i] = big.size()-1; 
		}
		else yy[i] = -1; 
		
	int maxs = big.size()/l; 
	memset(h, 0, sizeof(h)); 
	memset(e, 0, sizeof(e)); 
	tote = 0; 
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= maxs; ++j) 
			h[i][j] = h[i-1][j]; 
		if (yy[a[i]] != -1) {
			int no = yy[a[i]]; 
			tote++; 
			for (int j = 0; j < l; ++j) e[tote][j] = e[h[i-1][no/l]][j]; 
			e[tote][no%l]++; 
			h[i][no/l] = tote; 
		}
	}
	 
		
	for (int i = 1; i <= q; ++i) {
		int l, r, k; 
		scanf( "%d%d%d", &l, &r, &k ); 
		int ans = -1; 
		for (auto x : big) 
			if (Get(r,yy[x])-Get(l-1,yy[x]) > (r-l+1)/k)
				if (ans==-1 || x<ans) ans = x; 
				
		if (r-l+1 <= m) {
			vi tr; 
			for (int i = l; i <= r; ++i) {
				tr.pb(a[i]); 
				sum[a[i]]++; 
			}
			for (auto x : tr) 
				if (sum[x] > (r-l+1)/k)
					if (ans==-1 || x<ans) ans = x; 
			for (auto x : tr) sum[x] = 0; 
		}
		
		printf( "%d\n", (ans==-1)?-1:rr[ans] ); 
	}
	
}