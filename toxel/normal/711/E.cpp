#include<bits/stdc++.h>
#define ll long long

const int moder = 1e6 + 3;

int power_mod(int a, ll exp){
	int ret = 1;
	while (exp){
		if (exp & 1){
			ret = 1ll * ret * a % moder;
		}
		a = 1ll * a * a % moder;
		exp >>= 1;
	}
	return ret;
}

ll n, k;

int main(){
	scanf("%I64d%I64d", &n, &k);
	ll prod = 1;
	for (int i = 0; i < n && prod <= k; ++ i, prod <<= 1){
		if (prod > k){
			break;
		}
	}
	if (prod < k){
		return printf("1 1\n"), 0;
	}
	int power2n = power_mod(2, n), nume = 1;
	for (int i = 1; i < k; ++ i){
		nume = 1ll * (power2n - i) * nume % moder;
		if (!nume){
			break;
		}
	}
	ll cnt = 0, x = k - 1;
	while (x){
		cnt += x >> 1;
		x >>= 1;
	}
	int inv2cnt = power_mod(power_mod(2, cnt), moder - 2);
	nume = 1ll * nume * inv2cnt % moder;
	int deno = 1ll * power_mod(power_mod(2, n), k - 1) * inv2cnt % moder;
	nume = (deno - nume + moder) % moder;
	return printf("%d %d\n", nume, deno), 0;
}