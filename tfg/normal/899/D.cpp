#include <iostream>

typedef long long ll;

ll solve(ll x, ll n) {
	if(x <= n + 1) {
		return x / 2;
	} else {
		//std::cout << "got " << (x - n) << '\n';
		return (n - (x - n) + 1) / 2;
	}
}

ll solve2(ll x, ll n) {
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(x - i <= n && i <= x - i) {
			ans++;
		}
	}
	return ans; 
}

int main() {
	ll n;
	std::cin >> n;
	ll mx = n + n - 1;
	if(mx < 9) {
		std::cout << n * (n - 1) / 2 << '\n';
		return 0;
	}
	ll base = 1;
	ll cur = 0;
	while(cur + base * 9 <= mx) {
		cur += base * 9;
		base *= 10;
	}
	ll ans = 0;
	while(cur <= mx) {
		// std::cout << "on (" << cur << ", " << n << "), got " << solve(cur, n) << "\n";
		ans += solve(cur, n);
		/*if(solve(cur, n) != solve2(cur, n)) {
			std::cout << "deu merda, (" << solve(cur, n) << ", " << solve2(cur, n) << ")\n";
		}*/
		cur += base;
	}
	std::cout << ans << '\n';
}