#include <bits/stdc++.h>
using namespace std;
int t, n, k, x, y;
vector<int> a[400020];
int d[400020];
int v[400020];
int f[400020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
		{
			a[i].clear();
			v[i] = 0;
			d[i] = 0;
			f[i] = 0;
		}
		for (int i = 1; i < n; i++)
		{
			scanf("%d%d", &x, &y);
			a[x].push_back(y);
			a[y].push_back(x);
			d[x]++;
			d[y]++;
		}
		queue<int> q;
		for (int i = 1; i <= n; i++)
		{
			if (d[i] <= 1)
			{
				v[i] = 1;
				q.push(i);
			}
		}
		while (q.size())
		{
			int u = q.front();
			q.pop();
			for (int i : a[u])
			{
				d[i]--;
				if (d[i] <= 1 && !v[i])
				{
					v[i] = 1;
					f[i] = f[u] + 1;
					q.push(i);
				}
			}
		}
		int z = 0;
		for (int i = 1; i <= n; i++)
		{
			if (f[i] >= k)
			{
				z++;
			}
		}
		printf("%d\n", z);
	}
	return 0;
}