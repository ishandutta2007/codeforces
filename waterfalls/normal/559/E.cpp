#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second

int n;
pair<int,int> light[113];
int dp[113][113];

int main() {
	for (int i=0;i<113;i++) for (int j=0;j<113;j++) dp[i][j] = -1e9;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&light[i].A,&light[i].B);
	light[0] = MP(-2e8,0);
	sort(light,light+n+1);
	dp[0][0] = 0;
	for (int i=0;i<n;i++) for (int j=0;j<=i;j++) if (dp[i][j]>=0) {
		int cur = (j ? light[j].A+light[j].B : light[i].A);
		int high = -1;
		int which = 0;
		for (int k=i+1;k<=n;k++) if (light[k].A+light[k].B>cur) {
			dp[k][k] = max(dp[k][k],dp[i][j]+light[k].A+light[k].B-max(cur,light[k].A));
			if (light[k].A>high) high = light[k].A, which = 0;
			dp[k][which] = max(dp[k][which],dp[i][j]+high-max(cur,light[k].A-light[k].B));
			if (light[k].A+light[k].B>high) high = light[k].A+light[k].B, which = k;
		}
	}
	int ans = 0;
	for (int i=0;i<=n;i++) for (int j=0;j<2*i+2;j++) ans = max(ans,dp[i][j]);
	printf("%d\n",ans);

	return 0;
}