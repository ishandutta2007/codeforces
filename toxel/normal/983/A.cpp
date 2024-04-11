#include<bits/stdc++.h>

typedef long long ll;

int main(){
	int test;
	scanf("%d", &test);
	while (test --){
		ll p, q, b;
		scanf("%lld%lld%lld", &p, &q, &b);
		ll gcd = std::__gcd(p, q);
		p /= gcd, q /= gcd;
		gcd = std::__gcd(q, b);
		while (gcd != 1){
			while (q % gcd == 0){
				q /= gcd;
			}
			gcd = std::__gcd(gcd, q);
		}
		puts(q == 1 ? "Finite" : "Infinite");
	}
	return 0;
}