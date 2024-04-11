#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <cstdio>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 300300;
const int INF = 100;

int p[ms];
int dp[ms];
int freq[ms];
int trans[ms];

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 2; i < ms; i++) {
		if(p[i]) continue;
		for(int j = i; j < ms; j += i) {
			p[j] = i;
		}
	}
	int n;
	std::cin >> n;
	for(int i = 1; i < ms; i++) {
		dp[i] = INF;
	}
	while(n--) {
		int v;
		//std::cin >> v;
		scanf("%d", &v);
		int group = 1;
		//std::cout << "reading " << v << '\n';
		while(v != 1) {
			int curp = p[v];
			while(v % curp == 0) {
				v /= curp;
			}
			group *= curp;
		}
		//std::cout << "got " << group << "\n";
		dp[group] = 1;
		freq[group]++;
	}
	for(int i = 1; i < ms; i++) {
		for(int j = i + i; j < ms; j += i) {
			freq[i] += freq[j];
		}
	}
	for(int i = ms - 1; i > 1; i--) {
		if(dp[i] >= INF) continue;
		//std::cout << "cost to get to " << i << " is " << dp[i] << '\n';
		std::vector<int> primes;
		n = i;
		while(n != 1) {
			//std::cout << "got prime " << p[n] << "\n";
			primes.push_back(p[n]);
			assert(n / p[n] % p[n] != 0);
			n /= p[n];
		}
		n = (int) primes.size();
		for(int j = 0; j < (1 << n); j++) {
			trans[j] = 0;
		}
		for(int x = (1 << n) - 1; x >= 0; x--) {
			int val = 1;
			for(int j = 0; j < n; j++) {
				if((x >> j) & 1) {
					val *= primes[j];
				}
			}
			int cur = 0;
			//for(y submask of (1 << n) ^ x) {
			int mask = ((1 << n) - 1) ^ x;
			//std::cout << "on val " << val << ", mask " << x << "\n";
			for(int y = mask; y > 0; y = (y - 1) & mask) {
				int z = y ^ x;
				//std::cout << "making transition to mask " << z << "\n";
				cur -= trans[z];
			}
			cur += freq[val];
			trans[x] = cur;
			if(cur) {
				//std::cout << "can choose " << cur << " to go to " << val << '\n';
				dp[val] = std::min(dp[val], dp[i] + 1);
			}
		}
	}
	if(dp[1] >= INF) {
		dp[1] = -1;
	}
	std::cout << dp[1] << '\n';
}