#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200 * 30;
int to[ms][2];


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	std::vector<long long> sum(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		if(i) {
			sum[i] += sum[i-1] + a[i-1];
		}
	}
	std::set<std::pair<long long, int>> st;
	int ans = 0;
	for(int l = n-3; l >= 0; l--) {
		// a[l] ^ a[r] == (sum[r] - sum[l] - a[l])
		// a[l] + a[r] >= (sum[r] - sum[l] - a[l])
		// a[r] - sum[r] >= - (sum[l] + 2 * a[l])
		// sum[r] - a[r] <= sum[l] + 2 * a[l]
		st.insert({sum[l+2] - a[l+2], l+2});
		//std::cout << "inserting (" << sum[l+2] - a[l+2] << ", " << l+2 << ")\n";
		//std::cout << "searching for (" << sum[l] + a[l] << ", " << l << ")\n";
		for(auto it : st) {
			if(it.first > sum[l] + 2 * a[l]) {
				break;
			}
			int r = it.second;
			if((a[l] ^ a[r]) == (sum[r] - sum[l] - a[l])) {
				ans++;
			}
		}
	}
	std::cout << ans << '\n';
}