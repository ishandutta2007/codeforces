#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int maxn = 2006; 
const ll oo = 0x3f3f3f3f3f3f3f3fll; 

int n; 
ll g[maxn][maxn]; 
ll d[maxn]; 
bool v[maxn]; 

int main() {
	scanf( "%d", &n ); 
	ll minl = oo; 
	for (int i = 1; i <= n; ++i) g[i][i] = oo; 
	for (int i = 1; i < n; ++i) 
		for (int j = i+1; j <= n; ++j) {
			scanf( "%lld", &g[i][j] ); 
			g[j][i] = g[i][j]; 
			minl = min(minl, g[i][j]); 
		}
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= n; ++j) 
			g[i][j] -= minl; 
	for (int i = 1; i <= n; ++i) {
		d[i] = oo; 
		for (int j = 1; j <= n; ++j) 
			d[i] = min(d[i], g[i][j] * 2); 
	}
	memset(v, false, sizeof(v)); 
	for (int i = 1; i <= n; ++i) {
		int k = -1; 
		for (int j = 1; j <= n; ++j) 
			if (!v[j])
				if (k == -1 || d[k] > d[j]) 
					k = j; 
		v[k] = true; 
		for (int j = 1; j <= n; ++j) 
			d[j] = min(d[j], d[k] + g[k][j]); 
	}
	for (int i = 1; i <= n; ++i) printf( "%lld\n", d[i] + minl * (n-1) ); 
}