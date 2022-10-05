#include<bits/stdc++.h>
#define ll long long

ll l1, r1, l2, r2, k;

int main(){
	scanf("%I64d%I64d%I64d%I64d%I64d", &l1, &r1, &l2, &r2, &k);
	l1 = std::max(l1, l2);
	r1 = std::min(r1, r2);
	if (l1 > r1){
		return printf("0\n"), 0;
	}
	ll ans = r1 - l1 + 1;
	if (l1 <= k && k <= r1){
		-- ans;
	}
	return printf("%I64d\n", ans), 0;
}