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
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m;
vector<pair<int, int> > p;
int f[maxn][maxn];
int sum[maxn];
void calc(int l, int r)
{
	for (int i = l; i <= r; i++)
	{
		if(f[l][i - 1] == -1) calc(l, i - 1);
		if(f[i + 1][r] == -1) calc(i + 1, r);
	}
	for (int i = l - 1; i <= r + 1; i++) sum[i] = 0;
	for (int i = 0; i < p.size(); i++)
	{
		if(p[i].first < l || p[i].second > r) continue;
		sum[p[i].first]++, sum[p[i].second + 1]--;
	}
	for (int i = l; i <= r; i++)
	{
		sum[i] += sum[i - 1];
		f[l][r] = max(f[l][r], f[l][i - 1] + sum[i] * sum[i] + f[i + 1][r]);
	}
//	printf("%d %d %d\n", l, r, f[l][r]);
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		int k = read();
		for (int j = 1; j <= k; j++)
		{
			int l = read(), r = read();
			p.push_back(make_pair(l, r));
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = i; j <= m; j++) f[i][j] = -1;
	}
	calc(1, m);
	printf("%d\n", f[1][m]);
	return 0;
}