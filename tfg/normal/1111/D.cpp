#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const long long MOD = 1e9 + 7;
const int ms = 100001;

long long fexp(long long x, long long e = MOD - 2) {
	long long ans = 1;
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x % MOD;
		x = x * x % MOD;
	}
	return ans;
}

long long fat[ms], ifat[ms];

long long ans[52][52];

int getID(char c) { return 'a' <= c && c <= 'z' ? c - 'a' : c - 'A' + 26; }

long long poly[ms];

void add(int x) {
	for(int i = ms-1; i >= x; i--) {
		poly[i] += poly[i - x];
	}
}

void rem(int x) {
	for(int i = x; i < ms; i++) {
		poly[i] -= poly[i - x];
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	fat[0] = ifat[0] = 1;
	for(int i = 1; i < ms; i++) {
		fat[i] = fat[i-1] * i % MOD;
		ifat[i] = fexp(fat[i]);
	}
	std::string str;
	std::cin >> str;
	int n = (int) str.size();
	std::vector<int> freq(52, 0);
	for(char c = 'a'; c <= 'z'; c++) {
		//std::cout << c << ", " << getID(c) << '\n';
	}
	for(char c = 'A'; c <= 'Z'; c++) {
		//std::cout << c << ", " << getID(c) << '\n';
	}
	for(auto c : str) freq[getID(c)]++;
	long long bs = fat[n/2] * fat[n/2] % MOD;
	for(auto f : freq) bs = bs * ifat[f] % MOD;
	poly[0] = 1;
	for(auto f : freq) {
		if(f > 0) {
			add(f);
		}
	}
	//std::cout << "base is " << bs << '\n';
	for(int i = 0; i < 52; i++) {
		if(freq[i] == 0) continue;
		ans[i][i] = poly[n / 2] % MOD * bs % MOD;
		rem(freq[i]);
		for(int j = i + 1; j < 52; j++) {
			if(freq[j] == 0) continue;
			if(n / 2 - (freq[i] + freq[j]) >= 0) {
				rem(freq[j]);
				ans[i][j] = poly[n/2 - (freq[i] + freq[j])] % MOD * bs % MOD * 2 % MOD;
				add(freq[j]);
			}
		}
		add(freq[i]);
	}
	int q;
	std::cin >> q;
	while(q--) {
		int l, r;
		std::cin >> l >> r;
		l--;r--;
		l = getID(str[l]);
		r = getID(str[r]);
		if(l > r) std::swap(l, r);
		//std::cout << "query for " << l << ", " << r << "\n";
		std::cout << ans[l][r] << '\n';
	}
}