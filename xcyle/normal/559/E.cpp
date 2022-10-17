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
#define maxn 105
using namespace std;
const int INF = 0x3f3f3f3f;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n;
struct node
{
	int l, pos;
	inline bool friend operator < (node aa, node bb)
	{
		return aa.pos < bb.pos;
	}
}p[maxn];
int f[maxn][maxn][maxn];
inline int calc(int a, int b, int c)
{
	int x = max(0, p[b].pos + p[b].l - p[a].pos), y = max(0, p[a + 1].pos - p[c].pos + p[c].l);
	return min(x + y, p[a + 1].pos - p[a].pos);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &p[i].pos, &p[i].l);
	}
	p[n + 1] = {0, INF};
	p[0] = {0, -INF};
	sort(p + 1, p + n + 1);
	int ans = 0;
	for (int i = 1; i <= n + 1; i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (int k = i; k <= n + 1; k++)
			{
				int val = calc(i - 1, j, k);
				if(i != k)
				{
					int nxtj = j;
					if(p[i].pos + p[i].l > p[j].pos + p[j].l) nxtj = i;
					f[i][nxtj][k] = max(f[i][nxtj][k], f[i - 1][j][k] + val);
				}
				else
				{
					if(i == n + 1) ans = max(ans, f[i - 1][j][k] + val);
					for (int nxtk = k + 1; nxtk <= n + 1; nxtk++)
					{
						f[i][j][nxtk] = max(f[i][j][nxtk], f[i - 1][j][k] + val);
					}
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}