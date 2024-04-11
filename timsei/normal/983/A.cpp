#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

#define int long long

int n , p , q , b;

int gcd(int x , int y) {
	return (!y) ? x : gcd(y , x % y);
}

main(void) {
	cin >> n;
	for(int i = 1;i <= n;++ i) {
		scanf("%I64d%I64d%I64d" , &p , &q , &b);
		p %= q;
		q /= gcd(p , q);
		int now = gcd(q , b);
		while(1) {
			if(now > 1) {
				while(q % now == 0)
				q /= now;
				now = gcd(now , q);
			}
			else break;
		}
		if(q == 1) {
			puts("Finite");
		}
		else puts("Infinite");
	}
}