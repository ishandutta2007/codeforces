#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=1e5, M=998244353, mxA=200;
int n, a[mxN];
ll dp[mxN+1][mxA+1][2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	for(int i=0; i<=mxA; ++i)
		dp[0][i][1]=1;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=mxA; ++j) {
			if(a[i-1]==-1||j==a[i-1]) {
				dp[i][j][0]=(dp[i-1][j-1][0]+dp[i-1][j-1][1])%M;
				dp[i][j][1]=(dp[i-1][mxA][1]-dp[i-1][j-1][1]+dp[i-1][j][0]-dp[i-1][j-1][0]+2*M)%M;
			}
			dp[i][j][0]=(dp[i][j][0]+dp[i][j-1][0])%M;
			dp[i][j][1]=(dp[i][j][1]+dp[i][j-1][1])%M;
		}
	}
	cout << dp[n][mxA][1]%M;
}