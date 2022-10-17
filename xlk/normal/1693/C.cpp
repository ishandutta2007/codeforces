#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int out[200020];
vector<int> a[200020];
map<int, int> g[200020];
int d[200020];
vector<int> f[200020];
set<pair<int, int> > s;
void update(int x, int y, int e)
{
	f[x].push_back(e);
	if (int(e + out[x] - f[x].size()) < d[x])
	{
		s.erase(make_pair(d[x], x));
		d[x] = int(e + out[x] - f[x].size());
		s.insert(make_pair(d[x], x));
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		g[x][y]++;
		out[x]++;
		a[y].push_back(x);
	}
	memset(d, 0x3f, sizeof d);
	d[n] = 0;
	s.insert(make_pair(d[n], n));
	while (s.size())
	{
		auto u = *s.begin();
		s.erase(s.begin());
		for (int i : a[u.second])
		{
			update(i, u.second, d[u.second] + 1);
		}
	}
	// for (int i = 1; i <= n; i++)
	// {
	// 	printf("%d %d\n", i, d[i]);
	// }
	printf("%d\n", d[1]);
	return 0;
}