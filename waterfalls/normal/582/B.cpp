#include <bits/stdc++.h>
using namespace std;

int n,T;
int seq[10013];
int dp[10013];
int dp2[10013];
int last[313];
int has[313];
int best[313][313];

int main() {
	scanf("%d%d",&n,&T);
	for (int i=1;i<=n;i++) {
		int a;
		scanf("%d",&a);
		for (int j=0;j<n;j++) seq[j*n+i] = a;
		has[a]+=1;
	}
	seq[0] = 0;
	for (int i=1;i<=n*n;i++) {
		dp[i] = 1;
		for (int j=0;j<=seq[i];j++) if (last[j]) dp[i] = max(dp[i],1+dp[last[j]]);
		last[seq[i]] = i;
	}
	for (int i=0;i<313;i++) last[i] = 0;
	seq[n*n+1] = 312;
	for (int i=n*n;i>=1;i--) {
		dp2[i] = 1;
		for (int j=seq[i];j<313;j++) if (last[j]) dp2[i] = max(dp2[i],1+dp2[last[j]]);
		last[seq[i]] = i;
	}
	for (int i=0;i<313;i++) for (int j=i;j<313;j++) {
		for (int k=i;k<=j;k++) best[i][j] = max(best[i][j],has[k]);
	}
	int ans = 0;
	for (int i=0;i<=n*n;i++) for (int j=1;j<=n*n+1;j++) {
		if (seq[i]<=seq[j] && i+(n*n+1-j)<=n*T) {
			int num1 = (i+n-1)/n;
			int num2 = (n*n+1-j+n-1)/n;
			ans = max(ans,dp[i]+dp2[j]+(T-num1-num2)*best[seq[i]][seq[j]]);
		}
	}
	printf("%d\n",ans);

	return 0;
}