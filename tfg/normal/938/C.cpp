#include <iostream>

typedef long long ll;

ll f(ll n, ll m) {
	ll x = n / m;
	return n * n - x * x;
}

int main() {
	int t;
	std::cin >> t;
	while(t--) {
		ll want;
		std::cin >> want;
		ll n = 1;
		bool got = false;
		for(ll m = 2; m * m <= want + 1e6; m++) {
			ll l = m;
			ll r = 1e9;
			while(l != r) {
				ll mid = (l + r) / 2;
				if(f(mid, m) >= want) {
					r = mid;
				} else {
					l = mid + 1;
				}
			}
			if(f(l, m) == want) {
				std::cout << l << ' ' << m << '\n';
				got = true;
				break;
			}
		}
		if(want == 0) {
			std::cout << "1 1\n";
		} else if(!got) {
			std::cout << "-1\n";
		}
	}
}