#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int T, n, a[Maxn], sum1[Maxn], sum2[Maxn], val[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		int p = -1;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++)
		{
			if (!a[i]) val[i] = 1;
			if (a[i] && p == -1) p = i;
			else if (a[i])
			{
				if (a[p] == a[i]) val[i] = -1, val[p] = 1;
				else val[i] = val[p] = 1;
				p = -1;
			}
		}
		if (p != -1) puts("-1");
		else
		{
			vector <pair <int, int> > ans;
			int s = 1;
			for (int i = 1; i <= n; i++)
				if (val[i] == 1 && val[i - 1] == 1)
				{
					if (s <= i - 1) ans.push_back(make_pair(s, i - 1));
					s = i;
				}
			ans.push_back(make_pair(s, n));
			printf("%d\n", (int) ans.size());
			for (auto u : ans)
				printf("%d %d\n", u.first, u.second);
		}
	}
	return 0;
}