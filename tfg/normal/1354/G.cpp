#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::vector<int> gifts;

int qry(int i, int j, int size) {
	std::cout << "? " << size << ' ' << size << std::endl;
	for(int a = 0; a < size; a++) {
		std::cout << (a+i);
		if(a + 1 == size) {
			std::cout << std::endl;
		} else {
			std::cout << ' ';
		}
	}
	for(int a = 0; a < size; a++) {
		std::cout << (a+j);
		if(a + 1 == size) {
			std::cout << std::endl;
		} else {
			std::cout << ' ';
		}
	}
	if(!gifts.empty()) {
		int wotf = 0;
		for(int a = 0; a < size; a++) {
			wotf += gifts[i+a] - gifts[j+a];
		}
		std::cout << "balance is " << wotf << std::endl;
		if(wotf > 0) return -1;
		else if(wotf == 0) return 0;
		else return 1;
	}
	std::string str;
	std::cin >> str;
	if(str == "FIRST") return -1;
	else if(str == "EQUAL") return 0;
	else if(str == "SECOND") return 1;
	else {
		assert(0);
		return 42;
	}
}

void solve() {
	int n, k;
	std::cin >> n >> k;
	if(0) {
		gifts.assign(n+1, 0);
		for(int i = 1; i <= n; i++) {
			std::cin >> gifts[i];
		}
	}
	std::uniform_int_distribution<int> dist(2, n);
	for(int i = 0; i < 20; i++) {
		int j = dist(rng);
		int ans = qry(1, j, 1);
		if(ans == 1) {
			std::cout << "! 1" << std::endl;
			return;
		}
	}
	int l = 2, r = 3;
	while(r != n+1) {
		int ans = qry(1, l, r-l);
		if(ans) {
			assert(ans == -1);
			break;
		}
		l = std::min(r + 2 * (r - l), n+1);
		std::swap(l, r);
	}
	while(l+1 != r) {
		int mid = (l + r) / 2;
		if(qry(1, l, mid - l)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	std::cout << "! " << l << std::endl;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}