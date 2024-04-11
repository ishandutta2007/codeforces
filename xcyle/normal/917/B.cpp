#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 105
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
inline ll readll()
{
	ll x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m, u, v;
char s[10];
vector<int> G[maxn];
vector<int> val[maxn];
int f[maxn][maxn][30];
int dfs(int x, int y, int lev)
{
	if(f[x][y][lev] != -1) return f[x][y][lev];
	f[x][y][lev] = 0;
	for (int i = 0; i < G[x].size(); i++)
	{
		if(val[x][i] < lev) continue;
		f[x][y][lev] |= (1 ^ dfs(y, G[x][i], val[x][i]));
	} 
	return f[x][y][lev];
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		 for  (int j = 1; j <= n; j++)
		 {
		 	for (int k = 0; k <= 26; k++)
		 	{
		 		f[i][j][k] = -1;
			 }
		 }
	} 
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%s", &u, &v, s + 1);
		G[u].push_back(v);
		val[u].push_back(s[1] - 'a');
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(dfs(i, j, 0)) printf("A");
			else printf("B"); 
		} 
		printf("\n");
	}
	return 0;
}