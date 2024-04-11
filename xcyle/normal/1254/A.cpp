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
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, k;
char s[105][105], ans[105][105];
char work(int tp)
{
	if(tp <= 9) return '0' + tp;
	if(tp <= 35) return 'a' + tp - 10;
	return 'A' + tp - 36;
}
void solve()
{
	n = read(), m = read(), k = read();
	int tot = 0;
	ru(i, 1, n) 
	{
		scanf("%s", s[i] + 1);
		ru(j, 1, m) tot += s[i][j] == 'R';
	}
	int now = 0, tp = 0;
	ru(i, 1, n)
	{
		if(i & 1)
		{
			ru(j, 1, m)
			{
				ans[i][j] = work(tp);
				if(s[i][j] == 'R')
				{
					now++;
					if(k > 1 && now >= (tot + k - 1) / k)
					{
						tot -= now;
						now = 0;
						tp++;
						k--;
					}
				}
			}
		}
		else
		{
			rd(j, m, 1)
			{
				ans[i][j] = work(tp);
				if(s[i][j] == 'R')
				{
					now++;
					if(k > 1 && now >= (tot + k - 1) / k)
					{
						tot -= now;
						now = 0;
						tp++;
						k--;
					}
				}
			}
		}
	}
	ru(i, 1, n)
	{
		ru(j, 1, m) printf("%c", ans[i][j]); printf("\n");
	}
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}