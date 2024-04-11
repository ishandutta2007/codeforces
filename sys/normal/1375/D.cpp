#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
int T, n, done, ans_ct, pos[Maxn], ans[2 * Maxn], a[Maxn];
bool vis[Maxn];
int mex(void)
{
	memset(vis, 0, sizeof(bool[n + 1]));
	for (int i = 1; i <= n; i++)
		vis[a[i]] = true;
	for (int i = 0; i <= n; i++)
		if (!vis[i]) return i;
}
bool sorted(void)
{
	for (int i = 1; i < n; i++)
		if (a[i] > a[i + 1]) return false;
	return true;
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		done = ans_ct = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		while (!sorted())
		{
			int now = mex();
			if (now == n)
			{
				for (int i = 1; i <= n; i++)
					pos[a[i]] = i;
				for (int i = n - 1; i >= 0; i--)
					if (pos[i] != i + 1)
					{
						ans[++ans_ct] = pos[i];
						a[pos[i]] = now;
						goto END;
					}
			}
			else
			{
				ans[++ans_ct] = now + 1;
				a[now + 1] = now;
			}
			END:;
		}
		printf("%d\n", ans_ct);
		for (int i = 1; i <= ans_ct; i++)
			printf("%d ", ans[i]);
		puts("");
	}
	return 0;
}