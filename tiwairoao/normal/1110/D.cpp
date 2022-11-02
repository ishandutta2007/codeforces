#include<cstdio>
#include<algorithm>
using namespace std;
const int INF = int(1E9);
const int MAXN = 1000000 + 5;
int a[MAXN], dp[2][10][10];
int main() {
	int n, m; scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++) {
		int x; scanf("%d", &x);
		a[x]++;
	}
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			dp[0][i][j] = -INF;
	dp[0][0][0] = 0;
	for(int i=3;i<=m;i++) {
		for(int j=0;j<10;j++)
			for(int k=0;k<10;k++)
				dp[i&1][j][k] = -INF;
		for(int j=0;j<10;j++)
			for(int k=0;k<10;k++) {
				if( a[i-2] >= j && a[i-1] >= k ) {
					dp[i&1][k][0] = max(dp[i&1][k][0], dp[i&1^1][j][k] + (a[i-2] - j)/3);
				}
				if( a[i-2] >= j + 1 && a[i-1] >= k + 1 && a[i] >= 1 && k < 9 ) {
					dp[i&1][k+1][1] = max(dp[i&1][k+1][1], dp[i&1^1][j][k] + (a[i-2] - j - 1)/3 + 1);
				}
				if( a[i-2] >= j + 2 && a[i-1] >= k + 2 && a[i] >= 2 && k < 8 ) {
					dp[i&1][k+2][2] = max(dp[i&1][k+2][2], dp[i&1^1][j][k] + (a[i-2] - j - 2)/3 + 2);
				}
			}
				
	}
	int ans = 0;
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			if( a[m-1] >= i && a[m] >= j )
				ans = max(ans, dp[m&1][i][j] + (a[m-1] - i)/3 + (a[m] - j)/3);
	printf("%d\n", ans);
}