#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int l = 0, r = n-1;
	int last = -1;
	std::string ans;
	while(l < r && a[l] != a[r]) {
		if(std::max(a[l], a[r]) <= last) {
			break;
		}
		if(std::min(a[l], a[r]) <= last) {
			if(a[l] > last) {
				ans += 'L';
				last = a[l++];
			} else {
				ans += 'R';
				last = a[r--];
			}
		} else if(a[l] < a[r]) {
			ans += 'L';
			last = a[l++];
		} else {
			ans += 'R';
			last = a[r--];
		}
	}
	std::string bas = ans;
	// solve getting more from prefix
	{
		int ll = l;
		int lastl = last;
		std::string wtf = bas;
		while(ll <= r && a[ll] > lastl) {
			lastl = a[ll++];
			wtf += 'L';
		}
		if(wtf.size() > ans.size()) {
			ans = wtf;
		}
	}
	// solve getting more from suffix
	{
		int rr = r;
		int lastl = last;
		std::string wtf = bas;
		while(l <= rr && a[rr] > lastl) {
			lastl = a[rr--];
			wtf += 'R';
		}
		if(wtf.size() > ans.size()) {
			ans = wtf;
		}
	}
	std::cout << ans.size() << '\n' << ans << '\n';
}