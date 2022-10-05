#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;
int T, e, n, cnt, a[Maxn], prim[Maxn], len1[Maxn], len2[Maxn];
bool vis[Maxn];
void init(void)
{
	vis[1] = true;
	for (int i = 2; i <= 1000000; i++)
	{
		if (!vis[i]) prim[++cnt] = i;
		for (int j = 1; j <= cnt && i * prim[j] <= 1000000; j++)
		{
			vis[i * prim[j]] = true;
			if (i % prim[j] == 0) break;
		}
	}
}
int main()
{
	init();
	scanf("%d", &T);
	while (T--)
	{
		long long ans = 0;
		scanf("%d%d", &n, &e);
		memset(len1, 0, sizeof(int[n + e + 1]));
		memset(len2, 0, sizeof(int[n + e + 1]));
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int i = n; i >= 1; i--)
			if (a[i] == 1) len1[i] = len1[i + e] + 1;
			else len1[i] = 0;
		for (int i = 1; i <= n; i++)
			if (a[i] == 1) len2[i] = (i <= e ? 0 : len2[i - e]) + 1;
			else len2[i] = 0;
		for (int i = 1; i <= n; i++)
			if (!vis[a[i]]) ans += ((i <= e ? 0 : len2[i - e]) + 1) * (len1[i + e] + 1LL) - 1;
		printf("%lld\n", ans);
	}
	return 0;
}