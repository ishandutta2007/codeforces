#include <bits/stdc++.h>
using namespace std;
int t, n, m;
char s[60][60];
vector<pair<int, int> > p;
int dis(int a, int b)
{
	return (p[a].first - p[b].first) * (p[a].first - p[b].first) + (p[a].second - p[b].second) * (p[a].second - p[b].second);
}
void dfs(int x, int y)
{
	p.push_back(make_pair(x, y));
	s[x][y] = '.';
	for (int nx = max(x - 1, 0); nx <= min(x + 1, n - 1); nx++)
	{
		for (int ny = max(y - 1, 0); ny <= min(y + 1, m - 1); ny++)
		{
			if (s[nx][ny] == '*')
			{
				dfs(nx, ny);
			}
		}
	}
}
bool ok()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == '*')
			{
				p.clear();
				dfs(i, j);
				if (p.size() != 3)
				{
					return false;
				}
				int a[3] = {
					dis(0, 1),
					dis(0, 2),
					dis(1, 2),
				};
				sort(a, a + 3);
				if (a[0] != 1 || a[1] != 1 || a[2] != 2)
				{
					return false;
				}
			}
		}
	}
	return true;
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			scanf("%s", s[i]);
		}
		if (ok())
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}