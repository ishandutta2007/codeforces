#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define ll long long
#define maxn 2005
using namespace std;
const int mo = 1e9 + 7;
int t, n, m, res, cnt, vis[maxn][maxn], i, j;
char s[maxn][maxn];
int TY;
struct node
{
	int x, y;
};
queue<node> q;
void dfs(int x, int y)
{
	q.push((node){x, y});
	while(!q.empty())
	{
		int x = q.front().x, y = q.front().y;
		q.pop();
		if(vis[x][y]) continue;
		if(x < 1 || x > n || y < 1 || y > m) continue;
		if(s[x][y] == '0') 
		{
			TY = 1;
			continue;
		}
		vis[x][y] = 1;
		cnt = cnt * 2 % mo;
		q.push((node){x - 1, y});
		q.push((node){x + 1, y});
		q.push((node){x, y - 1});
		q.push((node){x, y + 1});
	}
	return;
}
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &n, &m);
		for (i = 1; i <= n; i++)
		{
			scanf("%s", s[i] + 1);
		}
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++) vis[i][j] = 0;
		}
		int res = 1;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				if(s[i][j] == '#' && !vis[i][j])
				{
					cnt = 1;
					TY = 0;
					dfs(i, j);
					if(TY) res = (ll)res * cnt % mo;
					else res = (ll)res * (cnt - 1 + mo) % mo;
//					printf("%d %d\n", F, T);
				}
			}
		}
		printf("%d\n", res);
	}
	return 0;
}