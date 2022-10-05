#include<bits/stdc++.h>

typedef long long ll;

ll n, k;

int main(){
	scanf("%I64d%I64d", &n, &k);
	ll x = n >> 1;
	ll ans1 = x / (k + 1), ans2 = x / (k + 1) * k;
	return printf("%I64d %I64d %I64d\n", ans1, ans2, n - ans1 - ans2), 0;
}