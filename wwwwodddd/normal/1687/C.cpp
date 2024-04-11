#include <bits/stdc++.h>
using namespace std;
int t, n, m;
long long a[200020];
long long b[200020];
int f[200020];
int l[200020];
int r[200020];
int c[200020];
vector<int> p[200020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i <= n + 1; i++)
		{
			f[i] = i;
			p[i].clear();
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &a[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &b[i]);
			a[i] -= b[i];
			a[i] += a[i - 1];
		}
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &l[i], &r[i]);
			l[i]--;
			c[i] = 0;
			p[l[i]].push_back(i);
			p[r[i]].push_back(i);
		}
		if (a[n] != 0)
		{
			puts("NO");
			continue;
		}
		queue<int> q;
		for (int i = 0; i <= n; i++)
		{
			if (a[i] == 0)
			{
				f[i] = i + 1;
				for (int j : p[i])
				{
					if (++c[j] == 2)
					{
						q.push(j);
					}
				}
			}
		}
		while (q.size())
		{
			int u = q.front();
			q.pop();
			for (int i = F(l[u]); i < r[u]; i = F(i))
			{
				assert(a[i] != 0);
				a[i] = 0;
				f[i] = i + 1;
				for (int j : p[i])
				{
					if (++c[j] == 2)
					{
						q.push(j);
					}
				}
			}
		}
		int z = 0;
		for (int i = 0; i <= n; i++)
		{
			if (a[i])
			{
				z++;
			}
		}
		puts(z ? "NO" : "YES");
	}
	return 0;
}