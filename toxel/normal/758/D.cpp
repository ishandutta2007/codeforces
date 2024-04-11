#include<bits/stdc++.h>
#define ll long long

const int N = 100;

ll dp[N], dig[N];
char s[N];
int n, len;

ll power(ll a, ll index){
	ll ret = 1;
	double d_ret = 1, d_a = a;
	while (index){
		if (d_a > 2e18){
			return LLONG_MAX;
		}
		if (index & 1){
			ret *= a;
			d_ret *= d_a;
		}
		if (d_ret > 2e18){
			return LLONG_MAX;
		}
		a *= a;
		d_a *= d_a;
		index >>= 1;
	}
	return ret;	
}

int get(int sit, int num){
	ll ret = 0;
	if (s[sit] == '0'){
		if (num == 1){
			return 0;
		}
		return -2;
	}
	for (int i = sit; i < sit + num; ++ i){
		ret = ret * 10 + s[i] - '0';
		if (ret >= n){
			return -1;
		}
	}
	return ret;
}

int main(){
	power(123358, 4);
	scanf("%d%s", &n, s);
	len = strlen(s);
	memset(dp, 0x7f, sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i <= len; ++ i){
		for (int j = 0; j <= i - 1; ++ j){
			int x = get(len - i, j + 1);
			if (x == -2){
				continue;
			}
			if (x == -1){
				break;
			}
			ll y = power(n, dig[i - j - 1]);
			if (x == 0){
				if (dp[i] > dp[i - j - 1]){
					dp[i] = dp[i - j - 1];
					dig[i] = dig[i - j - 1] + 1;
				}
				continue;
			}
			if (y == LLONG_MAX){
				continue;
			}
			double orz = dp[i - j - 1] + 1.0 * x * y;
			if (orz > 2e18){
				continue;
			}
			if (dp[i] > dp[i - j - 1] + x * y){
				dp[i] = dp[i - j - 1] + x * y;
				dig[i] = dig[i - j - 1] + 1;
			}
		}
	}
	printf("%I64d\n", (long long) dp[len]);
	return 0;
}