#include<bits/stdc++.h>

typedef long long ll;

int main(){
	int test;
	scanf("%d", &test);
	while (test --){
		ll n;
		scanf("%I64d", &n);
		ll sum = n * (n + 1) >> 1;
		for (int i = 1; i <= n; i <<= 1){
			sum -= i << 1;
		}
		printf("%I64d\n", sum);
	}
	return 0;
}