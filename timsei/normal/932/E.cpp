#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

#define int long long

const int mod = 1e9 + 7;

int S[N][N], n , k , m , x , y;

int Pow(int x , int y) {
	if(y == 0) return 1;
	if(y == 1) return x % mod;
	x %= mod;
	int it = Pow(x * x % mod , y >> 1);
	if(y & 1) it = it * x % mod;
	return it;
}

int inv[N];


int C(int x , int y) {
	int now = 1;
	for(int i = y;i >= 1;-- i) {
		now = now * inv[i] % mod * (x + i - y) % mod;
	}
	return now;
}

int fac[N] , T2[N];

main(void) {
	scanf("%lld%lld" , &n , &k);
	for(int i = 1;i <= k;++ i) {
		S[i][0] = 0; S[i][1] = 1;
		for(int j = 2;j <= i;++ j) {
			S[i][j] = (S[i - 1][j - 1] + S[i - 1][j]) % mod * j % mod;
		}
	}
	fac[0] = 1; T2[0] = 1;
	for(int i = 1;i <= k;++ i) inv[i] = Pow(i , mod - 2);
	for(int i = 1;i <= k;++ i) fac[i] = fac[i - 1] * i % mod , T2[i] = T2[i - 1] * 2 % mod;
	int ans = 0;
	for(int i = 1;i <= min(n , k);++ i) {
		ans = (ans + S[k][i] * C(n , i) % mod * Pow(2 , n - i) % mod) % mod;
	}
	cout << ans;
}