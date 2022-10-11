#include <iostream>
#include <cstdio>

typedef long long ll;

ll gcd(ll a, ll b) {
	while(b != 0) {
		a %= b;
		std::swap(a, b);
	}
	return a;
}

int main() {
	int n;
	std::cin >> n;
	while(n--) {
		ll a, b, base;
		scanf("%lld %lld %lld", &a, &b, &base);
		ll g = gcd(a, b);
		a /= g;
		b /= g;
		base = gcd(b, base);
		while(base != 1) {
			while(b % base == 0) b /= base;
			base = gcd(base, b);
		}
		if(b == 1) {
			printf("Finite\n");
		} else {
			printf("Infinite\n");
		}
	}
}