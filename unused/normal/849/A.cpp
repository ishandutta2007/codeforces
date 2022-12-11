#include <bits/stdc++.h>
using namespace std;

int a[105];
bool dp[105], ep[105];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	ep[0] = true;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] % 2 == 0) continue;

		for (int j = i; j >= 1; j -= 2)
		{
			if (a[j] % 2 == 0) continue;
			dp[i] |= ep[j - 1];
			ep[i] |= dp[j - 1];
		}
	}

	if (dp[n]) printf("Yes\n");
	else printf("No\n");
}