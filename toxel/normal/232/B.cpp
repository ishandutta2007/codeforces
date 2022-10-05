#include<bits/stdc++.h>

const int N = 110;
const int moder = 1e9 + 7;
typedef long long ll;

int dp[N * N];
int comb[N][N], power[N][N][2];

int powermod(int a, ll exp){
	int ret = 1;
	for ( ; exp > 0; exp >>= 1){
		if (exp & 1){
			ret = 1ll * a * ret % moder;
		}
		a = 1ll * a * a % moder;
	}
	return ret;
}

int main(){
	for (int i = 0; i < N; ++ i){
		comb[i][0] = 1;
		for (int j = 1; j <= i; ++ j){
			comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
			comb[i][j] -= comb[i][j] >= moder ? moder : 0;
		}
	}
	ll n, m, t;
	scanf("%I64d%I64d%I64d", &n, &m, &t);
	for (int i = 0; i < N; ++ i){
		for (int j = 0; j <= i; ++ j){
			power[i][j][0] = powermod(comb[i][j], m / n);
			power[i][j][1] = powermod(comb[i][j], m / n + 1);
		}
	}
	dp[0] = 1;
	for (int i = 0; i < n; ++ i){
		int x = m % n > i;
		for (int j = i * n; j >= 0; -- j){
			for (int k = 1; k <= n; ++ k){
				dp[j + k] = (dp[j + k] + 1ll * power[n][k][x] * dp[j]) % moder;
			}
		}
	}
	return printf("%d\n", dp[t] % moder), 0;
}