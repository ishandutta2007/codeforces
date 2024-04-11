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
#define maxn 400005
using namespace std;
const int mo = 1e9 + 7;
const int INF = 1e9 + 1;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, b[maxn];
ll a[maxn];
int main()
{
	n = read(); int mx = 0;
	ru(i, 0, n - 1)
	{
		b[i] = read(); 
		mx = max(mx, b[i]);
	}
	if(mx == 0)
	{
		printf("YES\n");
		ru(i, 1, n) printf("1 ");
		return 0;
	}
	int pos = -1;
	ru(i, 0, n - 1)
	{
		if(b[i] == mx && b[(i + n - 1) % n] != mx) pos = i;
	}
	if(pos == -1) {printf("NO\n"); return 0;}
	a[pos] = b[pos];
	int now = (pos + n - 1) % n;
	while(now != pos)
	{
		if(a[(now + 1) % n] == a[pos] && b[now] == 0) a[now] = 2ll * a[pos];
		else a[now] = b[now] + a[(now + 1) % n];
		now = (now + n - 1) % n;
	}
	printf("YES\n");
	ru(i, 0, n - 1) printf("%lld ", a[i]);
	return 0;
}