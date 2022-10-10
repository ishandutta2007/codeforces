#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	int s = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		s = (s + a[i]) % 2;
	}
	std::sort(a.begin(), a.end(), std::greater<int>());
	std::vector<long long> sum(n + 2, 0);
	auto check = [&](int x) {
		if(x > n) {
			return 1;
		}
		std::vector<int> b;
		int on = 0;
		while(on < n && a[on] >= x) {
			b.push_back(a[on++]);
		}
		b.push_back(x);
		while(on < n) {
			b.push_back(a[on++]);
		}
		//std::cout << "checking for " << x << '\n';
		for(int i = 0; i <= n; i++) {
			sum[i+1] = sum[i] + b[i];
			//std::cout << b[i] << (i == n ? '\n' : ' ');
		}
		int mask = 0;
		for(int i = 0, j = 0; i <= n; i++) {
			j = std::max(j, i + 1);
			while(j <= n && b[j] >= i + 1) {
				j++;
			}
			while(j - 1 > i && b[j-1] <= i + 1) {
				j--;
			}
			//if(sum[i + 1] > bal) {
			if(sum[i + 1] > (long long) i * (i + 1) + sum[n+1] - sum[j] + (j - i - 1LL) * (i + 1LL)) {
				// is bad
				if(a[i] >= x) {
					mask |= 1;
				} else {
					return 1;
				}
			}
		}
		if(mask) {
			return -1;
		}
		return 0;
	};
	for(int x = s; x <= n + 20; x += 2) {
		//std::cout << check(x) << '\n';
		//std::cout << x << ": " << check(x) << "\n";
	}
	int l = 0, r = n / 2 + 10;
	while(l != r) {
		int mid = (l + r) / 2;
		if(check(2 * mid + s) < 0) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	if(check(2 * l + s) != 0) {
		std::cout << "-1\n";
		return 0;
	}
	r = n / 2 + 10;
	int ll = l;
	while(l != r) {
		int mid = (l + r + 1) / 2;
		if(check(2 * mid + s) > 0) {
			r = mid - 1;
		} else {
			l = mid;
		}
	}
	for(int i = ll; i <= r; i++) {
		std::cout << 2 * i + s << (i == r ? '\n' : ' ');
	}
}