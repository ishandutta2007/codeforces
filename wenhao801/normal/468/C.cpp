#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
#define ll long long

int main () {
	ll mod; cin >> mod;
	ll p = ((ll)1e18) % mod * 9 % mod * 9 % mod;
	printf("%lld %lld\n", mod - p, ((ll)1e18) + mod - p - 1);
	return 0;
}