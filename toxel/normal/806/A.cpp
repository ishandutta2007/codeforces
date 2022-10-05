#include<bits/stdc++.h>
#define ll long long

ll x, y, p, q;
int test;

int main(){
	scanf("%d", &test);
	while (test --){
		scanf("%I64d%I64d%I64d%I64d", &x, &y, &p, &q);
		if (p == q){
			printf(x == y ? "0\n" : "-1\n");
			continue;
		}
		if (!p){
			printf(!x ? "0\n" : "-1\n");
			continue;
		}
		ll a = y * p - x * q;
		if (!a){
			printf("0\n");
			continue;
		}
		ll left = 0, right = 4e9;
		while (left < right){
			ll mid = left + right >> 1;
			if (mid * (q - p) >= y - x && mid * q >= y && mid * p >= x){
				right = mid;
			}
			else{
				left = mid + 1;
			}
		}
		printf("%I64d\n", left * q - y);
	}
	return 0;
}