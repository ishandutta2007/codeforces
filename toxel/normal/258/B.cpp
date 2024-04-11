#include<bits/stdc++.h>

const int N = 20;
const int moder = 1e9 + 7;

int digit[N], cnt[N], dp[N][N];

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

int comb(int n, int m){
	if (n < m || m < 0){
		return 0;
	}
	int ret = 1;
	for (int i = n; i > n - m; -- i){
		ret = 1ll * ret * i % moder;
	}
	for (int i = 1; i <= m; ++ i){
		ret = 1ll * ret * powermod(i, moder - 2) % moder;
	}
	return ret;
}

int main(){
	int m;
	scanf("%d", &m);
	++ m;
	int x = m, digitcnt = 0;
	while (x){
		digit[digitcnt ++] = x % 10;
		x /= 10;
	}
	std::reverse(digit, digit + digitcnt);
	for (int i = 0, now = 0; i < digitcnt; ++ i){
		for (int j = 0; j < digit[i]; ++ j){
			for (int k = 0; k < digitcnt - i; ++ k){
				cnt[now + k + (j == 4 || j == 7)] += comb(digitcnt - i - 1, k) * powermod(2, k) * powermod(8, digitcnt - i - 1 - k);
			}
		}
		now += digit[i] == 4 || digit[i] == 7;
	}
	-- cnt[0];
	int ans = 0;
	for (int i = 1; i <= 9; ++ i){
		if (!cnt[i]) continue;
		int sum = 0;
		-- cnt[i];
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int j = 0; j <= 9; ++ j){
			for (int u = N - 1; u >= 0; -- u){
				for (int v = N - 1; v >= 0; -- v){
					for (int w = 1; w <= 6; ++ w){
						int sit1 = u + w, sit2 = v + w * j;
						if (sit1 >= N || sit2 >= N) continue;
						dp[sit1][sit2] = (dp[sit1][sit2] + 1ll * dp[u][v] * comb(cnt[j], w)) % moder;
					}
				}
			}
		}
		for (int j = 0; j < i; ++ j){
			sum += dp[6][j];
			sum -= sum >= moder ? moder : 0;
		}
		++ cnt[i];
		ans = (ans + 1ll * sum * cnt[i]) % moder;
	}
	ans = 720ll * ans % moder;
	printf("%d\n", ans);
	return 0;
}