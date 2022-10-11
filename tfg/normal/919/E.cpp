#include <iostream>

typedef long long ll;

const int ms = 2e6;

int a, b, p;
ll x;

int cycle[ms];

int fexp(ll x, int e) {
	ll ans = 1;
	for(; e > 0; e /= 2) {
		if(e & 1) {
			ans = ans * x % p;
		}
		x = x * x % p;
	}
	return ans;
}

int main() {
	std::cin >> a >> b >> p >> x;
	cycle[0] = b;
	a = fexp(a, p - 2);
	for(int i = 1; i < p; i++) {
		cycle[i] = (ll)cycle[i - 1] * a % p;
	}
	ll ans = 0;
	for(int i = 1; i < p; i++) {
		int cur = i;
		int need = cycle[i];
		ll first = i;
		if(cur < need) {
			first += (ll) (i + 1) * (p - 1);
			cur = p - 1;
		}
		first += (ll) (cur - need) * (p - 1);
		cur = need;
		if(first > x) {
			continue;
		}
		ans += (x - first + 1 + ((ll)p * (p - 1) - 1)) / ((ll)p * (p - 1));
	}
	std::cout << ans << '\n';
}