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
int num[26];
char s[100005];
void solve()
{
	scanf("%s", s + 1); int n = strlen(s + 1);
	memset(num, 0, sizeof(num));
	ru(i, 1, n) num[s[i] - 'a']++;
	ll ans = 0;
	ru(i, 0, 25) ans = max(ans, (ll)num[i]);
	ru(i, 0, 25) ru(j, 0, 25)
	{
		ll res = 0;
		int cnt = 0;
		ru(k, 1, n)
		{
			if(s[k] - 'a' == j) res += cnt;
			if(s[k] - 'a' == i) cnt++;
		}
		ans = max(ans, res);
	}
	printf("%lld\n", ans);
}
int main()
{
	solve();
	return 0;
}