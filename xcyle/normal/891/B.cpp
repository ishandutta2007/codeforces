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
int n, a[2005];
struct node
{
	int val, id;
	inline bool operator < (const node &a) const
	{
		return val < a.val;
	}
}p[2005];
int ans[2005];
int main()
{
	n = read();
	ru(i, 1, n) a[i] = read(), p[i] = {a[i], i};
	sort(p + 1, p + n + 1);
	ru(i, 1, n) ans[p[i].id] = p[i % n + 1].id;
	ru(i, 1, n) printf("%d ", a[ans[i]]);
	return 0;
}