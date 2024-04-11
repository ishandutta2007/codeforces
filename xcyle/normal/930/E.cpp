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
#define maxn 400005
using namespace std;
const int mo = 1e9 + 7;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
inline int ksm(int x, int step)
{
	int res = 1;
	for (; step; step >>= 1)
	{
		if(step & 1) res = (ll)res * x % mo;
		x = (ll)x * x % mo;
	}
	return res;
}
int k, n, m, tmp[maxn], f[3][maxn];
struct node
{
	int l, r, tp;
	inline bool friend operator < (node x, node y){return x.r < y.r;}
}p[maxn];
int main()
{
	k = read(), n = read(), m = read();
	for (int i = 1; i <= n + m; i++) p[i].l = read(), p[i].r = read(), p[i].tp = (i <= n);
	for (int i = 1; i <= n + m; i++) tmp[2 * i - 1] = p[i].l - 1, tmp[2 * i] = p[i].r;
	sort(p + 1, p + n + m + 1);
	tmp[2 * (n + m) + 1] = 0;
	sort(tmp + 1, tmp + 2 * (n + m) + 2);
	int len = unique(tmp + 1, tmp + 2 * (n + m) + 2) - tmp - 1;
	f[0][1] = f[1][1] = f[2][1] = 1;
	int mx[2] = {0, 0}, pos[2] = {1, 1}, sum[2] = {1, 1};
	for (int i = 2, j = 1, k = 1; i <= len; i++)
	{
		while(j <= n + m && p[j].r <= tmp[i]) mx[p[j].tp] = max(mx[p[j].tp], p[j].l), j++;
		while(pos[0] <= len && tmp[pos[0]] < mx[0]) sum[0] = (sum[0] + mo - f[1][pos[0]++]) % mo;
		while(pos[1] <= len && tmp[pos[1]] < mx[1]) sum[1] = (sum[1] + mo - f[0][pos[1]++]) % mo;
		f[2][i] = (ll)f[2][i - 1] * (ksm(2, tmp[i] - tmp[i - 1]) + mo - 2) % mo;
		f[0][i] = (sum[0] + f[2][i]) % mo, f[1][i] = (sum[1] + f[2][i]) % mo;
		f[2][i] = (f[2][i] + (sum[0] + sum[1]) % mo) % mo;
		sum[0] = (sum[0] + f[1][i]) % mo;
		sum[1] = (sum[1] + f[0][i]) % mo;
	}
	printf("%d\n", (ll)ksm(2, k - tmp[len]) * f[2][len] % mo);
	return 0;
}