#include <bits/stdc++.h>
using namespace std;
int n, x, y, z;
long long ans;
vector<pair<int, int> > a[500020];
vector<int> b[500020];
int c[500020];
int w[500020];
int s[500020];
int dfs1(int x, int y)
{
	s[x] = 1;
	for (auto i : a[x])
	{
		if (i.first != y)
		{
			b[i.second].push_back(i.first);
			s[x] += dfs1(i.first, x);
			b[i.second].pop_back();
			if (b[i.second].size() > 0)
			{
				c[b[i.second].back()] -= s[i.first];
			}
			else
			{
				w[i.second] -= s[i.first];
			}
		}
	}
	c[x] += s[x];
	return s[x];
}
void dfs2(int x, int y)
{
	for (auto i : a[x])
	{
		if (i.first != y)
		{
			b[i.second].push_back(i.first);
			dfs2(i.first, x);
			b[i.second].pop_back();
			if (b[i.second].size() > 0)
			{
				ans += (long long)c[i.first] * c[b[i.second].back()];
			}
			else
			{
				ans += (long long)c[i.first] * w[i.second];
			}
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
		w[z] = n;
	}
	dfs1(1, 0);
	dfs2(1, 0);
	printf("%lld\n", ans);
	return 0;
}