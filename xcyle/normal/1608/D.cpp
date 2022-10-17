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
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 100005
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, fac[maxn], inv[maxn], ifac[maxn];
char s[3];
int cnt[2][3];
int check(char c)
{
	if(c == 'B') return 0;
	if(c == 'W') return 1;
	return 2;
}
inline int calc(int x, int y)
{
	if(x < y || y < 0) return 0;
	return (ll)fac[x] * ifac[y] % mo * ifac[x - y] % mo;
}
int main()
{
	scanf("%d", &n);
	fac[0] = fac[1] = inv[1] = ifac[0] = ifac[1] = 1;
	for (int i = 2; i < maxn; i++)
	{
		fac[i] = (ll)fac[i - 1] * i % mo;
		inv[i] = (ll)(mo - mo / i) * inv[mo % i] % mo;
		ifac[i] = (ll)ifac[i - 1] * inv[i] % mo;
	}
	int tot0 = 0, tot1 = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		if(s[0] == '?' && s[1] == '?') tot0++;
		else if(s[0] == s[1]) tot1++;
		cnt[0][check(s[0])]++;
		cnt[1][check(s[1])]++;
	}
	int ans = 0;
	for (int i = 0; i <= cnt[0][2]; i++)
	{
		ans = (ans + (ll)calc(cnt[0][2], i) * calc(cnt[1][2], cnt[0][0] + i - cnt[1][1]) % mo) % mo;
	}
	if(!tot1)
	{
		int tmp = 1;
		for (int i = 1; i <= tot0; i++) tmp = (ll)tmp * 2 % mo;
		ans = (ans - tmp + mo) % mo;
		if(!cnt[0][0] && !cnt[1][1]) ans = (ans + 1) % mo;
		if(!cnt[0][1] && !cnt[1][0]) ans = (ans + 1) % mo;
	}
	printf("%d", ans);
	return 0;
}