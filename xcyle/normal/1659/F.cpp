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
int p[maxn], d[maxn];
void solve()
{
	int n = read(), x = read();
	ru(i, 1, n) d[i] = 0;
	ru(i, 1, n - 1) d[read()]++, d[read()]++;
	int rt = 0, cnt = 0;
	ru(i, 1, n) (d[i] == n - 1) && (rt = i);
	ru(i, 1, n) p[i] = read(), cnt += (p[i] != i);
	if(!rt || !cnt || (cnt == 2 && p[x] == x)) {printf("Alice\n"); return;}
	if(p[rt] != rt && (x == rt || x == p[rt])) {printf("Bob\n"); return;}
	cnt = (x != rt) ^ (n & 1);
	ru(i, 1, n) if(d[i])
	{
		for (int j = i; d[j]; d[j] = 0, j = p[j]);
		cnt ^= 1;
	}
	cnt ? printf("Alice\n") : printf("Bob\n");
}
int main()
{
	int T = read(); while(T--) solve();
	return 0;
}