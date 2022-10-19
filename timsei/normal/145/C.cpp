#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <cassert>
using namespace std;

#define int long long

const int N = 2e5 + 5;

bool Yes(int x) {
	while(x) {
		if(x % 10 != 4 && x % 10 != 7) return 0;
		x /= 10;
	}
	return 1;
}

const int mod = 1e9 + 7;

long long num[N] , tot , inv[N] , fac[N];

int n , m , x , k , all;

long long dp[5005][5005];

map<int,int>Map;
map<int,int>::iterator it;

long long Pow(long long x , long long y) {
	if(!x) return 0;
	if(y == 0) return 1;
	if(y == 1) return x % mod;
	long long it = Pow(x , y >> 1);
	it = it * it % mod;
	if(y & 1) it = it * x % mod;
	return it;
}

long long C(int x , int y) {
	if(x < y) return 0ll;
	if(y == 0) return 1;
	if(y < 0) return 0;
	return fac[x] * inv[y] % mod * inv[x - y] % mod;
}

main(void) {
	scanf("%lld%lld" , &n , &k);
	for(int i = 1;i <= n;++ i) {
		scanf("%lld" , &x); ++ Map[x];
	}
	fac[0] = inv[0] = 1;
	for(int i = 1;i <= 200000;++ i) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = Pow(fac[i] , mod - 2);
	}
	for(it = Map.begin(); it != Map.end();++ it) {
		if(Yes(it -> first) && (it -> second) > 1) num[++ tot] = it -> second;
		else {
			all += it -> second;
		}
	}
	// from k - tot
	assert(tot <= 2000);
	for(int i = 0;i <= tot;++ i) dp[0][i] = C(all , k - tot + i) % mod;
	for(int i = 0;i < tot;++ i) {
		for(int j = tot;j >= 0; j --) {
			dp[i + 1][j] += dp[i][j]; dp[i + 1][j] %= mod;
			dp[i + 1][j + 1] += dp[i][j] % mod * num[i + 1] % mod; dp[i + 1][j + 1] %= mod;
		}
	}
	printf("%lld\n" , dp[tot][tot] % mod);
}