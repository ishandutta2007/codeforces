#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, L;
	std::cin >> n >> L;
	std::vector<std::pair<int, int>> ranges(L + 1, std::pair<int, int>(n + 1, -1));
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		ranges[a[i]].first = std::min(ranges[a[i]].first, i);
		ranges[a[i]].second = std::max(ranges[a[i]].second, i);
	}
	std::vector<int> left(L + 1, n + 1);
	left[0] = -1;
	int last = -1;
	long long ans = 1;
	for(int i = 1; i <= L; i++) {
		if(ranges[i].second == -1) {
			left[i] = left[i-1];
			left[i] = last;
			//std::cout << "left[" << i << "] = " << left[i] << '\n';
			if(i == L) {
				//std::cout << "!\n";
				std::cout << (long long) L * (L + 1) / 2 << '\n';
				return 0;
			}
			ans++;
			continue;
		}
		if(last >= ranges[i].first) {
			break;
		}
		if(i == L) {
			//std::cout << "!\n";
			std::cout << (long long) L * (L + 1) / 2 << '\n';
			return 0;
		}
		last = ranges[i].second;
		left[i] = last;
		//std::cout << "left[" << i << "] = " << left[i] << '\n';
		
		ans++;
	}
	last = n + 1;
	int pt = 0;
	for(int i = L; i > 0; i--) {
		if(ranges[i].second == -1) {
			while(pt <= L && left[pt] < last) {
				pt++;
			}
			while(pt > 0 && left[pt-1] >= last) {
				pt--;
			}
			ans += pt;
			continue;
		}
		if(last <= ranges[i].second) {
			break;
		}
		last = ranges[i].first;
		while(pt <= L && left[pt] < last) {
			pt++;
		}
		assert(pt <= L);
		while(pt > 0 && left[pt-1] >= last) {
			pt--;
		}
		assert(pt > 0);
		ans += pt;
	}
	std::cout << ans << '\n';
}