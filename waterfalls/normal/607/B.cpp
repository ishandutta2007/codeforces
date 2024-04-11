#include <bits/stdc++.h>
using namespace std;

int n;
int c[513];
int dp[513][513][2];

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	for (int i=0;i<=n+1;i++) for (int j=0;j<=n+1;j++) dp[i][j][0] = dp[i][j][1] = 1e9;
	for (int i=0;i<=n;i++) dp[i+1][i][0] = dp[i+1][i][1] = 0;
	for (int i=0;i<=n;i++) dp[i+2][i][0] = dp[i+2][i][1] = 0;
	for (int i=n;i>=1;i--) for (int j=i;j<=n;j++) for (int b=0;b<2;b++) {
		if (c[i]==c[j]) dp[i][j][b] = min(dp[i][j][b],dp[i+1][j-1][1]+(b==0));
		for (int k=i;k<j;k++) dp[i][j][b] = min(dp[i][j][b],dp[i][k][0]+dp[k+1][j][b]);
		for (int k=j;k>i;k--) dp[i][j][b] = min(dp[i][j][b],dp[i][k-1][b]+dp[k][j][0]);
	}
	printf("%d\n",dp[1][n][0]);

	return 0;
}