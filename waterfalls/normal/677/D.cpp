#include <bits/stdc++.h>
using namespace std;

int n,m,p;
int grid[313][313];
vector<int> has[313][313];
int dp[313][313];
int close[313];

int main() {
	scanf("%d%d%d",&n,&m,&p);
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			scanf("%d",&grid[i][j]);
		}
	}
	dp[0][0] = 0;
	for (int k=0;k<p;k++) {
		if (k%n==0) {
			for (int i=0;i<=n;i++) {
				for (int j=0;j<n;j++) has[i][j].clear();
			}
			if (k==0) has[0][0].push_back(0);
			for (int i=0;i<n;i++) {
				for (int j=0;j<m;j++) {
					if (k<=grid[i][j] && grid[i][j]<=k+n) {
						has[grid[i][j]-k][i].push_back(j);
					}
				}
			}
		}
		memset(close,0x7F,sizeof close);
		for (int i=0;i<n;i++) {
			for (int j: has[k%n][i]) {
				close[j] = min(close[j],dp[i][j]-i);
			}
			for (int j: has[k%n+1][i]) {
				dp[i][j] = 1e9;
				for (int a=0;a<m;a++) {
					dp[i][j] = min(dp[i][j],abs(a-j)+close[a]+i);
				}
			}
		}
		memset(close,0x7F,sizeof close);
		for (int i=n-1;i>=0;i--) {
			for (int j: has[k%n][i]) {
				close[j] = min(close[j],dp[i][j]+i);
			}
			for (int j: has[k%n+1][i]) {
				for (int a=0;a<m;a++) {
					dp[i][j] = min(dp[i][j],abs(a-j)+close[a]-i);
				}
			}
		}
	}
	int ans = 1e9;
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			if (grid[i][j]==p) ans = min(ans,dp[i][j]);
		}
	}
	printf("%d\n",ans);

	return 0;
}