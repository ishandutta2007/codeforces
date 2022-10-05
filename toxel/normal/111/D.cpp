#include<bits/stdc++.h>

const int N = 1010;
const int moder = 1e9 + 7;

int fac[N * N], inv[N * N];

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

int comb(int n, int m){
	return 1ll * fac[n] * inv[m] % moder * inv[n - m] % moder;
}

int dp[N][N];

int main(){
	fac[0] = 1;
	for (int i = 1; i < N * N; ++ i){
		fac[i] = 1ll * i * fac[i - 1] % moder;
	}
	inv[N * N - 1] = powermod(fac[N * N - 1], moder - 2);
	for (int i = N * N - 1; i; -- i){
		inv[i - 1] = 1ll * inv[i] * i % moder;
	}
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	if (m == 1){
		printf("%d\n", powermod(k, n));
		return 0;
	}
	dp[0][0] = 1;
	for (int i = 1; i < N; ++ i){
		for (int j = 1; j <= i; ++ j){
			dp[i][j] = (1ll * dp[i - 1][j] * j + 1ll * dp[i - 1][j - 1] * j) % moder;
		}
	}
	int ans = 0;
	for (int i = 0; i <= std::min(k, n); ++ i){
		int sum = 0;
		for (int j = 0; i + j <= n && i + 2 * j <= k; ++ j){
			int x = 1ll * comb(k - i, j) * comb(k - i - j, j) % moder;
			x = 1ll * x * dp[n][i + j] % moder * dp[n][i + j] % moder;
			sum += x;
			sum -= sum >= moder ? moder : 0;
		}
		ans = (ans + 1ll * sum * powermod(i, n * (m - 2)) % moder * comb(k, i)) % moder;
	}
	return printf("%d\n", ans), 0;
}