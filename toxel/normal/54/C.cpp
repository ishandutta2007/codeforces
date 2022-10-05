#include<bits/stdc++.h>

typedef long long ll;
const int N = 1010;

long double dp[N];

ll calc(ll n){
	ll now = 1, ans = 0;
	while (now <= n){
		if (2 * now <= n){
			ans += now;
		}
		else{
			ans += n - now + 1;
		}
		if (10.0 * now > 1.5 * n){
			break;
		}
		now *= 10;
	}
	return ans;
}

int main(){
	int n;
	scanf("%d", &n);
	dp[0] = 1.0;
	for (int i = 0; i < n; ++ i){
		ll l, r;
		scanf("%I64d%I64d", &l, &r);
		long double p = (long double) (calc(r) - calc(l - 1)) / (r - l + 1);
		for (int j = i; j >= 0; -- j){
			dp[j + 1] += dp[j] * p;
			dp[j] *= 1 - p;
		}
	}
	long double ans = 0;
	int k;
	scanf("%d", &k);
	for (int i = 0; i <= n; ++ i){
		if (i * 100 >= n * k){
			ans += dp[i];
		}
	}
	return printf("%.12Lf\n", ans), 0;
}