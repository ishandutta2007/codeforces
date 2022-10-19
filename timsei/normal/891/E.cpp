#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int n , k , A[N] , dp[N] , ans , res;

int Pow(int x , int y) {
	if(!y) return 1;
	if(y == 1) return x % mod;
	int it = Pow(x * x % mod , y >> 1);
	if(y & 1) it = it * x % mod;
	return it;
}

void Add(int &x , int y) {
	(x += (y + mod)) %= mod;
}

int P(int x) {
	if(x & 1) return -1;
	return 1;
}

main(void) {
	scanf("%lld%lld" , &n , &k);
	for(register int i = 1;i <= n;++ i) scanf("%lld" , &A[i]);
	dp[0] = 1;
	for(register int i = 1;i <= n;++ i) {
		for(register int j = i;j >= 0;-- j) {
			Add(dp[j + 1] , dp[j] * A[i] % mod);
		}
	}
	ans = dp[n];
	int tmp = 1 , t2 = k;
	
	for(register int i = 0;i <= n;++ i) if(i <= k) {
		Add(res , P(i) * dp[n - i] % mod * Pow(n , k - i) % mod * tmp % mod);
		tmp = tmp * t2 % mod; -- t2;
	}
	res = res % mod;
	res = res * Pow(Pow(n , mod - 2) , k) % mod;
	ans = ans + mod - res;
	ans %= mod;
	printf("%lld\n" , ans);
}