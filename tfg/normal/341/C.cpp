#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

const int ms = 2020;
const int MOD = 1e9 + 7;

ll fexp(ll x, int e = MOD - 2) {
	ll ans = 1;
	for(; e > 0; e /= 2) {
		if(e & 1) {
			ans = ans * x % MOD;
		}
		x = x * x % MOD;
	}
	return ans;
}

ll fat[ms], ifat[ms];
ll comb(int n, int a) {
	return fat[n] * ifat[a] % MOD * ifat[n - a] % MOD;
}

ll dp[ms][ms];

int brute(int n) {
	std::vector<int> p(n);
	for(int i = 0; i < n; i++) {
		p[i] = i;
	}
	int ans = 0;
	do {
		bool valid = true;
		for(int i = 0; i < n; i++) {
			valid = valid && p[i] != i;
		}
		if(valid) ans++;
	} while(std::next_permutation(p.begin(), p.end()));
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 1; i < 6; i++) {
		//std::cout << i << ": " << brute(i) << std::endl;
	}
	fat[0] = ifat[0] = 1;
	for(int i = 1; i < ms; i++) {
		fat[i] = i * fat[i - 1] % MOD;
		ifat[i] = fexp(fat[i]);
	}
	dp[0][0] = 1;
	for(int i = 2; i < ms; i++) {
		for(int j = 0; j + 1 < i; j++) {
			dp[0][i] = (dp[0][i] + dp[0][j] * comb(i - 1, i - j - 1) % MOD * fat[i - j - 1]) % MOD;
		}
	}
	for(int i = 1; i < ms; i++) {
		dp[i][0] = fat[i];
		for(int j = 1; j < ms; j++) {
			dp[i][j] = (dp[i - 1][j] * i + dp[i][j - 1] * j) % MOD;
		}
	}
	int n;
	std::cin >> n;
	std::vector<int> p(n, -1);
	std::vector<int> inv(n, -1);
	for(int i = 0; i < n; i++) {
		std::cin >> p[i];
		if(p[i] != -1) {
			p[i]--;
			inv[p[i]] = i;
		}
	}
	// second is free
	// first is group
	int freq[2] = {0, 0};
	for(int i = 0; i < n; i++) {
		//std::cout << "(" << p[i] << ", " << inv[i] << ")\n";
		if(p[i] == -1 && inv[i] != -1) {
			freq[0]++;
		} else if(p[i] == -1 && inv[i] == -1) {
			freq[1]++;
		}
	}
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			//std::cout << dp[i][j] << (j == 9 ? '\n' : ' ');
		}
	}
	//std::cout << "(" << freq[0] << ", " << freq[1] << ")\n";
	std::cout << dp[freq[0]][freq[1]] << std::endl;
}