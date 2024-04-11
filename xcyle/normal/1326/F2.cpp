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
#define maxn 20
#define int long long
#define vint vector<int>
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n; char s[maxn][maxn];
int f[1 << 18][maxn], g[maxn][1 << 18], val[1 << 18];
int dp[maxn][1 << 18], ans[1 << 18];
vint l;
void FWT_or(int *f, int tp, int n)
{
	ru(i, 0, n - 1) ru(j, 0, (1 << n) - 1) if((j >> i) & 1) f[j] += tp * f[j ^ (1 << i)];
}
void FWT_and(int *f, int tp, int n)
{
	ru(i, 0, n - 1) ru(j, 0, (1 << n) - 1) if((j >> i) & 1) f[j ^ (1 << i)] += tp * f[j];
}
void init()
{
	ru(i, 0, n - 1) f[1 << i][i] = 1;
	ru(i, 0, (1 << n) - 1) val[i] = 1;
	ru(i, 0, (1 << n) - 1) ru(now, 0, n - 1) if((i >> now) & 1)
	{
		val[i] *= -1;
		int cnt = 0;
		ru(j, 0, n - 1) cnt += ((i >> j) & 1);
		g[cnt][i] += f[i][now];
		ru(nxt, 0, n - 1) if(!((i >> nxt) & 1) && s[now][nxt] == '1') f[i ^ (1 << nxt)][nxt] += f[i][now];
	}
	ru(i, 0, n) FWT_or(g[i], 1, n);
}
void dfs(int rem, int las, int dep)
{
	if(!rem)
	{
		int res = 0;
		ru(i, 0, (1 << n) - 1) res += dp[dep][(1 << n) - 1 - i] * val[i];
		vint tmp = l; sort(tmp.begin(), tmp.end());
		do
		{
			int now = 0, st = 0;
			for (auto x: tmp)
			{
				ru(j, 1, x - 1) st |= (1 << (now++));
				now++;
			}
			ans[st] = res;
		}
		while(next_permutation(tmp.begin(), tmp.end()));
		return;
	}
	ru(i, 1, min(las, rem))
	{
		l.push_back(i);
		ru(j, 0, (1 << n) - 1) dp[dep + 1][j] = g[i][j] * dp[dep][j];
		dfs(rem - i, i, dep + 1);
		l.pop_back();
	}
} 
signed main()
{
	n = read();
	ru(i, 0, n - 1) scanf("%s", s[i]);
	init();
	dp[0][0] = 1, FWT_or(dp[0], 1, n);
	dfs(n, n, 0);
	ru(i, 0, (1 << (n - 1)) - 1) ans[i] *= val[i];
	FWT_and(ans, 1, n);
	ru(i, 0, (1 << (n - 1)) - 1) ans[i] *= val[i];
	ru(i, 0, (1 << (n - 1)) - 1) printf("%lld ", ans[i]);
	return 0;
}