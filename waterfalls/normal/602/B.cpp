#include <bits/stdc++.h>
using namespace std;

int n;
int a[100013];
int dp[100013][2];

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	a[0] = a[1]-2;
	for (int i=1;i<=n;i++) {
		dp[i][0] = dp[i][1] = 1;
		if (a[i]==a[i-1]+1) dp[i][1] = 1+dp[i-1][0];
		if (a[i]==a[i-1]-1) dp[i][0] = 1+dp[i-1][1];
		if (a[i]==a[i-1]) dp[i][0] = dp[i-1][0]+1;
		if (a[i]==a[i-1]) dp[i][1] = dp[i-1][1]+1;
	}
	int ans = 0;
	for (int i=1;i<=n;i++) ans = max(ans,max(dp[i][0],dp[i][1]));
	printf("%d\n",ans);

	return 0;
}