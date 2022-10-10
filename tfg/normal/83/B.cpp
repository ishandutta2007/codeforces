#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<long long> a(n);
	long long x;
	std::cin >> x;
	long long sum = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		sum += a[i];
	}
	auto check = [&](long long xx) {
		long long ans = 0;
		for(auto y : a) {
			ans += std::min(xx, y);
		}
		//std::cout << "check for " << xx << " is " << ans << std::endl;
		return ans;
	};
	if(x > sum) {
		std::cout << "-1\n";
		return 0;
	}
	if(x == 0) {
		for(int i = 0; i < n; i++) {
			std::cout << i+1 << (i+1 == n ? '\n' : ' ');
		}
		return 0;
	}
	long long l = 0, r = 1e9;
	while(l != r) {
		long long mid = (l + r + 1) / 2;
		if(check(mid) > x) {
			//std::cout << check(mid) << " is greater than " << x << std::endl;
			r = mid - 1;
		} else {
			l = mid;
		}
	}
	//std::cout << "check is " << l << std::endl;
	x -= check(l);
	std::vector<int> b;
	for(int i = 0; i < n; i++) {
		if(a[i] > l) {
			b.push_back(i+1);
		}
	}
	std::vector<int> c;
	for(int i = (int) x; i < (int) b.size(); i++) {
		c.push_back(b[i]);
	}
	for(int i = 0; i < (int) x; i++) {
		if(a[b[i]-1] > l+1) {
			c.push_back(b[i]);
		}
	}
	b = c;
	for(int i = 0; i < (int) b.size(); i++) {
		std::cout << b[i] << (i+1 == (int) b.size() ? '\n' : ' ');
	}
}