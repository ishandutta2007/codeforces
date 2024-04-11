#include<bits/stdc++.h>
#define ll long long

const int N = 1e7 + 100;

ll power_mod(ll a, ll index){
	ll ret = 1;
	while (index){
		if (a > 1e8){
			return INT_MAX;
		}
		if (index & 1){
			ret *= a;
		}
		if (ret > 1e8){
			return INT_MAX;
		}
		a *= a;
		index >>= 1;
	}
	return ret;
}

int power[(int) sqrt(N)], l, r, n;

int main(){
	scanf("%d%d%d", &n, &l, &r);
	if (n == 1){
		return printf("%d\n", r - l + 1), 0;
	}
	if (n == 2){
		return printf("%I64d\n", 1ll * (r - l + 1) * (r - l)), 0;
	}
	for (int i = 1, sz = exp(log(r) / (n - 1)) + 10; i < sz; ++ i){
		power[i] = power_mod(i, n - 1);
	}
	ll ans = 0;
	for (int i = 1, sz = exp(log(r) / (n - 1)) + 10; i < sz; ++ i){
		for (int j = i + 1; j < sz; ++ j){
			if (std::__gcd(i, j) > 1){
				continue;
			}
			int x = r / power[j] - (l - 1) / power[i];
			if (x > 0){
				ans += x;
			}
		}
	}
	printf("%I64d\n", ans << 1);
	return 0;
}