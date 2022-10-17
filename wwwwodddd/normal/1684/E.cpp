#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int a[100020];
vector<pair<int, int> > b;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		map<int, int> c, g;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			c[a[i]]++;
		}
		sort(a, a + n);
		int l = m, d = n;
		for (int i = 0; i <= n; i++)
		{
			if (c.find(i) == c.end())
			{
				if (l == 0)
				{
					d = i;
					break;
				}
				l--;
			}
		}
		int z = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] >= d)
			{
				g[a[i]]++;
			}
		}
		b.clear();
		for (auto i: g)
		{
			z++;
			b.push_back(make_pair(i.second, i.first));
		}
		sort(b.begin(), b.end());
		for (int i = 0; i < b.size(); i++)
		{
			if (b[i].first <= m)
			{
				m -= b[i].first;
				z--;
			}
		}
		printf("%d\n", z);
	}
	return 0;
}