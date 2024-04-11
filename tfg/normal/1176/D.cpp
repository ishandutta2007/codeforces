#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <map>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	const int ms = 3003000;
	std::vector<int> prime(ms, -1);
	std::vector<int> id(ms, -1);
	std::vector<int> primes;
	int haha = 0;
	for(int i = 2; i < ms; i++) {
		if(prime[i] != -1) continue;
		id[i] = ++haha;
		primes.push_back(i);
		for(int j = i; j < ms; j += i) {
			if(prime[j] == -1) prime[j] = i;
		}
	}
	int n;
	std::cin >> n;
	std::vector<int> a(2*n);
	for(int i = 0; i < 2 * n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.rbegin(), a.rend());
	std::map<int, int> wtf;
	std::vector<int> ans;
	for(auto x : a) {
		if(wtf[x]) {
			wtf[x]--;
			continue;
		}
		if(x == prime[x]) {
			// it's prime
			ans.push_back(id[x]);
			assert(prime[id[x]] == id[x]);
			wtf[id[x]]++;
		} else {
			// not prime
			ans.push_back(x);
			wtf[x / prime[x]]++;
		}
	}
	for(auto x : ans) {
		std::cout << x << ' ';
	}
	std::cout << std::endl;
}