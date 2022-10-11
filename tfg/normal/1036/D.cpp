#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <set>
#include <cstdio>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	// std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int same = 0;
	int n;
	std::cin >> n;
	long long first = 0;
	std::set<long long> hmm;
	for(int i = 0; i < n; i++) {
		long long v;
		scanf("%lld", &v);
		first += v;
		hmm.insert(first);
	}
	std::cin >> n;
	long long second = 0;
	for(int i = 0; i < n; i++) {
		long long v;
		scanf("%lld", &v);
		second += v;
		if(hmm.count(second)) {
			same++;
		}
	}
	if(same == 0 || first != second) {
		std::cout << "-1\n";
	} else {
		std::cout << same << '\n';
	}
}