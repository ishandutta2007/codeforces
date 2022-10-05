#include<bits/stdc++.h>

typedef long long ll;

int a, b;

int main(){
	scanf("%d%d", &a, &b);
	if (a > b){
		std::swap(a, b);
	}
	ll ans = 1;
	for (int i = 2; i <= a; ++ i){
		ans *= i;
	}
	return printf("%I64d\n", ans), 0;
}