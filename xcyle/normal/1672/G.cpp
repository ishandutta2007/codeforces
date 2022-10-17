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
#define rd(i, l, r) for (int i = (r); i >= (l); i--)
#define mid ((l + r) >> 1)
#define maxn 2005
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, cnt, num;
char s[maxn][maxn];
int val[2][maxn], vis[2][maxn];
int ans = 1, fl[2] = {1, 1};
int dfs(int tp, int x)
{
	int res = 0;
	cnt += val[tp][x] - 2, num ^= 1;
	vis[tp][x] = 1;
	if(!tp)
	{
		ru(i, 1, m) 
		{
			if(s[x][i] != '?') res ^= (s[x][i] - '0');
			else if(!vis[1][i]) res ^= dfs(1, i);
		}
	}
	else
	{
		ru(i, 1, n) 
		{
			if(s[i][x] != '?') res ^= (s[i][x] - '0');
			else if(!vis[0][i]) res ^= dfs(0, i);
		}
	}
	return res;
}
int main()
{
	n = read(), m = read();
	ru(i, 1, n) scanf("%s", s[i] + 1);
	ru(i, 1, n) ru(j, 1, m) val[0][i] += (s[i][j] == '?'); 
	ru(i, 1, m) ru(j, 1, n) val[1][i] += (s[j][i] == '?'); 
	if(n % 2 == 0 && m % 2 == 0)
	{
		ru(i, 1, n) ru(j, 1, m) if(s[i][j] == '?') ans = (ll)ans * 2 % mo;
		fl[0] = 0;
	}
	else if(n % 2 == 1 && m % 2 == 1)
	{
		ru(i, 1, n) if(!vis[0][i]) 
		{
			cnt = 2, num = 0;
			int res = dfs(0, i); cnt /= 2;
//			printf("tp0 %d %d %d %d\n", i, cnt, num, res);
			if(res & 1) fl[0] = 0;
			if(num != res) fl[1] = 0;
			while(cnt--) ans = ans * 2 % mo;
		}
		ru(i, 1, m) if(!vis[1][i])
		{
			cnt = 2, num = 0;
			int res = dfs(1, i); cnt /= 2;
			if(res & 1) fl[0] = 0;
			if(num != res) fl[1] = 0;
			while(cnt--) ans = ans * 2 % mo;
		}
	}
	else if(n % 2 == 0) 
	{
		for (int i = 1; i <= n; i++)
		{
			if(!val[0][i])
			{
				int tmp = 0;
				for (int j = 1; j <= m; j++) if(s[i][j] != '?') tmp ^= (s[i][j] - '0');
				fl[tmp ^ 1] = 0;
			}
			else ru(j, 1, val[0][i] - 1) ans = ans * 2 % mo;
		}
	}
	else if(m % 2 == 0) 
	{
		for (int i = 1; i <= m; i++)
		{
			if(!val[1][i])
			{
				int tmp = 0;
				for (int j = 1; j <= n; j++) if(s[j][i] != '?') tmp ^= (s[j][i] - '0');
				fl[tmp ^ 1] = 0;
			}
			else ru(j, 1, val[1][i] - 1) ans = ans * 2 % mo;
		}
	}
	printf("%d\n", (fl[0] + fl[1]) * ans % mo); 
	return 0;
}