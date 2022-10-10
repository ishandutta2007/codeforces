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
	std::vector<std::pair<int, int> > a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i].first >> a[i].second;
		a[i].first -= a[i].second;
	}
	std::sort(a.begin(), a.end());
	std::reverse(a.begin(), a.end());
	long long ans = 0;
	int i = 0;
	int j = n - 1;
	for(auto v : a) {
		v.first += v.second;
		//std::cout << "(" << v.first << ", " << v.second << ")\n";
		ans += (long long) i * v.first + (long long) j * v.second;
		i++;j--;
	}
	std::cout << ans << '\n';
}