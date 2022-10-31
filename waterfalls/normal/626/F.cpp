#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9+7;
int add(int a, int b) { return a+b-(a+b>=MOD)*MOD; }
int sub(int a, int b) { return a-b+(a-b<0)*MOD; }
int mult(int a, int b) { return ((ll) a*b)%MOD; }

int n,lim;
int a[213];
int dp[2][113][1013];

int main() {
	scanf("%d%d",&n,&lim);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	dp[0][0][0] = 1;
	for (int i=0;i<n;i++) {
		int w = i&1;
		memset(dp[w^1],0,sizeof dp[w^1]);
		for (int j=0;j<=min(i,n/2);j++) {
			for (int k=0;k<=lim;k++) if (k+(a[i+1]-a[i])*j<=lim) {
				// open
				if (j<n/2) dp[w^1][j+1][k+(a[i+1]-a[i])*j] = add(dp[w^1][j+1][k+(a[i+1]-a[i])*j],dp[w][j][k]);
				// close
				if (j) dp[w^1][j-1][k+(a[i+1]-a[i])*j] = add(dp[w^1][j-1][k+(a[i+1]-a[i])*j],mult(dp[w][j][k],j));
				// open and close or nothing
				dp[w^1][j][k+(a[i+1]-a[i])*j] = add(dp[w^1][j][k+(a[i+1]-a[i])*j],mult(dp[w][j][k],j+1));
			}
		}
	}
	int ans = 0;
	for (int k=0;k<=lim;k++) ans = add(ans,dp[n&1][0][k]);
	printf("%d\n",ans);

	return 0;
}