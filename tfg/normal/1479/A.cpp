#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int qry(int x) {
	std::cout << "? " << x << std::endl;
	std::cin >> x;
	return x;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int l = 1, r = n;
	while(l != r) {
		int mid = (l + r) / 2;
		if(qry(mid) < qry(mid + 1)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	std::cout << "! " << l << std::endl;
}