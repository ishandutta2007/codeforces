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
#define maxn 200005
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn], rt, LOG[maxn], st[maxn][22], pos[maxn];
pii ans = mp(1e9, 0);
inline int calc(int l, int r)
{
	if(l > r) return 0;
	int len = LOG[r - l + 1];
	int M = pos[min(st[l][len], st[r - (1 << len) + 1][len])];
	return max(calc(l, M - 1), calc(M + 1, r)) + 1;
}
inline int check(int beg)
{
	rd(i, n - 1, 0)
	{
		pos[st[i][0] = a[(beg + i) % n]] = i;
		ru(j, 1, 20) if(i + (1 << j) - 1 < n) 
		{
			st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}
	int RT = 0;
	ru(i, 0, n - 1) if(st[i][0] == 1) RT = i;
	int x = calc(0, RT - 1), y = calc(RT + 1, n - 1);
//	printf("%d %d %d\n", beg, x, y);
	ans = min(ans, mp(max(x, y) + 1, beg));
	return x > y;
}
int main()
{
	ru(i, 2, maxn - 1) LOG[i] = LOG[i >> 1] + 1;
	n = read();
	ru(i, 0, n - 1) a[i] = read(), (a[i] == 1) && (rt = i);
	if(!check(0))
	{
		int l = rt + 1, r = n;
		while(l <= r) check(mid) ? l = mid + 1 : r = mid - 1;
		printf("%d %d\n", ans.fi, ans.se);
	}
	else
	{
		int l = 0, r = rt;
		while(l <= r) check(mid) ? l = mid + 1 : r = mid - 1;
		printf("%d %d\n", ans.fi, ans.se);
	}
	return 0;
}