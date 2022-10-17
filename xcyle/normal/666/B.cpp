/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <bits/stdc++.h>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define ru(i, l, r) for (int i = (l); i <= (r); i++)
#define rd(i, r, l) for (int i = (r); i >= (l); i--)
#define mid ((l + r) >> 1)
#define maxn 3005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, dis[maxn][maxn];
int id1[maxn][maxn], id2[maxn][maxn];
vector<int> G[maxn];
queue<int> q;
void dijk(int s)
{
	q.push(s); dis[s][s] = 0;
	while(!q.empty())	
	{
		int x = q.front(); q.pop();
		for (auto V: G[x]) if(!dis[s][V] && s != V)
		{
			dis[s][V] = dis[s][x] + 1;
			q.push(V);
		}
	}
}
int now;
inline bool cmp1(int x, int y)
{
	return dis[now][x] > dis[now][y];
}
inline bool cmp2(int x, int y)
{
	return dis[x][now] > dis[y][now];
}
int main()
{
	n = read(), m = read();
	ru(i, 1, m)
	{
		int x = read(), y = read();
		G[x].push_back(y);
	}
	ru(i, 1, n) ru(j, 1, n) id1[i][j] = id2[i][j] = j;
	ru(i, 1, n) dijk(i);
//	ru(i, 1, n) ru(j, 1, n) printf("%d %d %d\n", i, j, dis[i][j]);
	for (now = 1; now <= n; now++) sort(id1[now] + 1, id1[now] + n + 1, cmp1), sort(id2[now] + 1, id2[now] + n + 1, cmp2);
	int ans = 0, a, b, c, d;
	ru(i, 1, n)
	{
		ru(j, 1, n) if(dis[j][i])
		{
			ru(k, 1, 3) if(id1[i][k] != j)
			{
				ru(l, 1, 3) if(id2[j][l] != i && id2[j][l] != id1[i][k])
				{
					if(!dis[i][id1[i][k]] || !dis[id2[j][l]][j]) continue;
					int tmp = dis[j][i] + dis[i][id1[i][k]] + dis[id2[j][l]][j];
					if(tmp > ans)
					{
						ans = tmp;
						a = id1[i][k], b = i, c = j, d = id2[j][l];
					}
				}
			}
		}
	}
	printf("%d %d %d %d\n", d, c, b, a);
	return 0;
}