#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int dp[51][51][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> p(n);
	int c[2]={(n+1)/2, n/2};
	for(int i=0; i<n; ++i) {
		cin >> p[i], --p[i];
		if(~p[i])
			p[i]&=1;
	}
	for(int i=0; i<=(n+1)/2; ++i) {
		for(int j=0; j<=n/2; ++j) {
			if(!i&&!j)
				continue;
			dp[i][j][0]=dp[i][j][1]=1e9;
			if(i)
				dp[i][j][0]=min(dp[i-1][j][0], dp[i-1][j][1]+1);
			if(j)
				dp[i][j][1]=min(dp[i][j-1][0]+1, dp[i][j-1][1]);
			if(~p[i+j-1])
				dp[i][j][p[i+j-1]^1]=1e9;
		}
	}
	cout << min(dp[(n+1)/2][n/2][0], dp[(n+1)/2][n/2][1]);
}