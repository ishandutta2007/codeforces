#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 503;
int n, k;
bool dp[N][N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	dp[0][0] = 1;
	while(n--)
	{
		int x;
		scanf("%d", &x);
		for (int i = k; i >= 0; i--)
			for (int j = k; j >= 0; j--)
			{
				if (!dp[i][j]) continue;
				if (i + x <= k)
					dp[i + x][j] = 1;
				if (j + x <= k)
					dp[i][j + x] = 1;
			}
	}
	int cnt = 0;
	for (int i = 0; i <= k; i++)
		cnt += dp[i][k - i];
	printf("%d\n", cnt);
	for (int i = 0; i <= k; i++)
		if (dp[i][k - i])
			printf("%d ", i);
	printf("\n");

	return 0;
}