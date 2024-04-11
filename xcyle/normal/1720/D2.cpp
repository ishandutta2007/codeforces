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
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define maxn 300005
#define N 10000005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn], ch[N][2], mx[N][2], tot;
void ins(int x, int y, int val)
{
	int now = 0;
	rd(i, 30, 0)
	{
		int k = (x >> i) & 1;
		if(!ch[now][k]) ch[now][k] = ++tot;
		now = ch[now][k];
		mx[now][(y >> i) & 1] = max(mx[now][(y >> i) & 1], val);
	}
}
int que(int x, int y)
{
	int res = 0, now = 0;
	rd(i, 30, 0)
	{
		int k = (x >> i) & 1;
		res = max(res, mx[ch[now][k ^ 1]][(y >> i) & 1]);
		if(!ch[now][k]) break;
		now = ch[now][k];
	}
	return res;
}
void solve()
{
	n = read();
	int ans = 0;
	ru(i, 0, tot) ch[i][0] = ch[i][1] = 0, mx[i][0] = mx[i][1] = 0; tot = 0;
	ru(i, 0, n - 1) 
	{
		int x = read(), t = x ^ i;
		int f = que(t, i) + 1;
		ins(t, x, f);
		ans = max(ans, f);
	}
	printf("%d\n", ans);
}
int main()
{
	int T = read();
	while(T--) solve(); 
	return 0;
}