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
int n, pos[maxn], pres[maxn];
char s[maxn];
void solve()
{
	scanf("%d%s", &n, s + 1);
	ru(i, 0, n) pos[i] = 0;
	int sum = 0;
	ru(i, 1, n) sum += 2 * (s[i] - '0') - 1;
	if(sum > 0)
	{
		ru(i, 1, n) s[i] = '1' - (s[i] - '0');
		ru(i, 1, n / 2) swap(s[i], s[n - i + 1]);
	}
	ru(i, 1, n) 
	{
		pres[i] = pres[i - 1] + 1 - 2 * (s[i] - '0');
		if(pres[i] >= 0) pos[pres[i]] = i;
	}
	ru(i, 1, n) pos[i] = max(pos[i], pos[i - 1]);
	while(n && s[n] == '1') n--;
	int now = 0, ans = 0;
	while(now < n && s[now + 1] == '0') now++;
	while(now < n)
	{
		ans++;
		int cnt0 = (now + pres[now]) / 2;
		now = pos[cnt0];
	}
	printf("%d\n", ans);
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}