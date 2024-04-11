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
int n, a[maxn];
vector<int> pos[maxn];
int t[maxn];
inline void add(int x)
{
	for (; x <= n; x += x & (-x)) t[x]++;
}
inline int que(int x)
{
	int res = 0;
	for (; x; x -= x & (-x)) res += t[x];
	return res; 
}
int main()
{
	n = read();
	ru(i, 1, n) pos[a[i] = read()].push_back(i);
	int L = 1, R = n; ll ans = 0;
	rd(i, n, 1) if(pos[i].size())
	{
		int nL = min(pos[i][0], R + 1), nR = max(pos[i].back(), L - 1);
		L = nL, R = nR;
		ans += que(R) - que(L - 1);
		for (auto x: pos[i]) add(x); 
	}
	printf("%lld\n", ans + que(n));
	return 0;
}