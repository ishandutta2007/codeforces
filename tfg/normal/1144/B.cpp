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
	std::vector<int> a[2];
	int sum = 0;
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		sum += x;
		a[x%2].push_back(-x);
	}
	for(int i = 0; i < 2; i++) {
		std::sort(a[i].begin(), a[i].end());
	}
	int ans = sum;
	{
		int cur = 0;
		for(int i = 0, j = 0, k = 0; 1; k ^= 1) {
			if(k == 0) {
				if(i >= (int) a[0].size()) break;
				cur += a[0][i++];
			} else {
				if(j >= (int) a[1].size()) break;
				cur += a[1][j++];
			}
		}
		ans = std::min(ans, sum + cur);
	}
	{
		int cur = 0;
		for(int i = 0, j = 0, k = 1; 1; k ^= 1) {
			if(k == 0) {
				if(i >= (int) a[0].size()) break;
				cur += a[0][i++];
			} else {
				if(j >= (int) a[1].size()) break;
				cur += a[1][j++];
			}
		}
		ans = std::min(ans, sum + cur);
	}
	std::cout << ans << '\n';
}