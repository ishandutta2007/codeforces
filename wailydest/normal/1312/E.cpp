#include <iostream>
#include <vector>
using namespace std;

int main() 
{
	int n;
	scanf("%d", &n);
	int a[500];
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	vector<vector<int> > fin(n, vector<int>(n));
	for (int i = 0; i < n; ++i) fin[i][i] = a[i];
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < n - i; ++j) {
			for (int k = j; k < j + i; ++k) if (fin[j][k] && fin[j][k] == fin[k + 1][j + i]) fin[j][j + i] = fin[j][k] + 1;
		}
	}
	vector<int> dp(n);
	dp[0] = 1;
	for (int i = 1; i < n; ++i) {
		dp[i] = dp[i - 1] + 1;
		for (int j = i - 1; j > 0; --j) if (fin[j][i]) dp[i] = min(dp[i], 1 + dp[j - 1]);
		if (fin[0][i]) dp[i] = 1;
	}
	printf("%d\n", dp[n - 1]);
	return 0;
}