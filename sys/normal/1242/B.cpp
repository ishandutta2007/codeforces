#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, m, cnt;
set <int> Se[Maxn], Left;
void dfs(int u)
{
	Left.erase(u);
	int now = 0;
	while (now != -1)
	{
		if (Left.upper_bound(now) == Left.end())
			now = -1;
		else
		{
			now = *Left.upper_bound(now);
			if (Se[u].find(now) != Se[u].end()) continue;
			dfs(now);
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		Se[x].insert(y);
		Se[y].insert(x);
	}
	for (int i = 1; i <= n; i++)
		Left.insert(i);
	for (int i = 1; i <= n; i++)
		if (Left.find(i) != Left.end()) cnt++, dfs(i);
	printf("%d", cnt - 1);
	return 0;
}