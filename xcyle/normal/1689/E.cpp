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
#define maxn 2005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn], fa[maxn];
inline int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
int check()
{
	ru(i, 1, n) fa[i] = i;
	ru(j, 0, 30)
	{
		int las = 0;
		ru(i, 1, n) if((a[i] >> j) & 1)
		{
			if(!las) las = find(i);
			fa[find(i)] = las;
		}
	}
	ru(i, 1, n) if(find(i) != find(1)) return 0;
	return 1;
}
void solve()
{
	n = read();
	int ans = 0;
	ru(i, 1, n)
	{
		a[i] = read();
		if(!a[i]) a[i]++, ans++;
	}
	if(check()) 
	{
		printf("%d\n", ans);
		ru(i, 1, n) printf("%d ", a[i]); printf("\n");
		return;
	}
	ans++;
	ru(i, 1, n)
	{
		a[i]++;
		if(check())
		{
			printf("%d\n", ans);
			ru(i, 1, n) printf("%d ", a[i]); printf("\n");
			return;
		}
		a[i] -= 2;
		if(check())
		{
			printf("%d\n", ans);
			ru(i, 1, n) printf("%d ", a[i]); printf("\n");
			return;
		}
		a[i]++;
	}
	ans++;
	int mx = 0;
	ru(i, 1, n) mx = max(mx, a[i] & (-a[i]));
	int x = 0, y = 0;
	ru(i, 1, n) if((a[i] & (-a[i])) == mx)
	{
		if(!x) x = i;
		else y = i;
	}
	a[x]--, a[y]++;
	printf("%d\n", ans);
	ru(i, 1, n) printf("%d ", a[i]); printf("\n");
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}