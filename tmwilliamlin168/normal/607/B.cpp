#include <bits/stdc++.h>
using namespace std;
 
const int mxN=500;
int n, c[mxN], dp[mxN][mxN][2];
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> c[i];
	for(int i=n-1; ~i; --i) {
		dp[i][i][0]=0;
		dp[i][i][1]=1;
		for(int j=i+1; j<n; ++j) {
			dp[i][j][0]=dp[i][j][1]=1e9;
			if(c[i]==c[j])
				dp[i][j][0]=min(dp[i][j][0], dp[i+1][j-1][0]);
			for(int k=i; k<j; ++k)
				dp[i][j][0]=min({dp[i][j][0], dp[i][k][0]+dp[k+1][j][1], dp[i][k][1]+dp[k+1][j][0]});
			dp[i][j][1]=min(dp[i][j][1], dp[i][j][0]+1);
		}
	}
	cout << dp[0][n-1][1];
}