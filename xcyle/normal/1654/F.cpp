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
#define maxn (1 << 18)
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, tot, dep;
char s[maxn];
vector<int> buc[30];
int pos[20][maxn], rk[20][maxn];
inline int find(int x)
{
	return rk[dep - 1][x ^ (1 << (dep - 1))];
}
inline bool cmp(int x, int y)
{
	return find(x) < find(y);
}
void work(int l, int r)
{
	sort(pos[dep] + l, pos[dep] + r + 1, cmp);
	int las = l; rk[dep][pos[dep][l]] = l;
	for (int i = l + 1; i <= r; i++)
	{
		if(find(pos[dep][i - 1]) < find(pos[dep][i])) las = i;
		rk[dep][pos[dep][i]] = las;
	}
}
int main()
{
	scanf("%d%s", &n, s);
	for (int i = 0; i < (1 << n); i++) buc[s[i] - 'a'].push_back(i);
	for (int i = 0; i < 30; i++)
	{
		int las = tot;
		for (auto V: buc[i]) pos[0][tot++] = V, rk[0][V] = las;
	}
	for (dep = 1; dep <= n; dep++)
	{
		int las = 0;
		for (int j = 0; j < (1 << n); j++)
		{
			pos[dep][j] = pos[dep - 1][j];
			if(j && rk[dep - 1][pos[dep - 1][j - 1]] != rk[dep - 1][pos[dep - 1][j]]) work(las, j - 1), las = j;
		}
		work(las, (1 << n) - 1);
	}
	for (int i = 0; i < (1 << n); i++) printf("%c", s[i ^ pos[n][0]]);
	return 0;
}