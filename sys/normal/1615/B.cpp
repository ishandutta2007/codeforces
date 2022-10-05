#include <bits/stdc++.h>
using namespace std;

int T, sum[200005][31];
int main()
{
	scanf("%d", &T);
	for (int i = 1; i <= 200000; i++)
	{
		int tmp = i;
		for (int j = 0; j <= 30; j++)
		{
			if (tmp & 1)
				sum[i][j] = sum[i - 1][j] + 1;
			else sum[i][j] = sum[i - 1][j];
			tmp >>= 1;
		}
	}
	while (T--)
	{
		int l, r, ans = 0;
		scanf("%d%d", &l, &r);
		for (int i = 0; i <= 30; i++)
			ans = max(ans, sum[r][i] - sum[l - 1][i]);
		printf("%d\n", r - l + 1 - ans);
	}
	return 0;
}