#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5005, mod = 1000000007;
int n, k;
ll ans = 0;
int inv2 = mod + 1 >> 1;
int S[N][N], fac[N];

ll pow2(ll x, ll y){
	ll p = 1;
	while (y){
		if (y & 1){
			p = p * x % mod;
		}
		x = x * x % mod;
		y >>= 1;
	}
	return p;
}

int main(){
	scanf("%d%d", &n, &k);
	fac[0] = 1;
	for (int i = 1; i <= k; i++){
		fac[i] = (ll)fac[i - 1] * i % mod;
	}
	for (int i = 0; i <= k; i++){
		S[i][0] = (i == 0);
		for (int j = 1; j <= i; j++){
			S[i][j] = (S[i - 1][j - 1] + ((ll)S[i - 1][j] * j % mod)) % mod;
		}
	}
	ll now = 1, now2 = pow2(2, n);
	for (int i = 0; i <= k; i++){
		ans += now * S[k][i] % mod * now2 % mod;
		ans %= mod;
		now = now * (n - i) % mod;
		now2 = now2 * inv2 % mod;
	}
	printf("%lld\n", ans);
}