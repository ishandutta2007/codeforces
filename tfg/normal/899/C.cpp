#include <iostream>
#include <vector>

typedef long long ll;

int main() {
	ll n;
	std::cin >> n;
	ll sum = (n * (n + 1) / 2) / 2;
	ll mine = 0;
	std::vector<int> ans;
	for(int i = n; i > 0; i--) {
		if(i <= sum) {
			ans.push_back(i);
			mine += i;
			sum -= i;
		}
	}
	ll other = (n * (n + 1) / 2) - mine;
	ll cost = other - mine;
	if(cost < 0) {
		cost = -cost;
	}
	std::cout << cost << '\n';
	std::cout << ans.size();
	for(auto a : ans) {
		std::cout << ' ' << a;
	}
	std::cout << '\n';
}