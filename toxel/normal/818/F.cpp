#include<bits/stdc++.h>

typedef long long ll;

bool check(ll n, ll mid){
	ll x = mid + 1 >> 1;
	return ((n - x) * (n - x - 1) >> 1) + x >= mid;
}

int main(){
	int test;
	scanf("%d", &test);
	while (test --){
		ll n;
		scanf("%I64d", &n);
		if (n == 1){
			printf("0\n");
			continue;
		}
		ll left = 0, right = n << 1;
		while (left < right){
			ll mid = left + right + 1 >> 1;
			if (check(n, mid)){
				left = mid;
			}
			else{
				right = mid - 1;
			}
		}
		printf("%I64d\n", left);
	}
	return 0;
}