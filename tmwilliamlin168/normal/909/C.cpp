#include <bits/stdc++.h>
using namespace std;

const int mxN=5000, M=1e9+7;

int dp[2][mxN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	dp[0][0]=1;
	int n, t=0;
	cin >> n;
	for(int i=1; i<n; ++i) {
		char c;
		cin >> c;
		if(c=='f') {
			for(int j=n-1; j>0; --j)
				dp[i&1][j]=dp[i&1^1][j-1];
			dp[i&1][0]=0;
		} else {
			dp[i&1][n-1]=dp[i&1^1][n-1];
			for(int j=n-2; j>=0; --j)
				dp[i&1][j]=(dp[i&1][j+1]+dp[i&1^1][j])%M;
		}
	}
	for(int i=0; i<n; ++i)
		t=(t+dp[n&1^1][i])%M;
	cout << t;
}