#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,s,e;
int x[5013];
int a[5013], b[5013], c[5013], d[5013];
ll dp[5013][5013];

int main() {
	scanf("%d%d%d",&n,&s,&e);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	for (int i=1;i<=n;i++) scanf("%d",&d[i]);
	memset(dp,0x7F,sizeof dp);
	dp[0][0] = 0;
	for (int i=1;i<=n;i++) {
		int diff = 0;
		if (s<i && e>=i) diff = 1;
		if (e<i && s>=i) diff = -1;
		for (int j=0;j<=n;j++) {
			int k = j-diff;
			if (k<0) continue;
			if (i==s) {
				if (k) dp[i][j] = min(dp[i][j],dp[i-1][j]+c[i]+x[i]);
				dp[i][j+1] = min(dp[i][j+1],dp[i-1][j]+d[i]-x[i]);
			} else if (i==e) {
				if (j) dp[i][j-1] = min(dp[i][j-1],dp[i-1][j]+a[i]+x[i]);
				dp[i][j] = min(dp[i][j],dp[i-1][j]+b[i]-x[i]);
			} else {
				if (j && k) dp[i][j-1] = min(dp[i][j-1],dp[i-1][j]+c[i]+a[i]+2*x[i]);
				if (k) dp[i][j] = min(dp[i][j],dp[i-1][j]+c[i]+b[i]);
				if (j) dp[i][j] = min(dp[i][j],dp[i-1][j]+d[i]+a[i]);
				dp[i][j+1] = min(dp[i][j+1],dp[i-1][j]+d[i]+b[i]-2*x[i]);
			}
		}
		if (i==n) continue;
		diff = 0;
		if (s<=i && e>i) diff = 1;
		if (e<=i && s>i) diff = -1;
		for (int j=0;j<=n;j++) {
			int k = j-diff;
			if (j<=0 && k<=0) dp[i][j] = 1e18;
		}
	}
	printf("%lld\n",dp[n][0]);

	return 0;
}