#include<bits/stdc++.h>

const int N = 100010;
const int M = 26;
const int moder = 1e9 + 7;
const int MAX = 326;

int dp[N], fac[N], inv[N], power[N], power26[N];
char s[N];
int test;

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

int main(){
	power[0] = power26[0] = 1;
	for (int i = 1; i < N; ++ i){
		power[i] = power[i - 1] * 25ll % moder;
		power26[i] = power26[i - 1] * 26ll % moder;
	}
	fac[0] = 1;
	for (int i = 1; i < N; ++ i){
		fac[i] = 1ll * fac[i - 1] * i % moder;
	}
	inv[N - 1] = powermod(fac[N - 1], moder - 2);
	for (int i = N - 1; i; -- i){
		inv[i - 1] = 1ll * inv[i] * i % moder;
	}
	int n, op, len;
	scanf("%d", &test);
	++ test;
	while (test --){
		int n;
		if (s[0] == '\0'){
			op = 1;
		}
		else{
			scanf("%d", &op);
		}
		if (op == 1){
			scanf("%s", s);
			len = strlen(s);
			if (len > MAX){
				memset(dp, 0, sizeof(dp));
				dp[len] = power26[len] - 1;
				for (int i = len + 1; i < N; ++ i){
					dp[i] = ((26ll * dp[i - 1] - 1ll * power[i - len] * comb(i - 1, i - len)) % moder + moder) % moder;
				}
			}
			continue;
		}
		scanf("%d", &n);
		if (n < len){
			printf("0\n");
			continue;
		}
		if (len <= MAX){
			int ret = power26[n];
			for (int i = n; i > n - len; -- i){
				ret = ((ret - 1ll * power[i] * comb(n, i)) % moder + moder) % moder;
			}
			printf("%d\n", ret);
		}
		else{
			printf("%d\n", (power26[n] - dp[n] + moder) % moder);
		}
	}
	return 0;
}