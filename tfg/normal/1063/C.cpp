#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int qry(long long x) {
	std::cout << x << " " << x << std::endl;
	std::string str;
	std::cin >> str;
	return str == "black" ? 0 : 1;
}

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int base = qry(0);
	long long l = 1, r = 1000000000;
	for(int i = 1; i < n; i++) {
		long long mid = (l + r) / 2;
		if(qry(mid) == base) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	l--;
	r++;
	std::cout << l + 1 << ' ' << l << ' ' << l << ' ' << l + 1 << std::endl;
}