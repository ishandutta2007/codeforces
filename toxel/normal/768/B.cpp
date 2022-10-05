#include<bits/stdc++.h>
#define ll long long

const int N = 60;

ll l, r, n, power[N], lgn = 0;

ll solve(int stage, ll sit){
	ll x = power[lgn - 1 - stage];
	if (sit == x){
		return n >> stage & 1;
	}
	if (sit < x){
		return solve(stage + 1, sit);
	}
	return solve(stage + 1, sit % x);
}

int main(){
	scanf("%I64d%I64d%I64d", &n, &l, &r);
	if (n == 0 || n == 1){
		return printf("%I64d\n", n), 0;
	}
	ll x = n;
	while (x){
		++ lgn;
		x >>= 1;
	}
	power[0] = 1;
	for (int i = 1; i < N; ++ i){
		power[i] = power[i - 1] * 2;
	}
	ll ans = 0;
	for (ll i = l; i <= r; ++ i){
		ans += solve(0, i);
	}
	return printf("%I64d\n", ans), 0;
}