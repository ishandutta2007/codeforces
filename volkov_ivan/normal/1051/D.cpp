#include <iostream>
#define int long long
 
using namespace std;

const int MAX_N = 1007, M = 998244353;
int dp[MAX_N][2 * MAX_N][4];
 
signed main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = dp[i][j][3] = 0;
		}
	}
	dp[1][1][0] = dp[1][1][3] = 1;
	dp[1][2][1] = dp[1][2][2] = 1;
	for (int j = 1; j <= k; j++) {
		for (int i = 1; i < n; i++) {
			dp[i + 1][j][0] = (dp[i + 1][j][0] + dp[i][j][0]) % M;
			dp[i + 1][j + 1][1] = (dp[i + 1][j + 1][1] + dp[i][j][0]) % M;
			dp[i + 1][j + 1][2] = (dp[i + 1][j + 1][2] + dp[i][j][0]) % M;
			dp[i + 1][j + 1][3] = (dp[i + 1][j + 1][3] + dp[i][j][0]) % M;
			//fuf
			dp[i + 1][j][0] = (dp[i + 1][j][0] + dp[i][j][1]) % M;
			dp[i + 1][j][1] = (dp[i + 1][j][1] + dp[i][j][1]) % M;
			dp[i + 1][j + 2][2] = (dp[i + 1][j + 2][2] + dp[i][j][1]) % M;
			dp[i + 1][j][3] = (dp[i + 1][j][3] + dp[i][j][1]) % M;
			//fuf
			dp[i + 1][j][0] = (dp[i + 1][j][0] + dp[i][j][2]) % M;
			dp[i + 1][j + 2][1] = (dp[i + 1][j + 2][1] + dp[i][j][2]) % M;
			dp[i + 1][j][2] = (dp[i + 1][j][2] + dp[i][j][2]) % M;
			dp[i + 1][j][3] = (dp[i + 1][j][3] + dp[i][j][2]) % M;
			//fuf
			dp[i + 1][j + 1][0] = (dp[i + 1][j + 1][0] + dp[i][j][3]) % M;
			dp[i + 1][j + 1][1] = (dp[i + 1][j + 1][1] + dp[i][j][3]) % M;
			dp[i + 1][j + 1][2] = (dp[i + 1][j + 1][2] + dp[i][j][3]) % M;
			dp[i + 1][j][3] = (dp[i + 1][j][3] + dp[i][j][3]) % M;
		}
	}
	int ans1 = (dp[n][k][0] + dp[n][k][1]) % M;
	int ans2 = (dp[n][k][2] + dp[n][k][3]) % M;
	cout << (ans1 + ans2) % M << endl;
    return 0;
}