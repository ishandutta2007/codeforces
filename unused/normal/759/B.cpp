#include <bits/stdc++.h>
using namespace std;

int dat[100005];
int dp[100005];

int main()
{
	int n;
	scanf("%d", &n);
	int last = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &dat[i]);

		int a1 = 20 + last;
		int idx1 = (int)(lower_bound(dat, dat + i, dat[i] - 89) - dat) - 1;
		int a2 = 50 + (idx1 < 0 ? 0 : dp[idx1]);
		int idx2 = (int)(lower_bound(dat, dat + i, dat[i] - 1439) - dat) - 1;
		int a3 = 120 + (idx2 < 0 ? 0 : dp[idx2]);

		dp[i] = min({ a1, a2, a3 });
		printf("%d\n", dp[i] - last);
		last = dp[i];
	}
}