#include <bits/stdc++.h>
using namespace std; 

const int maxn = 2000007; 
using ll = long long; 
const ll mod = 1000000007;
const int D = 30; 

int r, n; 
ll way[D]; 
ll inv[maxn]; 
ll fac[maxn]; 
ll ifac[maxn];
int minp[maxn]; 

ll Get(ll a, ll b) {
	if (b == 0) return 0; 
	return fac[a+b-1] * ifac[a] % mod * ifac[b-1] % mod; 
}

int main() {
	fac[0] = ifac[0] = fac[1] = inv[1] = ifac[1] = 1; 
	for (int i = 2; i < maxn; ++i) {
		inv[i] = (ll)mod/i*(mod - inv[mod % i]) % mod; 
		fac[i] = (ll)fac[i-1] * i % mod; 
		ifac[i] = (ll)ifac[i-1] * inv[i] % mod; 
	}
	for (int i = 1; i < maxn; ++i) minp[i] = i; 
	for (int i = 2; i < maxn; ++i) 
		for (int j = i; j < maxn; j+=i) 
			minp[j] = min( minp[j], i ); 
	int q; 
	scanf( "%d", &q ); 
	while( q-- ) {
		scanf( "%d%d", &r, &n ); 
		if ( n == 1 ) {
			printf( "1\n" ); 
			continue; 
		}
		ll ans = 1; 
		ll x = n; 
		int t = 1, pre = minp[x]; 
		x /= minp[x]; 
		while (x > 1) {
			if (minp[x] != pre) {
				ans = (Get(t-1,r+1)*2% mod + Get(t,r)) % mod * ans % mod; 
				t = 0; 
			}
			pre = minp[x]; 
			x /= minp[x]; 
			t++; 
		}
		if (t > 0) ans = (Get(t-1,r+1)*2% mod + Get(t,r)) % mod * ans % mod; 
		printf( "%I64d\n", ans ); 
	}
}