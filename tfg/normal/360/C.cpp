#include <iostream>

typedef long long ll;

const int MOD = 1e9 + 7;
const int ms = 2020;

int dp[ms][ms];
int eq[ms];

int main() {
	int n, k;
	std::cin >> n >> k;
	std::string str;
	std::cin >> str;
	str = '#' + str;
	n++;
	dp[0][0] = 1;
	for(int i = 0; i < n; i++) {
		int diff = 0;
		for(int sum = 0; sum <= k; sum++) {
			int v = dp[i][sum];

			dp[i][sum] = (dp[i][sum] + eq[sum] * (ll)(str[i] - 'a')) % MOD;
			
			eq[sum] = (eq[sum] + dp[i][sum]) % MOD;
		}
		//std::cout << "on " << i << std::endl;
		//for(int sum = 0; sum <= k; sum++) std::cout << dp[i][sum] << (sum == k ? '\n' : ' ');
		//for(int sum = 0; sum <= k; sum++) std::cout << eq[sum] << (sum == k ? '\n' : ' ');
		ll choices = 1;
		for(int j = i + 1; j < n; j++) {
			diff = (j - i) * (n - j);
			//if(j > i + 1) {
			for(int sum = 0; sum + diff <= k; sum++) {
				dp[j][sum + diff] = (dp[j][sum + diff] + (ll) dp[i][sum] * ('z' - str[j])) % MOD;
			}
			/*} else {
				for(int sum = 0; sum <= k; sum++) {
					dp[j][sum] = (dp[i][sum] * (ll)(str[j] - 'a') + dp[j][sum]) % MOD;
				}
			}*/
		}
	}
	std::cout << (eq[k]) % MOD << std::endl;
}