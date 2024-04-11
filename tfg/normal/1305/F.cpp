#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1e6;

bool np[ms];
long long haha[ms];
std::vector<long long> primes;

void segmentedSieve(long long l, long long r) {
	for(long long i = l; i < r; i++) {
		haha[i-l] = i;
	}
	l = std::max(l, (long long) ms);
	for(auto p : primes) {
		for(long long i = (l + p - 1) / p * p; i < r; i += p) {
			//np[i - l] = true;
			while(haha[i-l] % p == 0) {
				haha[i-l] /= p;
			}
		}
	}
	for(long long i = l; i < r; i++) {
		if(haha[i-l] != 1) {
			primes.push_back(haha[i-l]);
		}
	}
	std::sort(primes.begin(), primes.end());
	primes.resize(std::unique(primes.begin(), primes.end()) - primes.begin());
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 2; i < ms; i++) {
		if(np[i]) continue;
		primes.push_back(i);
		for(int j = i + i; j < ms; j += i) {
			np[j] = true;
		}
	}
	for(int i = 0; i < ms; i++) {
		np[i] = false;
	}
	int n;
	std::cin >> n;
	std::vector<long long> b(n);
	for(int i = 0; i < n; i++) {
		std::cin >> b[i];
	}
	std::sort(b.begin(), b.end());
	std::vector<std::pair<long long, int>> a;
	for(int l = 0, r = 0; l < n; l = r) {
		while(r < n && b[l] == b[r]) r++;
		a.emplace_back(b[l], r - l);
	}
	std::shuffle(a.begin(), a.end(), rng);
	segmentedSieve(a[0].first - n, a[0].first + n + 1);
	std::vector<std::pair<long long, int>> cost;
	for(auto p : primes) {
		cost.emplace_back(p, 0);
	}
	for(auto x : a) {
		for(int i = 0; i < (int) cost.size(); i++) {
			long long val = x.first % cost[i].first;
			val = (val == x.first ? cost[i].first - val : std::min(val, cost[i].first - val)) * x.second;
			if(val + cost[i].second > n) {
				std::swap(cost[i], cost.back());
				cost.pop_back();
				i--;
			} else {
				cost[i].second += (int) val;
			}
		}
	}
	int ans = n;
	for(auto wtf : cost) ans = std::min(ans, wtf.second);
	std::cout << ans << '\n';
}