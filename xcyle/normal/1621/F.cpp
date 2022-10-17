/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#define db double
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 200005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n;
ll a, b, c;
char s[maxn];
int siz[maxn], top;
void solve()
{
	scanf("%d%lld%lld%lld%s", &n, &a, &b, &c, s + 1);
	int cnt[2] = {0, 0}, num[2] = {0, 0};
	for (int i = 1; i <= n; i++) num[s[i] - '0']++; 
	for (int i = 2; i <= n; i++)
	{
		if(s[i] == s[i - 1]) cnt[s[i] - '0']++;
	} 
//	printf("%d %d %d %d\n", cnt[0], cnt[1], num[0], num[1]);
	ll ans = (a + b) * min(cnt[0], cnt[1]);
	int las = -1;
	top = 0;
	for (int i = 1; i <= n; i++)
	{
		if(s[i] == '1')
		{
			if(las != i - 1 && las != -1) siz[++top] = i - las - 2;
			las = i;
		}
	}
	sort(siz + 1, siz + top + 1);
	if(cnt[1] > cnt[0])
	{
		ans += b;
		if(b - c > 0) ans += (b - c) * min(num[1] - cnt[0] - 2, num[0] - cnt[0]);
	}
	else
	{
		if(b - c > 0)
		{
			int rem = cnt[1];
			for (int i = 1; i <= top; i++)
			{
				if(rem >= siz[i])
				{
					rem -= siz[i];
					ans += b - c;
				}
			}
		}
		if(cnt[1] < cnt[0]) ans += a; 
	}
	printf("%lld\n", ans);
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}