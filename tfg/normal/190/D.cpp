#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	long long ans = 0;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::vector<int> freq(k+1, 0);
	freq[0] = n;
	std::map<int, int> wtf;
	auto change = [&](int x, int delta) {
		int f = wtf[x];
		freq[f]--;
		wtf[x] += delta;
		f += delta;
		freq[f]++;
	};
	for(int l = 0, r = 0; l < n; l++) {
		while(r < n && freq[k] <= 0) change(a[r++], 1);
		//std::cout << "at " << l << ", " << r << ", " << freq[k] << "\n";
		if(freq[k] <= 0) {
			break;
		}
		ans += (n - r) + 1;
		change(a[l], -1);
	}
	std::cout << ans << std::endl;
}