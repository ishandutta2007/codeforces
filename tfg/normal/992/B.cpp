#include <iostream>
#include <vector>
#include <set>

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int l, r, x, y;
	std::cin >> l >> r >> x >> y;
	int ans = 0;
	if(y % x != 0) {
		std::cout << ans << std::endl;
		return 0;
	}
	std::vector<int> facts[2];
	int rest = 1;
	for(int i = 2; i * i <= y; i++) {
		if(y % i == 0) {
			facts[0].push_back(1);
			while(y % i == 0) {
				facts[0].back() *= i;
				y /= i;
			}
			facts[1].push_back(1);
			while(x % i == 0) {
				facts[1].back() *= i;
				x /= i;
			}
			if(facts[0].back() == facts[1].back()) {
				facts[0].pop_back();
				rest *= facts[1].back();
				facts[1].pop_back();
			}
		}
	}
	if(y > 1) {
		facts[0].push_back(y);
		facts[1].push_back(1);
		while(x % y == 0) {
			facts[1].back() *= y;
			x /= y;
		}
		if(facts[0].back() == facts[1].back()) {
			facts[0].pop_back();
			rest *= facts[1].back();
			facts[1].pop_back();
		}
	}
	int n = facts[0].size();
	std::vector<int> val(1 << n, rest);
	for(int i = 0; i < (1 << n); i++) {
		for(int j = 0; j < n; j++) {
			val[i] *= facts[(i >> j) & 1][j];
		}
	}
	for(int i = 0; i < (1 << n); i++) {
		if(l <= std::min(val[i], val[i ^ ((1 << n) - 1)]) && std::max(val[i], val[i ^ ((1 << n) - 1)]) <= r) {
			ans++;
		}
	}
	std::cout << ans << std::endl;
}