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
#define M 262143
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn], fa[maxn], cnt; ll ans = 0;
int mx[1 << 18], mx2[1 << 18], to[maxn], val[maxn]; 
inline int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
inline void check(int x, int y, int t)
{
	t += a[y], y = find(y);
	if(x != y && t > val[x]) val[x] = t, to[x] = y;
}
int main()
{
	cnt = n = read() + 1;
	a[0] = -1, fa[n] = n;
	ru(i, 1, n - 1) fa[i] = i, a[i] = read(), ans -= a[i];
	while(cnt > 1)
	{
		ru(i, 0, M) mx[i] = mx2[i] = 0;
		ru(i, 1, n) mx[a[i]] ? mx2[a[i]] = i : mx[a[i]] = i;
		ru(i, 0, 17) ru(j, 0, M) if((j >> i) & 1)
		{
			int id[4] = {mx[j], mx2[j], mx[j ^ (1 << i)], mx2[j ^ (1 << i)]};
			ru(k, 0, 3) if(a[mx[j]] < a[id[k]]) mx[j] = id[k];
			mx2[j] = 0;
			ru(k, 0, 3) if(find(id[k]) != find(mx[j]) && a[mx2[j]] < a[id[k]]) mx2[j] = id[k];
		}
		ru(i, 1, n) val[i] = -1, to[i] = 0;
		ru(i, 1, n) check(find(i), mx[M - a[i]], a[i]), check(find(i), mx2[M - a[i]], a[i]);
		ru(i, 1, n) if(find(i) == i && to[i] && find(to[i]) != i) fa[i] = find(to[i]), ans += val[i], cnt--;
	}
	printf("%lld\n", ans);
	return 0;
}