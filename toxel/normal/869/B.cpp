#include<bits/stdc++.h>

const int moder = 10;
typedef long long ll;

int main(){
	ll a, b;
	scanf("%I64d%I64d", &a, &b);
	if (b - a <= 100){
		int ans = 1;
		for (ll i = a + 1; i <= b; ++ i){
			ans = ans * (i % 10) % moder;
		}
		return printf("%d\n", ans), 0;
	}
	return printf("0\n"), 0;
}