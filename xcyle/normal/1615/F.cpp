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
#define maxn 2010
using namespace std;
const int mo = 1e9 + 7;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, beg;
char s[maxn], t[maxn];
int f[maxn][maxn * 2][2];
inline void add(int &x, int y) {x = (x + y) % mo;}
void calc(int step, int val)
{
	if(f[step][val][0] != -1) return;
	f[step][val][0] = f[step][val][1] = 0;
	int tmp = (val - beg) > 0 ? (val - beg) : -(val - beg);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if(s[step] != '?' && s[step] - '0' != i) continue;
			if(t[step] != '?' && t[step] - '0' != j) continue;
			int nxtval = val;
			if(step & 1) nxtval += i - j;
			else nxtval -= i - j;
			calc(step - 1, nxtval);
			add(f[step][val][0], f[step - 1][nxtval][0]);
			add(f[step][val][1], f[step - 1][nxtval][1]);
			add(f[step][val][1], (ll)f[step - 1][nxtval][0] * tmp % mo);
		}
	}
//	printf("%d %d %d %d\n", step, val - n - 1, f[step][val][0], f[step][val][1]);
}
void solve()
{
	scanf("%d%s%s", &n, s + 1, t + 1);
	beg = ((n + 2) ^ ((n + 2) & 1));
	for (int i = 0; i <= 2 * n + 2; i++) f[0][i][0] = 0;
	f[0][beg][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 2 * n + 2; j++)
		{
			f[i][j][0] = -1;
		}
	}
	calc(n, beg);
	printf("%d\n", f[n][beg][1]);
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}