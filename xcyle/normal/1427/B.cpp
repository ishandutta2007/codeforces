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
int n, k, a[100005], tot;
char s[100005];
void solve()
{
	n = read(), k = read(); tot = 0;
	scanf("%s", s + 1);
	int cnt = 0, ans = 0;
	int las = n;
	ru(i, 1, n)
	{
		if(s[i] == 'L') cnt++;
		if(s[i] == 'W')
		{
			ans++;
			if(las < i - 1) a[++tot] = i - las - 1;
			if(las == i - 1) ans++;
			las = i;
		}
	}
	k = min(k, cnt);
	if(cnt == n)
	{
		printf("%d\n", max(0, 2 * k - 1));
		return;
	}
	sort(a + 1, a + tot + 1);
	ans += 2 * k;
	ru(i, 1, tot)
	{
		if(k < a[i]) break;
		k -= a[i], ans++;
	}
	printf("%d\n", ans);
}
int main()
{
	int T = read();
	while(T--) solve(); 
	return 0;
}