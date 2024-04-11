#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
int T, n, a[Maxn], las[Maxn], maxi[Maxn], ans[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		memset(ans, 0x3f, sizeof(int[n + 1]));
		memset(maxi, 0, sizeof(int[n + 1]));
		memset(las, 0, sizeof(int[n + 1]));
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			maxi[a[i]] = max(maxi[a[i]], i - las[a[i]]);
			las[a[i]] = i;
		}
		for (int i = 1; i <= n; i++)
			if (las[i]) maxi[i] = max(maxi[i], n + 1 - las[i]);
		for (int i = 1; i <= n; i++)
			if (las[i]) ans[maxi[i]] = min(ans[maxi[i]], i);
		for (int i = 1; i <= n; i++)
			ans[i] = min(ans[i], ans[i - 1]), printf("%d ", ans[i] == 0x3f3f3f3f ? -1 : ans[i]);
		puts("");
	}
	return 0;
}