#include <iostream>

typedef long long ll;

ll n;

bool fit(ll i, ll j) {
	return i * i + j * j <= n * n;
}

int main() {
	std::cin >> n;
	ll ans = 1;
	if(n == 0) {
	    std::cout << "1\n";
	    return 0;
	}
	ll r = n;
	ll l = n;
	for(ll i = 0; i <= n; i++) {
		while(!fit(i, r)) {
			r--;
		}
		l = std::min(l, r);
		while(fit(i, l - 1) && (!fit(i + 1, l - 1))) {
			l--;
		}
		ans += r - l + 1;
	}
	std::cout << (ans - 2) * 4 << '\n';
}