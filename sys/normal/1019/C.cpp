#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;
int n, m, ct;
bool vis[Maxn], used[Maxn];
vector <int> Ve[Maxn];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		vis[i] = true;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y), Ve[x].push_back(y);
	}
	for (int u = 1; u <= n; u++)
	{
		if (vis[u])
		{
			used[u] = true;
			for (vector <int> :: iterator it = Ve[u].begin(); it != Ve[u].end(); it++)
				vis[*it] = false;
		}
	}
	for (int u = n; u >= 1; u--)
		if (used[u])
		{
			for (vector <int> :: iterator it = Ve[u].begin(); it != Ve[u].end(); it++)
				used[*it] = false;
		}
	for (int i = 1; i <= n; i++)
		if (used[i]) ct++;
	printf("%d\n", ct);
	for (int i = 1; i <= n; i++)
		if (used[i]) printf("%d ", i);
	return 0;
}