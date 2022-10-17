/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 305
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m, edge[maxn][maxn], col[maxn], u[maxn], v[maxn];
int a[5005][maxn], cnt, mul[3][3];
void write()
{
	printf("\n");
	for (int i = 1; i <= cnt; i++)
	{
		for (int j = 1; j <= m + 1; j++) printf("%d ", a[i][j]);
		printf("\n");
	}
	printf("\n");
}
void gauss()
{
	for (int i = 1; i <= m; i++)
	{
		int pos = 0;
		for (int j = 1; j < i; j++) if(!a[j][j] && a[j][i]) pos = j;
		for (int j = i; j <= cnt; j++) if(a[j][i]) {pos = j; break;}
		if(!pos) continue;
		swap(a[i], a[pos]);
		for (int j = 1; j <= cnt; j++)
		{
			if(i == j) continue;
			int tmp = mul[a[j][i]][a[i][i]];
			for (int k = i; k <= m + 1; k++)
			{
				a[j][k] += 3 - mul[a[i][k]][tmp];
				if(a[j][k] >= 3) a[j][k] -= 3;
			}
		}
//		write();
	}
}
void solve()
{
	n = read(), m = read(), cnt = 0;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) edge[i][j] = 0;
	for (int i = 0; i < 1000; i++) for (int j = 0; j < maxn; j++) a[i][j] = 0;
	for (int i = 1; i <= m; i++)
	{
		u[i] = read(), v[i] = read(), col[i] = read();
		if(col[i] != -1) col[i]--, cnt++, a[cnt][i] = 1, a[cnt][m + 1] = col[i];
		edge[v[i]][u[i]] = edge[u[i]][v[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			for (int k = j + 1; k <= n; k++)
			{
				if(edge[i][j] && edge[j][k] && edge[i][k])
				{
					cnt++;
					a[cnt][edge[i][j]] = a[cnt][edge[j][k]] = a[cnt][edge[i][k]] = 1;
				}
			}
		}
	}
	cnt = max(cnt, m);
	gauss();
//	write();
	for (int i = 1; i <= m; i++)
	{
		if(!a[i][i] && a[i][m + 1])
		{
			printf("-1\n");
			return;
		}
	}
	for (int i = m + 1; i <= cnt; i++)
	{
		if(a[i][m + 1])
		{
			printf("-1\n");
			return;
		}
	}
//	printf("YES\n");
	for (int i = 1; i <= m; i++)
	{
		if(a[i][i]) col[i] = mul[a[i][m + 1]][a[i][i]];
		else col[i] = 0;
	}
	for (int i = 1; i <= m; i++) printf("%d ", col[i] + 1);
	printf("\n");
}
int main()
{
//	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout); 
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) mul[i][j] = i * j % 3;
	int T = read();
	while(T--) solve(); 
	return 0;
}