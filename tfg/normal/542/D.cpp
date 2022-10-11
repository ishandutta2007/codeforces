#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

typedef long long ll;

const int md = 1001000;

std::vector<ll> getDivs(ll n) {
	std::vector<ll> ans[2];
	for(ll i = 1; i * i <= n; i++) {
		if(n % i == 0) {
			ans[0].push_back(i);
			if(n / i != i) {
				ans[1].push_back(n / i);
			}
		}
	}
	while(!ans[1].empty()) {
		ans[0].push_back(ans[1].back());
		ans[1].pop_back();
	}
	return ans[0];
}

ll prime(ll n) {
	if(n < 2) {
		return 0;
	}
	for(ll i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			while(n % i == 0) {
				n /= i;
			}
			if(n == 1) {
				return i;
			} else {
				return 0;
			}
		}
	}
	return n;
}

ll dp[md];
ll trans[md];

int main() {
	ll n;
	std::cin >> n;
	auto v = getDivs(n);
	std::sort(v.begin(), v.end());
	dp[0] = 1;
	std::set<ll> gotten;
	for(auto a : v) {
		ll got = prime(a - 1);
		//std::cout << "got " << got << "\n";
		if(got && gotten.count(got) == 0) {
			gotten.insert(got);
			ll d = got;
			ll x = n / d;
			while(x) {
				int pt = v.size() - 1;
				d++;
				if(n % d == 0) {
					for(int i = pt; v[i] >= d; i--) {
						if(v[i] % d != 0) {
							continue;
						}
						pt = std::min(pt, i - 1);
						while(v[i] / d < v[pt]) {
							pt--;
						}
						trans[i] += dp[pt];
					}
				}
				d--;
				x /= got;
				d *= got;
			}
			for(int i = 0; i < v.size(); i++) {
				dp[i] += trans[i];
				trans[i] = 0;
			}
		}
	}
	std::cout << dp[v.size() - 1] << '\n';
}