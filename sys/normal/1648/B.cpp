#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2000005;
int T, n, c, C, a[Maxn], vis[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		C = 0;
		scanf("%d%d", &n, &c);
		memset(vis, 0, sizeof(int[c + 1]));
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		n = unique(a + 1, a + 1 + n) - a - 1;
		for (int i = 1; i <= n; i++)
		{
			if (c / a[i] < a[i]) break;
			C++;
			for (int j = i; j <= n; j++)
				if (a[i] * a[j] <= c)
				{
					if (a[i] == a[j]) vis[a[i] * a[j]]++, vis[(a[i] + 1) * a[j]]--;
					else vis[a[i] * a[j]] += 2, vis[(a[i] + 1) * a[j]]--, vis[a[i] * (a[j] + 1)]--;
				}
				else break;
		}
		for (int i = 1; i <= c; i++) vis[i] += vis[i - 1];
		for (int i = 1; i <= n; i++)
			if (vis[a[i]] != i)
			{
				puts("NO");
				goto END;
			}
		puts("YES");
		END:;
	}
	return 0;
}