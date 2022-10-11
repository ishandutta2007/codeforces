#include <iostream>

typedef long long ll;

int main() {
	ll n, k;
	std::cin >> n >> k;
	ll got = -1;
	int idx = -1;
	ll box = 0;
	for(int i = 1; i <= k; i++) {
		ll x;
		std::cin >> x;
		ll cur = (n / x) * x;
		if(cur > got) {
			got = cur;
			idx = i;
			box = (n / x);
		}
	}
	std::cout << idx << " " << box << "\n";
}