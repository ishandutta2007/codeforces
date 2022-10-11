#include <set>
#include <iostream>

typedef long long ll;

int main() {
	std::set<ll> nums;
	ll n, k;
	std::cin >> n >> k;
	if(k >= n && n > 1) {
		std::cout << "No\n";
		return 0;
	}
	for(int i = 1; i <= k; i++) {
		if(nums.count(n % i)) {
			std::cout << "No\n";
			return 0;
		}
		nums.insert(n % i);
	}
	std::cout << "Yes\n";
}