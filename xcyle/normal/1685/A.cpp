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
int n, a[200005], b[200005];
map<int, int> cnt;
void solve()
{
	n = read();
	cnt.clear();
	ru(i, 1, n) cnt[a[i] = read()]++;
	sort(a + 1, a + n + 1);
	int mx = 0, id = 0;
	for (auto x: cnt) if(x.second > mx) id = x.first, mx = x.second;
	if(n & 1 || mx * 2 > n || (mx * 2 == n && id != a[1] && id != a[n])) printf("NO\n");
	else 
	{
		printf("YES\n");
		int now = 1;
		ru(i, 1, n)
		{
			if(now > n) now = 2;
			b[now] = a[i];
			now += 2;
		}
		ru(i, 1, n) printf("%d ", b[i]);
		printf("\n");
	}
}
int main()
{
	int T = read();
	 while(T--) solve(); 
	return 0;
}