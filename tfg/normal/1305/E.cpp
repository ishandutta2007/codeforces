#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a;
	for(int i = 0; i < n && m - i / 2 >= 0; i++) {
		a.push_back(i+1);
		m -= i / 2;
	}
	if((int) a.size() == n && m > 0) {
		std::cout << "-1\n";
		return 0;
	}
	if(m > 0) {
		a.push_back((int) a.size() + 1 + ((int) a.size() / 2 - m) * 2);
		for(int i = 0; i + 1 < (int) a.size(); i++) {
			for(int j = 0; j < i; j++) {
				if(a[i] + a[j] == a.back()) m--;
			}
		}
		assert(m == 0);
	}
	const int INF = 1e9;
	int sum = a.empty() ? 1 : 2 * a.back();
	for(int i = (int) a.size(); i < n; i++) {
		a.push_back(INF - sum * (n - i - 1));
	}
	for(int i = 0; i < n; i++) {
		std::cout << a[i] << (i + 1 == n ? '\n' : ' ');
	}
}