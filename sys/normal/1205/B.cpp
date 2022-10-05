#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, G[125][125], dis[125][125], ans = 0x3f3f3f3f;
long long a[Maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		if (!a[i]) n--, i--;
	}
	if (n > 120)
	{
		printf("3");
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		dis[i][i] = 10000000;
		for (int j = i + 1; j <= n; j++)
			if (a[i] & a[j]) dis[i][j] = dis[j][i] = G[i][j] = G[j][i] = 1;
			else dis[i][j] = dis[j][i] = G[i][j] = G[j][i] = 10000000;
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i < k; i++)
			for (int j = 1; j < k; j++)
				ans = min(ans, G[k][i] + dis[i][j] + G[j][k]);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (i != j)
					dis[j][i] = dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	}
	if (ans <= n)
		printf("%d", ans);
	else printf("-1");
	return 0;
}