#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::vector<long long> f[2][26];

long long go(std::vector<long long> &a, std::vector<long long> &b) {
	long long ans = 0;
	for(int i = 0, l = 0, r = 0; i < (int) a.size(); i++) {
		while(l < (int) b.size() && b[l] < a[i]) l++;
		while(r < (int) b.size() && b[r] <= a[i]) r++;
		ans += r - l;
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	long long S;
	std::cin >> n >> k >> S;
	int ms = 1;
	std::vector<long long> a(1, 1);
	while(a.back() * ms <= S) {
		a.push_back(a.back() * ms++);
	}
	f[0][0].push_back(0);
	f[1][0].push_back(0);
	for(int rep = 0; rep < n; rep++) {
		long long x;
		std::cin >> x;
		int id = rep & 1;
		for(int j = k; j >= 0; j--) {
			int sz = (int) f[id][j].size();
			for(int i = 0; i < sz; i++) {
				if(f[id][j][i] + x <= S) {
					f[id][j].push_back(f[id][j][i] + x);
				}
				if(j+1 <= k && x < (long long) ms && f[id][j][i] + a[(int) x] <= S) {
					f[id][j+1].push_back(f[id][j][i] + a[(int) x]);
				}
			}
		}
	}
	for(int j = 0; j <= k; j++) for(auto &x : f[1][j]) {
		x = S - x;
		assert(0 <= x && x <= S);
	}
	for(int j = 0; j <= k; j++) {
		std::sort(f[0][j].begin(), f[0][j].end());
		std::sort(f[1][j].begin(), f[1][j].end());
	}
	long long ans = 0;
	for(int i = 0; i <= k; i++) for(int j = 0; i + j <= k; j++) {
		ans += go(f[0][i], f[1][j]);
	}
	std::cout << ans << '\n';
}