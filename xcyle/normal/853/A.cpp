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
#define maxn 600005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, k, res[maxn];
ll c[maxn];
struct cmp
{
	inline bool operator ()(int x, int y)
	{
		return c[x] < c[y];
	}
};
priority_queue<int, vector<int>, cmp> q; 
int main()
{
	n = read(), k = read();
	ru(i, 1, n) c[i] = read(); ll ans = 0;
	ru(i, 1, n + k)
	{
		if(i <= n) q.push(i);
		if(i > k) { int tmp = q.top(); q.pop();
		res[tmp] = i; ans += (ll)(i - tmp) * c[tmp];}
	}
	printf("%lld\n", ans);
	ru(i, 1, n) printf("%d ", res[i]);
	return 0;
}