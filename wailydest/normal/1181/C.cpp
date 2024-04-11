#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1000;

char buf[N + 1];
char a[N][N];
int dp[N][N];
int ans[N][N];

int main() 
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%s", a[i]);
	for (int j = 0; j < m; ++j) {
		dp[n - 1][j] = 1;
		for (int i = n - 2; i >= 0; --i) dp[i][j] = a[i][j] == a[i + 1][j] ? dp[i + 1][j] + 1 : 1;
	}
	for (int i = 0; i < n; ++i) {
		if (i + 2 * dp[i][m - 1] < n && dp[i][m - 1] == dp[i + dp[i][m - 1]][m - 1] && dp[i + 2 * dp[i][m - 1]][m - 1] >= dp[i][m - 1]) ans[i][m - 1] = 1;
		for (int j = m - 2; j >= 0; --j) {
			if (ans[i][j + 1] && dp[i][j] == dp[i][j + 1] && a[i][j] == a[i][j + 1] && dp[i + dp[i][j]][j] == dp[i][j] && a[i + dp[i][j]][j] == a[i + dp[i][j]][j + 1] && dp[i + 2 * dp[i][j]][j] >= dp[i][j] && a[i + 2 * dp[i][j]][j] == a[i + 2 * dp[i][j]][j + 1]) ans[i][j] = ans[i][j + 1] + 1;
			else if (i + 2 * dp[i][j] < n && dp[i][j] == dp[i + dp[i][j]][j] && dp[i + 2 * dp[i][j]][j] >= dp[i][j]) ans[i][j] = 1;
		}
	}
	int res = 0;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res += ans[i][j];
	printf("%d\n", res);
	return 0;
}