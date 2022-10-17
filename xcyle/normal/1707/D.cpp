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
#define maxn 2005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, mo, f[maxn][maxn], g[maxn], c[maxn][maxn];
int pre[maxn][maxn], suf[maxn], ans[maxn];
vector<int> G[maxn];
void dfs(int x, int fa)
{
	for (auto &V: G[x]) if(V == fa) {swap(V, G[x].back()); break;} G[x].pop_back();
	for (auto V: G[x]) if(V ^ fa) dfs(V, x);
	ru(i, 0, n) pre[0][i] = suf[i] = 1;
	ru(i, 0, (int)G[x].size() - 1)
	{
		int tmp = 0;
		ru(j, 0, n)
		{
			tmp = (tmp + f[G[x][i]][j]) % mo;
			pre[i + 1][j] = (ll)pre[i][j] * tmp % mo;
		}
	}
	rd(i, (int)G[x].size() - 1, 0)
	{
		int tmp = 0, sum = 0;
		ru(j, 0, n)
		{
			tmp = (tmp + f[G[x][i]][j]) % mo;
			sum = (sum + (ll)pre[i][j] * suf[j] % mo) % mo;
			f[x][j + 1] = (f[x][j + 1] + (ll)sum * f[G[x][i]][j + 1] % mo) % mo;
			suf[j] = (ll)suf[j] * tmp % mo;
		}
	}
//	printf("!!! %d\n", x);
//	ru(i, 0, n) printf("%d ", f[x][i]); printf("\n");
	ru(i, 0, n) f[x][i] = (f[x][i] + pre[(int)G[x].size()][i]) % mo;
//	printf("!!! %d\n", x);
//	ru(i, 0, n) printf("%d ", f[x][i]); printf("\n");
}
int main()
{
	scanf("%d%d", &n, &mo);
	ru(i, 0, n)
	{
		c[i][0] = c[i][i] = 1;
		ru(j, 1, i - 1) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mo; 
	}
	ru(i, 1, n - 1)
	{
		int x = read(), y = read();
		G[x].push_back(y), G[y].push_back(x);
	}
	G[1].push_back(0), dfs(1, 0);
	ru(i, 0, n) ans[i] = 1;
	for (auto V: G[1])
	{
		int sum = 0;
		ru(i, 0, n)
		{
			sum = (sum + f[V][i]) % mo;
			ans[i + 1] = (ll)ans[i + 1] * sum % mo;
		}
	}
//	ru(i, 0, n) printf("%d ", ans[i]); printf("\n");
	ru(i, 1, n - 1)
	{
		int tmp = 1, res = 0;
		rd(j, i, 1)
		{
			res = (res + (ll)tmp * c[i][j] % mo * ans[j] % mo) % mo;
			tmp = mo - tmp;
		}
		printf("%d ", res);
	}
	return 0;
}