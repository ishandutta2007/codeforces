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
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n;
int cnt[maxn][maxn], need[maxn][maxn], tmp[maxn][maxn];
int opt[maxn * maxn][maxn], tot;
int main()
{
	n = read();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) cnt[i][read() - 1]++;
		for (int j = 0; j < n; j++) tmp[i][j] = cnt[i][j];
	}
	int all = 0;
	for (int i = 0; i < n; i++)
	{
		int las = 0, mn = 0;
		for (int j = 0; j < n; j++)
		{
			las += cnt[j][i] - 1;
			need[j][i] = las;
			mn = min(mn, need[j][i]);
		}
		for (int j = 0; j < n; j++) need[j][i] -= mn, all += need[j][i];
	}
	for (tot = 1; tot <= all / n; tot++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if(cnt[i][j] && need[i][j])
				{
					cnt[i][j]--, need[i][j]--;
					opt[tot][i] = j;
					break;
				}
			}
		}
		for (int i = 0; i < n; i++) cnt[i][opt[tot][(i - 1 + n) % n]]++;
	}
	tot--; 
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j > 0; j--)
		{
			tot++;
			for (int k = 0; k < n; k++) opt[tot][k] = (j + k) % n;
		}
	}
	printf("%d\n", tot);
	for (int i = 1; i <= tot; i++)
	{
		for (int j = 0; j < n; j++) printf("%d ", opt[i][j] + 1);
		printf("\n");
	}
	/*
	for (int i = 1; i <= tot; i++)
	{
		printf("process %d :\n", i);
		for (int j = 0; j < n; j++)
		{
			tmp[j][opt[i][j]]--;
			if(tmp[j][opt[i][j]] < 0) printf("!!!!!");
			tmp[j][opt[i][(j + n - 1) % n]]++;
			for (int k = 0; k < n; k++)
			{
				for (int l = 1; l <= tmp[j][k]; l++) printf("%d ", k + 1);
			}
			printf("\n");
		}
	}
	*/
	return 0;
}