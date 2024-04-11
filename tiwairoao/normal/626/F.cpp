#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 200;
const int MAXK = 1000;
const int MOD = int(1E9) + 7;
int a[MAXN + 5], dp[MAXN + 5][MAXN + 5][MAXK + 5];
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i=1;i<=n;i++)
		scanf("%d", &a[i]);
	sort(a+1, a+n+1);
	dp[0][0][0] = 1;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<i;j++) {
			int p = j*(a[i]-a[i-1]);
			for(int l=p;l<=k;l++)
				dp[i][j][l] = 1LL*dp[i-1][j][l-p]*(j+1)%MOD;
		}
		for(int j=0;j<i;j++) {
			int p = j*(a[i]-a[i-1]);
			for(int l=p;l<=k;l++)
				dp[i][j+1][l] = (dp[i][j+1][l] + dp[i-1][j][l-p])%MOD;
		}
		for(int j=1;j<i;j++) {
			int p = j*(a[i]-a[i-1]);
			for(int l=p;l<=k;l++)
				dp[i][j-1][l] = (dp[i][j-1][l] + 1LL*dp[i-1][j][l-p]*j%MOD)%MOD;
		}
	}
	int ans = 0;
	for(int i=0;i<=k;i++)
		ans = (ans + dp[n][0][i]) % MOD;
	printf("%d\n", ans);
}