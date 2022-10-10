#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long s, e, t;
	std::cin >> s >> e >> t;
	e -= t - 1;
	int n;
	std::cin >> n;
	std::vector<long long> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	a.push_back(e + 1);
	n++;
	std::sort(a.begin(), a.end());
	long long ans[2] = {0, s};
	for(int l = 0, r = 0; l < n; l = r) {
		if(s >= e) break;
		//std::cout << "at " << a[l] << " got " << s << '\n';
		if(a[l] > s) {
			ans[0] = s;
			break;
		}
		if(s - a[l] + 1 < ans[1]) {
			ans[1] = s - a[l] + 1;
			ans[0] = a[l] - 1;
		}
		while(r < n && a[l] == a[r]) {
			r++;
			s += t;
		}
	}
	std::cout << ans[0] << '\n';
}