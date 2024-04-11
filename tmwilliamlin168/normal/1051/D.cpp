#include <bits/stdc++.h>
using namespace std;

const int mxN=1e3, M=998244353;
int n, k;
long long dp[2][2*mxN+2][2];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	dp[0][0][0]=2;
	dp[0][1][1]=2;
	for(int i=0; i<n-1; ++i) {
		memset(dp[i&1^1], 0, sizeof(dp[i&1^1]));
		for(int j=0; j<2*n; ++j) {
			dp[i&1][j][0]%=M;
			dp[i&1][j][1]%=M;
			dp[i&1^1][j][0]+=dp[i&1][j][0]+2*dp[i&1][j][1];
			dp[i&1^1][j+1][0]+=dp[i&1][j][0];
			dp[i&1^1][j+1][1]+=2*dp[i&1][j][0];
			dp[i&1^1][j][1]+=dp[i&1][j][1];
			dp[i&1^1][j+2][1]+=dp[i&1][j][1];
		}
	}
	cout << (dp[n&1^1][k-1][0]+dp[n&1^1][k-1][1])%M;
}