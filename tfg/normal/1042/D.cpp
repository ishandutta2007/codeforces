#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

int tree[ms];

void upd(int x) {
	for(; x < ms; x += x & -x) {
		tree[x]++;
	}
}

int qry(int x) {
	int ans = 0;
	for(; x > 0; x -= x & -x) {
		ans += tree[x];
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	long long t;
	std::cin >> n >> t;
	std::vector<long long> sum(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		std::cin >> sum[i];
		sum[i] += sum[i-1];
	}
	auto uni = sum;
	std::sort(uni.begin(), uni.end());
	uni.resize(std::unique(uni.begin(), uni.end()) - uni.begin());
	auto getID = [&](long long x) { return std::upper_bound(uni.begin(), uni.end(), x) - uni.begin(); };
	long long ans = 0;
	int lol = 0;
	for(auto v : sum) {
		long long want = v - t;
		ans += lol - qry(getID(want));
		lol++;
		upd(getID(v));
	}
	std::cout << ans << '\n';
}