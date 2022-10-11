#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	int on = n-1;
	long long rest = 0;
	long long delta = 0;
	long long ans = 0;
	while(a[on] > a[0]) {
		int cur = a[on];
		while(a[on] == cur) {
			delta++;
			on--;
		}
		long long h = (cur - a[on]);
		long long use = (k - rest) / delta;
		use = std::min(use, h);
		//std::cout << "on " << cur << ", h is " << h << ", delta is " << delta << ", rest is " << rest << std::endl;
		//std::cout << "using " << use << std::endl;
		h -= use;
		rest += use * delta;
		if(h == 0) continue;
		rest = 0;
		ans++;
		//std::cout << "second part\n";
		long long size = k / delta;
		ans += h / size;
		rest = delta * (h % size);
		//std::cout << "size is " << size << ", resting " << rest << std::endl;
		//std::cout << "adding 1 + " << h / size << std::endl;
	}
	if(rest > 0) {
		ans++;
	}
	std::cout << ans << std::endl;
}