#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, p, x;
ll pw(ll x, ll y) {
	ll re = 1;
	for (; y; y >>= 1) {
		if (y & 1) {
			re = re * x % p;
		}
		x = x * x % p;
	}
	return re;
}
int main() {
	cin >> a >> b >> p >> x;
	ll an = 1, z = 0;
	for (int i = 0; i < p - 1; i++) {
		ll c = b * pw(an, p - 2) % p;
		// n mod p = c
		// n mod (p - 1) = i
		ll n = (i * p + (p - 1) * (p - 1) * c) % (p * (p - 1));
		assert((n * an - b) % p == 0);
		z += (x - n + p * (p - 1)) / (p * (p - 1));
		an = an * a % p;
	}
	cout << z << endl;
}