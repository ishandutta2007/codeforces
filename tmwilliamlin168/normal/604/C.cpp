#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5;
int n, dp[3][mxN+1][2];
string s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s;
	for(int k=0; k<3; ++k) {
		for(int i=1; i<=n; ++i) {
			int c=s[i-1]-'0';
			dp[k][i][c]=max(dp[k][i-1][c^1]+1, dp[k][i-1][c]);
			dp[k][i][c^1]=dp[k][i-1][c^1];
			if(k)
				dp[k][i][c]=max(dp[k-1][i-1][c]+1, dp[k][i][c]);
		}
	}
	cout << max(dp[2][n][0], dp[2][n][1]);
}