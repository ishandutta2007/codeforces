/*

_/      _/      _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/     _/      _/     _/    _/     _/           _/
  _/  _/      _/              _/  _/      _/           _/
   _/_/       _/                _/        _/           _/_/_/_/
  _/  _/      _/                _/        _/           _/
 _/    _/     _/      _/        _/        _/           _/
_/      _/      _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <ctime>
#include <cstdlib>
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 50005
using namespace std;
const int mo = 31607;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int s[4][25];
int n, a[25][25];
int fac[maxn], ifac[maxn], inv[maxn];
int ans = 0;
int val[4] = {1, mo - 1, mo - 1, 1}; 
void dfs(int step)
{
//	printf("%d %d %d\n", step, tp * 128 % mo, (mo - tp) * 16 % mo);
//	for (int i = 0; i < 4; i++) for (int j = 1; j <= n; j++) printf("%d ", s[i][j] * 16 % mo);
//	printf("\n");
	if(step > n)
	{
		for (int i = 0; i < 4; i++)
		{
			int tmp = val[i];
			for (int j = 1; j <= n; j++) tmp = tmp * (1 + mo - s[i][j]) % mo;
			ans = (ans + tmp) % mo;
		}
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if((i == step && (j & 1)) || (i + step == n + 1 && (j & 2))) val[j] = val[j] * a[step][i] % mo;
			else s[j][i] = s[j][i] * a[step][i] % mo;
		}
	}
	dfs(step + 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if((i == step && (j & 1)) || (i + step == n + 1 && (j & 2))) val[j] = val[j] * inv[a[step][i]] % mo;
			else s[j][i] = s[j][i] * inv[a[step][i]] % mo;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			val[j] = val[j] * a[step][i] % mo;
		}
	}
	for (int j = 0; j < 4; j++) val[j] = val[j] * (mo - 1) % mo;
	dfs(step + 1);
	for (int j = 0; j < 4; j++) val[j] = val[j] * (mo - 1) % mo;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			val[j] = val[j] * inv[a[step][i]] % mo;
		}
	}
}
int main()
{
	scanf("%d", &n);
	inv[1] = 1;
	for (int i = 2; i < mo; i++) inv[i] = (mo - mo / i) * inv[mo % i] % mo;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &a[i][j]);
			a[i][j] = a[i][j] * inv[10000] % mo;
		}
	}
	for (int i = 0; i < 4; i++) for (int j = 1; j <= n; j++) s[i][j] = 1;
	dfs(1);
	printf("%d", (1 - ans + mo) % mo);
	return 0;
}