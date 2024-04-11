#include <iostream>
#include <queue>
#include <vector>

typedef long long ll;

const int ms = 200200;

ll a[ms];

ll solve(int first, std::priority_queue<ll, std::vector<ll>, std::greater<ll>> hp) {
	ll ans = 0;
	while(first-- && !hp.empty()) {
		ans += hp.top();
		hp.pop();
	}
	if(ans) {
		hp.push(ans);
	}
	while(hp.size() > 1) {
		ll cur = 0;
		for(int i = 0; i < 3 && !hp.empty(); i++) {
			cur += hp.top();
			hp.pop();
		}
		ans += cur;
		hp.push(cur);
	}
	return ans;
}

int main() {
	int n;
	std::cin >> n;
	std::priority_queue<ll, std::vector<ll>, std::greater<ll>> hp;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		hp.push(a[i]);
	}
	ll ans = solve(0, hp);
	for(int i = 1; i <= 3; i++) {
		ans = std::min(ans, solve(i, hp));
	}
	std::cout << ans << "\n";
}