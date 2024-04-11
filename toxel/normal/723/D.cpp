#include<bits/stdc++.h>
using namespace std;
typedef struct point
{
	bool water, visited;
	int type;
};
typedef struct answer
{
	int type, x, y, count;
};
point poi[60][60];
answer ans[3000];
int n, m, k, ans2 = 0;
bool compare (answer a, answer b)
{
	return a.count < b.count;
}
void dfs(int x, int y, int type)
{
	if (x < 0 || y < 0 || x >= n || y >= m || !poi[x][y].water || poi[x][y].visited)
		return;
	poi[x][y].type = type;
	poi[x][y].visited = true;
	dfs(x - 1, y, type);
	dfs(x + 1, y, type);
	dfs(x, y - 1, type);
	dfs(x, y + 1, type);
}
void dfs2(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= m || !poi[x][y].water || poi[x][y].visited)
		return;
	poi[x][y].visited = true;
	dfs2(x - 1, y);
	dfs2(x + 1, y);
	dfs2(x, y - 1);
	dfs2(x, y + 1);
	poi[x][y].water = false;
	ans2++;
}
int main()
{
	memset(poi, 0, sizeof(poi));
	memset(ans, 0, sizeof(ans));
	scanf("%d%d%d",&n, &m, &k);
	getchar();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(getchar() == '.')
				poi[i][j].water = true;
			poi[i][j].type = -1;
		}
		getchar();
	}
	for (int i = 0; i < n; i++)
	{
		dfs(i, 0, 0);
		dfs(i, m - 1, 0);
	}
	for (int i = 0; i < m; i++)
	{
		dfs(0, i, 0);
		dfs(n - 1, i, 0);
	}
	int count = 0;
	for (int i = 1; i < n - 1; i++)
		for (int j = 1; j < m - 1; j++)
			if (poi[i][j].water && !poi[i][j].visited)
			{
				count++;
				ans[count].type = count;
				ans[count].x = i;
				ans[count].y = j;	
				dfs(i, j, count);
			}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (poi[i][j].type > 0)
				ans[poi[i][j].type].count++;
	sort(ans + 1, ans + count + 1, compare);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			poi[i][j].visited = false;
	for (int i = k; i < count; i++)
	{
		dfs2(ans[i - k + 1].x, ans[i - k + 1].y);
	}
	printf("%d\n",ans2);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			if (poi[i][j].water)
				putchar('.');
			else
				putchar('*');
		putchar('\n');
	}
	return 0;
}