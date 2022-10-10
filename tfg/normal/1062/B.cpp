#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int ans = 0;
	int hehe = 1;
	std::set<int> ex;
	for(int i = 2; i * i <= n; i++) {
		int got = 0;
		while(n % i == 0) {
			n /= i;
			got++;
		}
		if(got) {
			hehe *= i;
			ex.insert(got);
		}
		ans = std::max(ans, got);
	}
	if(n > 1) {
		hehe *= n;
		ex.insert(1);
	}
	std::cout << hehe << ' ';
	if(ans <= 1) {
		std::cout << "0\n";
	} else {
		int hmm = 1;
		int wtf = 0;
		while(hmm < ans) {
			hmm += hmm;
			wtf++;
		}
		std::cout << wtf + (hmm != ans || ex.size() > 1 ? 1 : 0) << '\n';
	}
}