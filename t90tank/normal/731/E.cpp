#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
const int maxn = 400000; 
ll f[maxn]; 
int a[maxn];
ll s[maxn]; 
int n;  

int main() {
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &a[i] ); 
	for (int i = 1; i <= n; ++i) s[i] = s[i-1] + a[i]; 
	f[n] = 0; 
	f[n-1] = s[n]; 
	ll best = max( s[n] - f[n], s[n-1] - f[n-1] ); 
	for (int i = n-2; i >= 1; --i) {
		f[i] = best; 
		best = max( best, s[i] - f[i] ); 
	}
	cout<<f[1]<<endl; 
}