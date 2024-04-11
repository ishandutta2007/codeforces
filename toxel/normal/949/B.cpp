#include<bits/stdc++.h>

typedef long long ll;

ll calc(ll n, ll x){
	if (x & 1){
		return x + 1 >> 1;
	}
	return calc(n >> 1, x >> 1) + (n >> 1);
}

ll solve(ll n, ll x){
	ll max = 1;
	while (max << 1 <= n){
		max <<= 1;
	}
	if (x <= n - max << 1){
		if (x & 1){
			return x + 1 >> 1;
		}
		return calc(max, (x >> 1) + (max << 1) - n) + (n - max);
	}
	return calc(max, x - (n - max << 1)) + (n - max);
}

int main(){
	ll n, q;
	scanf("%I64d%I64d", &n, &q);
	while (q --){
		ll x;
		scanf("%I64d", &x);
		printf("%I64d\n", solve(n, x));
	}
	return 0;
}