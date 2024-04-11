#include <iostream>
#include <cstring>

typedef long long ll;

const int MOD = 998244353;
const int ms = 2020;

int dp[2][ms][ms][11];
int freq[2][11];
int tot[2];

int fat[2 * ms];
int comb[2 * ms][2 * ms];

int size(int n) {
	if(n == 0) {
		return 0;
	} else {
		return 1 + size(n / 10);
	}
}

int main() {
	for(int i = 0; i < 2 * ms; i++) {
		comb[i][0] = 1;
		for(int j = 1; j <= i; j++) {
			comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
		}
	}
	fat[0] = 1;
	for(int i = 1; i < 2 * ms; i++) {
		fat[i] = (ll) fat[i - 1] * i % MOD;
	}
	int t;
	std::cin >> t;
	dp[0][0][0][0] = 1;
	dp[1][0][0][0] = 1;
	while(t--) {
		int n;
		std::cin >> n;
		memset(freq, 0, sizeof freq);
		memset(tot, 0, sizeof tot);
		while(n--) {
			int card;
			std::cin >> card;
			freq[size(card) % 2][card % 11]++;
			tot[size(card) % 2]++;
		}
		for(int p = 0; p < 2; p++) {
			int got = 0;
			for(int v = 0; v < 11; v++) {
				while(freq[p][v]--) {
					//std::cout << "got for (" << p << ", " << v << ")\n";
					got++;
					for(int i = 0; i <= got; i++) {
						int j = got - i;
						memset(dp[p][i][j], 0, sizeof dp[p][i][j]);
						if(j) {
							for(int k = 0; k < 11; k++) {
								dp[p][i][j][k] = (dp[p][i][j][k] + dp[p][i][j - 1][(k + v) % 11]) % MOD;
							}
						}
						if(i) {
							for(int k = 0; k < 11; k++) {
								dp[p][i][j][k] = (dp[p][i][j][k] + dp[p][i - 1][j][(k - v + 11) % 11]) % MOD;
							}
						}
						/*for(int k = 0; k < 11; k++) {
							if(dp[p][i][j][k]) {
								std::cout << "(" << p << ", " << i << ", " << j << ", " << k << ") = " << dp[p][i][j][k] << "\n";
							}
						}*/
					}
				}
			}
		}
		int pos = (tot[1] + 1) / 2;
		int neg = (tot[1]) / 2;
		int pos_slot = neg + 1;
		int neg_slot = pos;
		int ans = 0;
		//std::cout << "(" << pos << ", " << neg << ")\n";
		//std::cout << "(" << pos_slot << ", " << neg_slot << ")\n";
		for(int i = 0; i <= tot[0]; i++) {
			int j = tot[0] - i;
			if(j && neg_slot == 0) {
				continue;
			}
			for(int k = 0; k < 11; k++) {
				ll cur = (ll)dp[0][i][j][k] * dp[1][pos][neg][(11 - k) % 11] % MOD;
				//std::cout << "on (" << i << ", " << j << ", " << k << ") got " << cur << "\n";
				cur = cur * fat[pos] % MOD * fat[neg] % MOD;
				cur = cur * fat[i] % MOD * fat[j] % MOD;
				//std::cout << "on (" << i << ", " << j << ", " << k << ") got " << cur << "\n";
				if(i)
				cur = cur * comb[i + pos_slot - 1][pos_slot - 1] % MOD;
				if(j)
				cur = cur * comb[j + neg_slot - 1][neg_slot - 1] % MOD;
				//std::cout << "on (" << i << ", " << j << ", " << k << ") got " << cur << "\n";
				ans = (ans + cur) % MOD;
			}
		}
		std::cout << ans << '\n';
	}
}