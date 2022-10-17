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
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, q;
struct node
{
	ll x, y;
	inline bool operator < (const node &a) const
	{
		return x == a.x ? y > a.y : x < a.x;
	}
}p[maxn], sta[maxn];
int top;
inline int check(node a, node b, node c)
{
	return (ll)(c.y - b.y) * (b.x - a.x) >= (ll)(b.y - a.y) * (c.x - b.x);
}
int main()
{
	n = read();
	ru(i, 1, n) p[i].x = read(), p[i].y = read() - (ll)p[i].x * p[i].x; 
	sort(p + 1, p + n + 1);
	ru(i, 1, n)
	{
		while(top > 1 && check(sta[top - 1], sta[top], p[i])) top--;
		sta[++top] = p[i];
	}
	if(sta[top - 1].x == sta[top].x) top--;
	if(sta[1].x == sta[2].x) top--;
	printf("%d\n", max(0, top - 1));
	return 0;
}