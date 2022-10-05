#include<bits/stdc++.h>

const int N = 110;
const int moder = 1e9 + 7;

int fac[N], inv[N];
int a[N];

int powermod(int a, int exp){
	int ret = 1;
	for ( ; exp > 0; exp >>= 1){
		if (exp & 1){
			ret = 1ll * ret * a % moder;
		}
		a = 1ll * a * a % moder;
	}
	return ret;
}

int dp[N];

int calc(int n){
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 0; i < 10; ++ i){
		for (int j = N - 1; j >= 0; -- j){
			int x = dp[j];
			dp[j] = 0;
			for (int k = a[i]; k <= n; ++ k){
				if (j + k >= N) break;
				dp[j + k] = (dp[j + k] + 1ll * x * inv[k]) % moder;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++ i){
		ans = (ans + 1ll * dp[i] * fac[i]) % moder;
	}
	return ans;
}

int main(){
	fac[0] = 1;
	for (int i = 1; i < N; ++ i){
		fac[i] = 1ll * fac[i - 1] * i % moder;
	}
	inv[N - 1] = powermod(fac[N - 1], moder - 2);
	for (int i = N - 1; i; -- i){
		inv[i - 1] = 1ll * inv[i] * i % moder;
	}
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 10; ++ i){
		scanf("%d", &a[i]);
	}
	int ans = calc(n);
	if (a[0] > 0){
		-- a[0];
	}
	ans -= calc(n - 1);
	ans += ans < 0 ? moder : 0;
	bool flag = a[0] <= 1;
	for (int i = 1; i < 10; ++ i){
		flag = flag && !a[i];
	}
	if (flag){
		-- ans;
		ans += ans < 0 ? moder : 0;
	}	
	printf("%d\n", ans);
	return 0;
}