#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define ll long long

ll solve (ll n, ll x) {
	if (x & 1ll) return (x + 1) >> 1;
	x >>= 1; ll tmp = (x - (n & 1)) % (n >> 1);
	if (!tmp) tmp += n >> 1;
	return ((n + 1) >> 1) + solve(n >> 1, tmp);
}
ll n, q;

int main () {
	cin >> n >> q;
	while (q--) {
		ll x; scanf("%lld", &x);
		printf("%lld\n", solve(n, x));
	}
	return 0;
}