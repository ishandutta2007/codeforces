#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 5000;
const long long INF = (1ll<<60);
long long dp[2][MAXN + 5][MAXN + 5];
int a[MAXN + 5];
int main() {
	int n;
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &a[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dp[0][i][j] = dp[1][i][j] = INF;
	for(int i=1;i<=n;i++)
		dp[0][i][0] = 0;
	dp[1][1][1] = 0;
	for(int i=2;i<=n;i++) {
		dp[0][i][1] = min(dp[0][i-1][1], dp[1][i-1][1] + max(0, a[i]-(a[i-1]-1)));
		dp[1][i][1] = max(0, a[i-1]-(a[i]-1));
	}
	for(int i=2;i<=(n+1)/2;i++) {
		dp[1][2*i-1][i] = dp[1][2*i-3][i-1] + max(0, a[2*i-2]-min(a[2*i-1]-1, a[2*i-3]-1));
		for(int j=2*i;j<=n;j++) {
			dp[0][j][i] = min(dp[0][j-1][i], dp[1][j-1][i] + max(0, a[j]-(a[j-1]-1)));
			dp[1][j][i] = min(dp[0][j-2][i-1]+max(0, a[j-1]-(a[j]-1)), dp[1][j-2][i-1]+max(0,a[j-1]-min(a[j]-1, a[j-2]-1)));
		}
	}
	printf("%I64d", min(dp[0][n][1], dp[1][n][1]));
	for(int i=2;i<=(n+1)/2;i++)
		printf(" %I64d", min(dp[0][n][i], dp[1][n][i]));
	puts("");
}