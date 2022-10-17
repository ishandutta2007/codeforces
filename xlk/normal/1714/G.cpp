#include <bits/stdc++.h>
using namespace std;
int t, n;
vector<array<int, 3> > a[200020];
long long r[200020];
vector<long long> s;
void dfs(int x, long long u, long long v, int d)
{
	s.push_back(v);
	r[x] = upper_bound(s.begin(), s.end(), u) - s.begin() - 1;
	for (auto b : a[x])
	{
		dfs(b[0], u + b[1], v + b[2], d + 1);
	}
	s.pop_back();
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			a[i].clear();
		}
		for (int i = 2; i <= n; i++)
		{
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			a[x].push_back({i, y, z});
		}
		dfs(1, 0, 0, 0);
		for (int i = 2; i <= n; i++)
		{
			printf("%lld%c", r[i], i < n ? ' ' : '\n');
		}
	}
	return 0;
}