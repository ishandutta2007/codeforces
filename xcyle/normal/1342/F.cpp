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
#define maxn 20
#define maxs (1 << 15)
using namespace std;
const int INF = 0x3f3f3f3f;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn], f[maxn][maxs][maxn], las[maxn][maxs][maxn], sum[maxs], id[maxn];
void work(int lev, int s, int pos)
{
	if(lev == 0) return;
	for (int i = pos - 1; i >= 0; i--) if(f[lev][s][i] == f[lev][s][pos]) pos = i;
//	printf("%d %d %d %d\n", lev, s, pos, las[lev][s][pos]);
//	for (int i = 0; i < n; i++) printf("%d", ((s >> i) & 1));
//	printf(" ");
//	for (int i = 0; i < n; i++) printf("%d", ((las[lev][s][pos] >> i) & 1));
//	printf("\n");
	work(lev - 1, las[lev][s][pos], pos - 1);
	for (int i = 0; i < n; i++)
	{
		if(i == pos) continue;
		if(((s - las[lev][s][pos]) >> i) & 1)
		{
			printf("%d %d\n", id[i], id[pos]);
			for (int j = i; j < n; j++) id[j]--;
		}
	}
}
inline void check()
{
	printf("!\n"); fflush(stdout);
}
void solve()
{
	n = read(); for (int i = 0; i < n; i++) a[i] = read();
	for (int i = 0; i < (1 << n); i++) sum[i] = 0;
	for (int i = 0; i < (1 << n); i++) for (int j = 0; j < n; j++) if((i >> j) & 1) sum[i] += a[j];
	for (int i = 0; i <= n; i++) for (int j = 0; j < (1 << n); j++) for (int k = 0; k < n; k++) f[i][j][k] = INF;
	for (int i = 0; i < n; i++) f[0][0][i] = 0;
	for (int lev = 1; lev <= n; lev++)
	{
		for (int s = 0; s < (1 << n); s++)
		{
			int cnt = 0; for (int i = 0; i < n; i++) cnt += ((s >> i) & 1);
			if(cnt < lev) continue;
			for (int pos = lev - 1; pos < n; pos++)
			{
				if(pos) f[lev][s][pos] = f[lev][s][pos - 1];
				if((s >> pos) & 1)
				{
					for (int ls = s & (s - 1); ; ls = s & (ls - 1))
					{
						int fl = 1;
						if(pos == 0)
						{
							if(lev == 1 && ls == 0) fl = 1;
							else fl = 0;
						}
						else fl = f[lev - 1][ls][pos - 1] < sum[s - ls];
						if((((s - ls) >> pos) & 1) && fl && sum[s - ls] < f[lev][s][pos])
						{
//							printf("!%d\n", f[0][2][]);
							f[lev][s][pos] = sum[s - ls], las[lev][s][pos] = ls;
//							printf("%d %d %d %d %d %d\n", lev, s, pos, ls, f[lev - 1][ls][pos - 1], sum[s - ls]);
						}
						if(!ls) break;
					}
				}
//				if(f[lev][s][pos] != INF) printf("%d %d %d %d\n", lev, s, pos, f[lev][s][pos]);
			}
		}
		if(f[lev][(1 << n) - 1][n - 1] == INF)
		{
			for (int i = 0; i < n; i++) id[i] = i + 1;
			printf("%d\n", n - lev + 1);
			work(lev - 1, (1 << n) - 1, n - 1);
			return;
		}
	}
	printf("0\n");
	return;
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}