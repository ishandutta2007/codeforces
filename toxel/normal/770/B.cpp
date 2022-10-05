#include<bits/stdc++.h>
#define ll long long

ll x;

int main(){
	scanf("%I64d", &x);
	ll x1 = x;
	int len = 0, cnt = 0;
	while (x >= 10){
		++ len;
		x /= 10;
	}
	ll max = x;
	for (int i = 0; i < len; ++ i){
		max = max * 10 + 9;
	}
	if (max <= x1){
		return printf("%I64d\n", max), 0;
	}
	max = x - 1;
	for (int i = 0; i < len; ++ i){
		max = max * 10 + 9;
	}
	for (int i = 0; i < len; ++ i){
		ll ans = x;
		for (int j = 0; j < len; ++ j){
			ans = ans * 10 + (i == j ? 8 : 9);
		}
		if (ans <= x1){
			max = std::max(ans, max);
		}
	}
	return printf("%I64d\n", max), 0;
}