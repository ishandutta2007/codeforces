#include <cstdio>
#include <algorithm>

const int N = 100000;
const int K = 5;
int a[N];
int dp[N][K + 1];
int t, n, k, z;

int main() 
{
	scanf("%d", &t);
	while (t--) {
		int ans = 0;
		scanf("%d%d%d", &n, &k, &z);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= z; ++j) if (i + j * 2 <= k) {
				dp[i][j] = (i ? dp[i - 1][j] : 0) + a[i];
				ans = std::max(ans, dp[i][j]);
			}
			for (int j = 0; j < z; ++j) if (i + (j + 1) * 2 <= k) {
				dp[i][j + 1] = std::max(dp[i][j + 1], dp[i][j] + a[i + 1] + a[i]);
				ans = std::max(ans, dp[i][j + 1]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}