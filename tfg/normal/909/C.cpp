#include <iostream>

typedef long long ll;

const ll MOD = 1e9 + 7;

char a[5050];
int dp[5050][5050];

int main() {
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	/*int ways = 1;
	for(int i = 0; i < n; i++) {
		if(a[i] == 'f') {
			int cur = 0;
			for(int j = i + 1; j < n; j++) {
				if(a[j] == 's') {
					cur++;
				}
			}
			ways = (ll) ways * cur % MOD;
		}
	}*/
	dp[0][0] = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			//std::cout << dp[i][j] << ' ';
		}
		//std::cout << '\n';
		if(a[i] == 'f') {
			for(int j = 1; j < n; j++) {
				dp[i + 1][j] = dp[i][j - 1];
			}
		} else {
			for(int j = n - 2; j >= 0; j--) {
				dp[i][j] = (dp[i][j] + dp[i][j + 1]) % MOD;
			}
			for(int j = 0; j < n; j++) {
				dp[i + 1][j] = dp[i][j];
			}
		}
	}
	std::cout << dp[n][0] << '\n';
}