#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int check(std::vector<int> &v, int k, int st) {
	int sum = 0;
	int ans = 0;
	for(int i = st; i < (int) v.size(); i++) {
		if(sum + v[i] > k) {
			sum = v[i];
			ans++;
		} else {
			sum += v[i];
		}
	}
	if(sum > 0) {
		ans++;
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int l = 0, r = n - 1;
	while(l != r) {
		int mid = (l + r) / 2;
		if(check(a, k, mid) <= m) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	std::cout << n - l << std::endl;
}