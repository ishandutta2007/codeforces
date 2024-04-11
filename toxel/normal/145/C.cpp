#include<bits/stdc++.h>

const int N = 100010;
const int M = 1500;
const int moder = 1e9 + 7;

int powermod(int a, int exp){
	int ret = 1;
	for ( ; exp; exp >>= 1){
		if (exp & 1){
			ret = 1ll * ret * a % moder;
		}
		a = 1ll * a * a % moder;
	}
	return ret;
}

int fac[N], inv[N];
int dp[M];

bool check(int n){
	while (n){
		if (n % 10 != 4 && n % 10 != 7) return false;
		n /= 10;
	}
	return true;
}

int comb(int n, int m){
	if (m < 0 || n < m) return 0;
	return 1ll * fac[n] * inv[m] % moder * inv[n - m] % moder;
}

int main(){
	fac[0] = 1;
	for (int i = 1; i < N; ++ i){
		fac[i] = 1ll * i * fac[i - 1] % moder;
	}
	inv[N - 1] = powermod(fac[N - 1], moder - 2);
	for (int i = N - 1; i; -- i){
		inv[i - 1] = 1ll * inv[i] * i % moder;
	}
	int n, k;
	scanf("%d%d", &n, &k);
	int cnt = 0;
	std::map <int, int> Hash;
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		if (check(x)){
			++ cnt;
			++ Hash[x];
		}
	}
	dp[0] = 1;
	for (auto u : Hash){
		for (int i = M - 1; i >= 0; -- i){
			if (i){
				dp[i] = (dp[i] + 1ll * dp[i - 1] * u.second) % moder;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < M; ++ i){
		ans = (ans + 1ll * dp[i] * comb(n - cnt, k - i)) % moder;
	}
	return printf("%d\n", ans), 0;
}