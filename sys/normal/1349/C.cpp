#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
int n, m, t, dis[Maxn][Maxn];
bool val[Maxn][Maxn], vis[Maxn][Maxn];
queue <pair <int, int> > Qu;
void bfs(void)
{
	while (!Qu.empty())
	{
		pair <int, int> u = Qu.front();
		Qu.pop();
		if (u.first != 1 && !vis[u.first - 1][u.second] && val[u.first - 1][u.second] != val[u.first][u.second])
			dis[u.first - 1][u.second] = dis[u.first][u.second] + 1, Qu.push(make_pair(u.first - 1, u.second)), vis[u.first - 1][u.second] = true;
		if (u.first != n && !vis[u.first + 1][u.second] && val[u.first + 1][u.second] != val[u.first][u.second])
			dis[u.first + 1][u.second] = dis[u.first][u.second] + 1, Qu.push(make_pair(u.first + 1, u.second)), vis[u.first + 1][u.second] = true;
		if (u.second != 1 && !vis[u.first][u.second - 1] && val[u.first][u.second - 1] != val[u.first][u.second])
			dis[u.first][u.second - 1] = dis[u.first][u.second] + 1, Qu.push(make_pair(u.first, u.second - 1)), vis[u.first][u.second - 1] = true;
		if (u.second != m && !vis[u.first][u.second + 1] && val[u.first][u.second + 1] != val[u.first][u.second])
			dis[u.first][u.second + 1] = dis[u.first][u.second] + 1, Qu.push(make_pair(u.first, u.second + 1)), vis[u.first][u.second + 1] = true;
	}
}
int main()
{
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			int x;
			scanf("%1d", &x), val[i][j] = x;
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if ((i != 1 && val[i - 1][j] == val[i][j]) || (i != n && val[i + 1][j] == val[i][j]) || (j != 1 && val[i][j - 1] == val[i][j]) || (j != m && val[i][j + 1] == val[i][j])) vis[i][j] = true, Qu.push(make_pair(i, j));
	bfs();
	for (int i = 1; i <= t; i++)
	{
		int x, y;
		long long p;
		scanf("%d%d%lld", &x, &y, &p);
		if (!vis[x][y]) putchar('0' + val[x][y]);
		else if (p < dis[x][y]) putchar('0' + val[x][y]);
		else putchar('0' + (val[x][y] ^ ((p - dis[x][y]) & 1)));
		puts("");
	}
	return 0;
}