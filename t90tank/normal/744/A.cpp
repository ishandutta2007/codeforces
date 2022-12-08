#include <bits/stdc++.h>
using namespace std; 

const int maxn = 300000; 
using ll = long long; 

int n, m, k; 
int c[maxn]; 
int f[maxn]; 
int s[maxn]; 

int getf(int v) {
	if (f[v] == v) return v; 
	f[v] = getf(f[v]); 
	return f[v]; 
}

int main() {
	scanf( "%d%d%d", &n, &m, &k ); 
	for (int i = 1; i <= k; ++i) scanf( "%d", &c[i]); 
	for (int i = 1; i <= n; ++i) {
		f[i] = i; 
		s[i] = 1; 
	}
	for (int i = 1; i <= m; ++i) {
		int u, v; 
		scanf( "%d%d", &u, &v ); 
		int fu = getf(u); 
		int fv = getf(v); 
		if (fu != fv) {
			f[fu] = fv; 
			s[fv] += s[fu]; 
		}
	}
	ll maxs = 0, sum = n; 
	ll all = 0; 
	for (int i = 1; i <= k; ++i) {
		ll u = s[getf(c[i])];
		sum -= u; 
		maxs = max(maxs,u); 
		all += u*(u-1)/2; 
	}
	all += sum*(sum-1)/2+sum*maxs; 
	cout<<all-m<<endl; 
}