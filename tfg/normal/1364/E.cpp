#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::vector<int> local;
std::map<std::pair<int, int>, int> memo;
int qries;

int qry(int i, int j) {
	assert(i != j);
	if(i > j) std::swap(i, j);
	if(memo.count(std::pair<int, int>(i, j))) return memo[std::pair<int, int>(i, j)];
	qries++;
	assert(qries <= 4269);
	int ans;
	std::cout << "? " << i+1 << ' ' << j+1 << std::endl;
	if(local.empty()) {
		std::cin >> ans;
	} else {
		ans = local[i] | local[j];
		//std::cout << "(" << local[i] << ", " << local[j] << ")\n";
		//std::cout << ans << std::endl;
	}
	return memo[std::pair<int, int>(i, j)] = ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	if(n < 0) {
		n = -n;
		for(int i = 0; i < n; i++) {
			//std::cout << "pushing " << i << std::endl;
			local.push_back(i);
		}
		std::shuffle(local.begin(), local.end(), rng);
	}
	std::vector<int> a(n, 0);
	for(int i = 0; i < n; i++) {
		a[i] = i;
	}
	std::shuffle(a.begin(), a.end(), rng);
	auto go = [&](int x) {
		int ans = ~0;
		int c = 0;
		for(auto i : a) {
			if(c == 30) break;
			if(i != x) {
				ans = ans & qry(i, x);
				c++;
			}
		}
		return ans;
	};
	int i = 0;
	int val = go(i);
	for(auto j : a) {
		if(i == j) continue;
		if(qry(i, j) == val) {
			i = j;
			val = go(i);
		}
	}
	assert(val == 0);
	for(int j = 0; j < n; j++) {
		if(j == i) a[j] = 0;
		else a[j] = qry(i, j);
	}
	std::cout << '!';
	for(auto x : a) std::cout << ' ' << x;
	if(!local.empty()) {
		assert(a == local);
	}
	std::cout << std::endl;
}