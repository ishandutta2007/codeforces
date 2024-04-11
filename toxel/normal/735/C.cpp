#include<bits/stdc++.h>
#define ll long long

ll n;
std::map <ll, ll> Hash;
std::vector <ll> fib;

int main(){
	scanf("%I64d", &n);
	fib.push_back(2);
	fib.push_back(3);
	for (int i = 1; ; ++ i){
		ll x = fib[i] + fib[i - 1];
		if (x > 2e18){
			break;
		}
		fib.push_back(x);
	}
	int ans = upper_bound(fib.begin(), fib.end(), n) - fib.begin();
	return printf("%d\n", ans), 0;
}