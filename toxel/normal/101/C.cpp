#include<bits/stdc++.h>
#define ll long long

ll mod(std::complex <ll> c){
	return c.real() * c.real() + c.imag() * c.imag();
}

ll point(std::complex <ll> a, std::complex <ll> b){
	return a.real() * b.real() + a.imag() * b.imag();
}

int main(){
	std::complex <ll> a, b, c, rotate[4];
	ll a1, a2, b1, b2, c1, c2;
	scanf("%I64d%I64d", &a1, &a2);
	scanf("%I64d%I64d", &b1, &b2);
	scanf("%I64d%I64d", &c1, &c2);
	a = {a1, a2};
	b = {b1, b2};
	c = {c1, c2};
	for (int i = 0; i < 4; ++ i){
		rotate[i] = b - a;
		a *= std::complex <ll> (0, 1);
	}
	if (c == std::complex <ll> (0, 0)){
		for (int i = 0; i < 4; ++ i){
			if (rotate[i] == std::complex <ll> (0, 0)){
				return printf("YES\n"), 0;
			}
		}
		return printf("NO\n"), 0;
	}
	ll _mod = mod(c);
	for (int i = 0; i < 4; ++ i){
		if (!(point(rotate[i], c) % _mod) && !(point(rotate[i], c * std::complex <ll> (0, 1)) % _mod)){
			return printf("YES\n"), 0;
		}
	}
	return printf("NO\n"), 0;
}