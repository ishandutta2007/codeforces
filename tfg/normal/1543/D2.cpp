#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int add(int a, int b, int k) {
	return (a + b == 0 ? 0 : (a + b) % k + add(a / k, b / k, k) * k);
}


int sub(int a, int b, int k) {
	return (a + b == 0 ? 0 : ((a - b) % k + k) % k + sub(a / k, b / k, k) * k);
}

int ans = 2;
bool qry(int val) {
	std::cout << val << std::endl;
	if(0) {
		std::cout << "currently is " << ans << std::endl;
		int aux = ans == val;
		assert(add(ans, sub(val, ans, 3), 3) == val);
		ans = sub(val, ans, 3);
		val = aux;
		std::cout << val << std::endl;
	} else {
		std::cin >> val;
	}
	return val == 1;
}

void solve() {
	int n, k;
	std::cin >> n >> k;
	int cur = 0;
	for(int i = 0; i < n; i++) {
		int val = i % 2 == 0 ? add(cur, i, k) : sub(cur, i, k);
		if(qry(val)) {
			return;
		}
		cur = sub(val, cur, k);
	}
	assert(0);
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}