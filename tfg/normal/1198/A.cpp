#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, bits;
	std::cin >> n >> bits;
	std::vector<int> a(n);
	for(auto &v : a) std::cin >> v;
	std::sort(a.begin(), a.end());
	std::vector<int> freq;
	for(int l = 0, r = 0; l < n; l = r) {
		while(r < n && a[l] == a[r]) r++;
		freq.push_back(r - l);
	}
	int want = 1;
	int ha = 0;
	while((long long) (ha+1) * n <= bits * 8 && want < n) {
		ha++;
		want += want;
	}
	want = std::min(want, (int) freq.size());
	int sum = 0;
	for(int i = want; i < freq.size(); i++) {
		sum += freq[i];
	}
	int ans = sum;
	for(int i = want; i < freq.size(); i++) {
		sum += freq[i-want] - freq[i];
		ans = std::min(ans, sum);
	}
	std::cout << ans << '\n';
}