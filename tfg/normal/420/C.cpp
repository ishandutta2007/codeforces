#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, p;
	std::cin >> n >> p;
	std::vector<int> freq(n, 0);
	std::vector<std::pair<int, int>> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i].first >> a[i].second;
		a[i].first--;a[i].second--;
		if(a[i].first > a[i].second) {
			std::swap(a[i].first, a[i].second);
		}
		freq[a[i].first]++;
		freq[a[i].second]++;
	}
	auto b = freq;
	std::sort(b.begin(), b.end());
	std::sort(a.begin(), a.end());
	long long ans = 0;
	for(int i = 0, j = n; i < n; i++) {
		j = std::max(j, i+1);
		while(j-1 > i && b[j-1] + b[i] >= p) {
			j--;
		}
		//std::cout << "matching up " << i << " with " << j << '\n';
		ans += n-j;
	}
	for(int i = 0, j = 0; i < n; i = j) {
		while(j < n && a[i] == a[j]) {
			j++;
		}
		if(freq[a[i].first] + freq[a[i].second] - (j-i) < p && freq[a[i].first] + freq[a[i].second] >= p) {
			ans--;
		}
	}
	std::cout << ans << std::endl;
}