#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 300300;
const int MOD = 998244353;

long long fat[ms];

template<class T>
long long solve(std::vector<T> &a) {
	std::sort(a.begin(), a.end());
	long long ha = 1;
	for(int l = 0, r = 0; l < (int) a.size(); l = r) {
		while(r < (int) a.size() && a[r] == a[l]) r++;
		ha = ha * fat[r-l] % MOD;
	}
	return ha;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	fat[0] = 1;
	for(int i = 1; i < ms; i++) {
		fat[i] = (long long) fat[i-1] * i % MOD;
	}
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> a;
	std::vector<int> b(n), c(n);
	for(int i = 0; i < n; i++) {
		std::cin >> b[i] >> c[i];
		a.emplace_back(b[i], c[i]);
	}
	long long ans = fat[n] - solve(b) - solve(c);
	bool good = true;
	std::sort(a.begin(), a.end());
	for(int i = 1; i < n; i++) {
		good = good && a[i].second >= a[i-1].second;
	}
	if(good) {
		ans += solve(a);
	}
	std::cout << (ans%MOD+MOD)%MOD << std::endl;
}