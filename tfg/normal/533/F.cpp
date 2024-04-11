#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const long long MOD = 1e18 + 9;

long long fmul(unsigned long long a, unsigned long long b) {
	unsigned long long c = (long double) a * b / MOD;
	return (a * b - c * MOD + MOD) % MOD;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long ba = std::uniform_int_distribution<unsigned long long>(10, MOD - 2)(rng);
	ba = 128378126368LL;
	long long ha = 1;
	int n, m;
	std::cin >> n >> m;
	for(int i = 1; i < m; i++) {
		ha = fmul(ha, ba);
	}
	std::string s, t;
	std::cin >> s >> t;
	std::vector<long long> hashes(26, 0);
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < 26; j++) {
			hashes[j] = (fmul(hashes[j], ba) + 1) % MOD;
		}
		hashes[t[i]-'a'] = (hashes[t[i]-'a'] + 1) % MOD;
	}
	std::vector<long long> cur(26, 0);
	for(int i = 0; i+1 < m; i++) {
		for(int j = 0; j < 26; j++) {
			cur[j] = (fmul(cur[j], ba) + 1) % MOD;
		}
		cur[s[i]-'a'] = (cur[s[i]-'a'] + 1) % MOD;
	}
	std::vector< std::pair<long long, long long> > h1(26), h2(26);
	std::vector<int> ans;
	for(int i = m-1; i < n; i++) {
		// add position i
		for(int j = 0; j < 26; j++) {
			cur[j] = (fmul(cur[j], ba) + 1) % MOD;
		}
		cur[s[i]-'a'] = (cur[s[i]-'a'] + 1) % MOD;
		// check
		for(int j = 0; j < 26; j++) {
			h1[j] = {cur[j], hashes[j]};
			h2[j] = {hashes[j], cur[j]};
		}
		std::sort(h1.begin(), h1.end());
		std::sort(h2.begin(), h2.end());
		if(h1 == h2) {
			ans.push_back(i-(m-1)+1);
		}
		// remove position i-(m-1)
		for(int j = 0; j < 26; j++) {
			cur[j] = (cur[j] - ha + MOD) % MOD;
		}
		cur[s[i-(m-1)]-'a'] = (cur[s[i-(m-1)]-'a'] - ha + MOD) % MOD;
	}
	std::cout << ans.size() << '\n';
	for(int i = 0; i < (int) ans.size(); i++) {
		std::cout << ans[i] << (i + 1 == (int) ans.size() ? '\n' : ' ');
	}
}