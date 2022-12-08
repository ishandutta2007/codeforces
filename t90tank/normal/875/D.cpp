#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int maxn = 200006; 

int n; 
int a[maxn]; 
int f[23][maxn]; 
int l[31][maxn];
int r[31][maxn]; 
ll ans; 

int maxnum(int l, int r) {
	int k = 31 - __builtin_clz(r+1-l); 
	int x = f[k][l+(1<<k)-1], y = f[k][r]; 
	if (a[x] > a[y]) return x; 
	return y; 
}

void solve(int L, int R) {
	if (L > R) return; 
	int M = maxnum(L, R);
	int pl = L, pr = R; 
	for (int h = 0; h <= 30; ++h) {
		if (((a[M] >> h) & 1) == 0) {
			pl = max(pl, l[h][M]+1); 
			pr = min(pr, r[h][M]-1); 
		}
	}
	ans += ll(M-L+1)*ll(R-M+1) - ll(M-pl+1)*ll(pr-M+1); 
	//cout<<L<<' '<<R<<' '<<M<<' '<<pl<<' '<<pr<<endl; 
	solve(L, M-1); 
	solve(M+1, R); 
}

int main() {
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) {
		scanf( "%d", &a[i] ); 
		f[0][i] = i; 
	}
	for (int i = 1; n >> i; ++i) 
		for (int j = 1<<i; j <= n; ++j) {
			int x = f[i-1][j], y = f[i-1][j-(1<<(i-1))]; 
			if (a[x] > a[y]) f[i][j] = x; 
			else f[i][j] = y; 
		}
	for (int h = 0; h <= 30; ++h) {
		l[h][0] = 0; 
		for (int i = 1; i <= n; ++i) 
			if ((a[i] >> h) & 1) l[h][i] = i; 
			else l[h][i] = l[h][i-1]; 
		r[h][n+1] = n+1; 
		for (int i = n; i >= 1; --i) 
			if ((a[i] >> h) & 1) r[h][i] = i; 
			else r[h][i] = r[h][i+1]; 
	}
	ans = 0; 
	solve(1, n); 
	cout<<ans<<endl; 
}