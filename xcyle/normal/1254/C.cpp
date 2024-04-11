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
#define maxn 1000005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n;
struct node
{
	ll val; int id;
	inline bool operator < (const node &a) const
	{
		return val < a.val;
	}
}p[maxn];
int l[maxn], ltot;
int r[maxn], rtot;
inline int query2(int x, int y, int z)
{
	printf("2 %d %d %d\n", x, y, z); fflush(stdout);
	return read();
}
inline ll query1(int x, int y, int z)
{
	if(y == z) return 0;
	printf("1 %d %d %d\n", x, y, z); fflush(stdout);
	ll v; scanf("%lld", &v);
	return v;
}
int main()
{
	n = read();
	int now = 2;
	ru(i, 3, n) if(query2(1, i, now) == 1) now = i;
	ru(i, 2, n) p[i] = {query1(1, now, i), i};
	sort(p + 2, p + n + 1);
	rd(i, n - 1, 2)
	{
		if(query2(1, p[i].id, p[n].id) == 1) l[++ltot] = p[i].id;
		else r[++rtot] = p[i].id;
	}
	printf("0 1 ");
	rd(i, ltot, 1) printf("%d ", l[i]);
	printf("%d ", p[n].id);
	ru(i, 1, rtot) printf("%d ", r[i]);
	return 0;
}