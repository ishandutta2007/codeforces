#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::vector<long long> a;

void gen(long long cur, int f) {
	a.push_back(cur);
	while((long long)(1e18) / cur >= 10) {
		cur *= 10;
		a.push_back(cur);
		if(f < 3) {
			for(int i = 1; i < 10; i++) {
				gen(cur + i, f + 1);
			}
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 1; i < 10; i++) {
		gen(i, 1);
	}
	int n;
	std::cin >> n;
	std::sort(a.begin(), a.end());
	//std::cout << "generated " << a.size() << " numbers\n";
	while(n--) {
		long long l, r;
		std::cin >> l >> r;
		std::cout << (int)(std::upper_bound(a.begin(), a.end(), r) - std::lower_bound(a.begin(), a.end(), l)) << '\n';
	}
}