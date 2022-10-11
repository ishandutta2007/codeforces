#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

typedef long long ll;

const ll MOD = 1e9 + 7;
const int ms = 1e6 + 10;

ll fexp(ll x, ll e) {
	ll ans = 1;
	for(; e > 0; e /= 2) {
		if(e & 1) {
			ans = ans * x % MOD;
		}
		x = x * x % MOD;
	}
	return ans;
}

ll dp[ms];
std::vector<int> divs;
std::map<ll, ll> memo;

ll solve(ll x) {
	if(x == 1) {
		return 1;
	}
	if(x < ms) {
		return dp[x];
	}
	if(memo.count(x)) {
		return memo[x];
	}
	ll ans = fexp(2, x - 1) - 1;
	//std::cout << x << ", Base is: " << ans << "\n";
	for(auto a : divs) {
		//std::cout << "testing " << a << "\n";
		if(a < x && x % a == 0) {
			ans = (ans - solve(a) + MOD) % MOD;
		} else if(a >= x) {
			break;
		}
	}
	return memo[x] = ans;
}

int main() {
	dp[1] = 1;
	for(int i = 2; i < ms; i++) {
		dp[i] = dp[i - 1] * 2 % MOD;
	}
	for(int i = 1; i < ms; i++) {
		for(int j = i + i; j < ms; j += i) {
			dp[j] = (dp[j] - dp[i] + MOD) % MOD;
		}
	}
	/*for(int i = 1; i < 50; i++) {
		if(solve(i) != dp[i]) {
			std::cout << i << ": (" << solve(i) << ", " << dp[i] << ")\n";
		}
	}*/
	ll x, y;
	std::cin >> x >> y;
	if(y % x != 0) {
		std::cout << "0\n";
	} else {
		for(int i = 2; i * i <= y / x; i++) {
			if((y / x) % i == 0) {
				divs.push_back(i);
				if((y / x) / i != i) {
					divs.push_back((y / x) / i);
				}
			}
		}
		std::sort(divs.begin(), divs.end());
		std::cout << solve(y / x) << '\n';
	}
}