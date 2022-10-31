#include <cstdio>
#include <algorithm>

using namespace std;

int n,m;
char s[21][21];
int a[21][21];
int has[21][21];
int cost[21][21];
int dp[1<<20];

int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf(" %s",&s[i]);
	for (int i=0;i<n;i++) for (int j=0;j<m;j++) scanf("%d",&a[i][j]);
	for (int i=0;i<n;i++) for (int j=0;j<m;j++) {
		int high = 0;
		for (int k=0;k<n;k++) if (s[i][j]==s[k][j]) {
			cost[i][j]+=a[k][j];
			high = max(high,a[k][j]);
			has[i][j]|=(1<<k);
		}
		cost[i][j]-=high;
	}
	for (int i=0;i<(1<<n);i++) dp[i] = 1e9;
	dp[0] = 0;
	for (int i=0;i<(1<<n)-1;i++) {
		int b = 0;
		for (int j=0;j<n;j++) if ((i&(1<<j))==0) b = j;
		for (int j=0;j<m;j++) {
			dp[i|(1<<b)] = min(dp[i|(1<<b)],dp[i]+a[b][j]);
			dp[i|has[b][j]] = min(dp[i|has[b][j]],dp[i]+cost[b][j]);
		}
	}
	printf("%d\n",dp[(1<<n)-1]);

	return 0;
}