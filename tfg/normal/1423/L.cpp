#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <bitset>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1100;

std::bitset<ms> mat[ms];

int read(int n) {
	int size;
	std::cin >> size;
	std::bitset<ms> cur;
	while(size--) {
		int x;
		std::cin >> x;
		cur[x-1] = true;
	}
	for(int i = 0; i < n; i++) {
		if(!cur[i]) continue;
		if(!mat[i][i]) return -1;
		cur ^= mat[i];
	}
	int ans = 0;
	for(int i = 0; i < 30; i++) {
		if(cur[n+i]) {
			ans ^= 1 << i;
		}
	}
	return ans;
}


int bits[1 << 16];
int pop(int x) {
	return x < (1 << 16) ? bits[x] : bits[x & ((1 << 16) - 1)] + pop(x >> 16);
}
void solve1(int n, int q, std::vector<int> basis) {
	// solution for small basis
	std::vector<int> mask(1, 0);
	for(int i = 0; i < (int) basis.size(); i++) {
		for(int j = 0; j < (1 << i); j++) {
			mask.push_back(mask[j] ^ basis[i]);
		}
	}
	while(q--) {
		int got = read(n);
		if(got == -1) {
			std::cout << "-1\n";
			continue;
		}
		int ans = 1e9;
		for(auto m : mask) {
			ans = std::min(ans, pop(got ^ m));
		}
		std::cout << ans << '\n';
	}
}

void solve2(int n, int q, std::vector<int> basis) {
	// solution for big basis
	int id = 0;
	std::vector<int> mapping;
	for(auto m : basis) {
		while((m & (1 << id)) == 0) {
			mapping.push_back(id++);
		}
		id++;
	}
	while(id < 30) {
		mapping.push_back(id++);
	}
	assert((int) mapping.size() <= 15);
	std::vector<int> dp(1 << mapping.size(), 1e9), wtf(1 << mapping.size(), 0);
	dp[0] = 0;
	for(int i = 0; i < (1 << (int) mapping.size()); i++) {
		for(int j = 0; j < (int) mapping.size(); j++) {
			if(i & (1 << j)) {
				wtf[i] ^= 1 << mapping[j];
			}
		}
	}
	for(auto mask : basis) {
		for(int i = 0; i < (int) dp.size(); i++) {
			dp[i^mask] = std::min(dp[i^mask], dp[i] + 1);
		}
	}
	while(q--) {
		int got = read(n);
		if(got == -1) {
			std::cout << "-1\n";
			continue;
		}
		int ans = 1e9;
		for(int i = 0; i < (int) dp.size(); i++) {
			ans = std::min(ans, dp[i] + pop(got ^ wtf[i]));
		}
		std::cout << ans << '\n';
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 1; i < (1 << 16); i++) {
		bits[i] = (i & 1) + bits[i / 2];
	}
	int n, s, d;
	std::cin >> n >> s >> d;
	for(int ii = 0; ii < s; ii++) {
		std::bitset<ms> cur;
		int size;
		std::cin >> size;
		while(size--) {
			int x;
			std::cin >> x;
			cur[x-1] = true;
		}
		cur[n+ii] = true;
		for(int i = 0; i < n+s; i++) {
			if(!cur[i]) continue;
			if(mat[i][i]) {
				cur ^= mat[i];
			} else {
				mat[i] = cur;
				for(int j = 0; j < i; j++) {
					if(mat[j][i]) {
						mat[j] ^= cur;
					}
				}
				break;
			}
		}
	}
	std::vector<int> basis;
	for(int i = 0; i < s; i++) {
		int cur = 0;
		for(int j = 0; j < s; j++) {
			if(mat[n+i][n+j]) {
				cur ^= 1 << j;
			}
		}
		if(cur) basis.push_back(cur);
	}
	if((int) basis.size() <= 15) {
		solve1(n, d, basis);
	} else {
		solve2(n, d, basis);
	}
}