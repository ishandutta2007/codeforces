#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, p;
	std::cin >> n >> p;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	auto check = [&](int x) {
		int ans = 0;
		for(int i = 0, j = 0; i < n; i++) {
			while(j < n && x + i >= a[j]) j++;
			int got = j - i;
			if(got <= 0) return -1;
			if(got >= p) ans = 1;
		}
		return ans;
	};
	int l = 0, r = 1e9 + 1e6;
	while(l != r) {
		int mid = (l + r) / 2;
		if(check(mid) >= 0) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	int L = l;
	l = 0, r = 1e9 + 1e6;
	while(l != r) {
		int mid = (l + r) / 2;
		if(check(mid) >= 1) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	int R = l;
	std::cout << R - L << '\n';
	for(int i = L; i < R; i++) {
		std::cout << i << (i + 1 == R ? '\n' : ' ');
	}
}