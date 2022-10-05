#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
int n, m, cnt;
string str[Maxn];
bool flag1, flag2, vis[Maxn][Maxn];
void dfs(int x, int y)
{
	vis[x][y] = true;
	if (x - 1 >= 1 && str[x - 1][y] == '#' && !vis[x - 1][y]) dfs(x - 1, y);
	if (y - 1 >= 0 && str[x][y - 1] == '#' && !vis[x][y - 1]) dfs(x, y - 1);
	if (x + 1 <= n && str[x + 1][y] == '#' && !vis[x + 1][y]) dfs(x + 1, y);
	if (y + 1 < m && str[x][y + 1] == '#' && !vis[x][y + 1]) dfs(x, y + 1);
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		cin >> str[i];
	bool flag = false;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < m; j++)
			if (str[i][j] == '#') flag = true;
	if (!flag)
	{
		puts("0");
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		int tag = 0;
		for (int j = 0; j < m; j++)
		{
			if (str[i][j] == '#' && !tag) tag = 1;
			else if (str[i][j] == '.' && tag == 1) tag = 2;
			else if (str[i][j] == '#' && tag == 2)
			{
				puts("-1");
				return 0;
			}
		}
		if (!tag) flag1 = true;
	}
	for (int j = 0; j < m; j++)
	{
		int tag = 0;
		for (int i = 1; i <= n; i++)
		{
			if (str[i][j] == '#' && !tag) tag = 1;
			else if (str[i][j] == '.' && tag == 1) tag = 2;
			else if (str[i][j] == '#' && tag == 2)
			{
				puts("-1");
				return 0;
			}
		}
		if (!tag) flag2 = true;
	}
	if (flag1 + flag2 == 1)
	{
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < m; j++)
			if (!vis[i][j] && str[i][j] == '#') dfs(i, j), cnt++;
	printf("%d", cnt);
	return 0;
}