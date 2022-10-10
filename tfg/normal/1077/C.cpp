#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	long long sum = 0;
	std::map<long long, int> freq;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		sum += a[i];
		freq[a[i]]++;
	}
	std::vector<int> ans;
	for(int i = 0; i < n; i++) {
		if((sum - a[i]) % 2 != 0) {
			continue;
		}
		long long want = (sum - a[i]) / 2;
		if(!freq.count(want)) continue;
		int got = freq[want] - (a[i] == want ? 1 : 0);
		if(got) {
			ans.push_back(i);
		}
	}
	n = (int) ans.size();
	std::cout << n << '\n';
	for(int i = 0; i < n; i++) {
		std::cout << ans[i] + 1 << (i + 1 == n ? '\n' : ' ');
	}
}