#include <bits/stdc++.h>
using namespace std; 

using ll = long long; 
#define fir first
#define sec second 
#define pb push_back
using vi = vector<int>; 
const ll mod = 1000000007; 
const int maxn = 2000006; 

/*
f[i][j] = f[i-1][j-1] * (i-1)
f[i][0] = sum{f[i-1][j]} 0<=j<k

g[i][j] = f[i][i-j] / (i-1)!
f[i][j] = g[i][i-j] * (i-1)!

g[i][j] = f[i][i-j] / (i-1)! 
		= f[i-1][i-j-1] * (i-1) / (i-1)!
		= g[i-1][j]

g[i][i] = f[i][0] / (i-1)!
		= sum{f[i-1][j]} / (i-1)!
		= sum{g[i-1][i-j-1] * (i-2)!} / (i-1)!

ans = sum{f[n][i]}
*/

int n, k; 
ll fac[maxn], inv[maxn], ifac[maxn]; 
ll g[maxn]; 
int main() {
	cin>>n>>k; 
	fac[0] = fac[1] = inv[1] = ifac[1] = 1; 
	for (int i = 2; i <= n; ++i) {
		inv[i] = (mod-mod/i) * inv[mod % i] % mod; 
		fac[i] = fac[i-1] * i % mod; 
		ifac[i] = ifac[i-1] * inv[i] % mod; 
	}
	g[1] = 1; 
	ll sum = g[1]; 
	for (int i = 2; i <= n; ++i) {
		if (i-k-1 >= 0) sum = (sum - g[i-k-1] + mod) % mod; 
		g[i] = sum * inv[i-1] % mod; 
		sum = (sum + g[i]) % mod; 
	}
	ll ans = 0; 
	for (int i = 1; i <= n; ++i) 
		ans = (ans + g[i]) % mod; 
	ans = ans * fac[n-1] % mod; 
	cout<<(fac[n]-ans+mod) % mod<<endl; 
}