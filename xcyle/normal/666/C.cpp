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
#define maxn 100005
#define B 505
using namespace std;
const int mo = 1e9 + 7;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int q, vis[maxn], que[maxn], que2[maxn], tot;
char s[maxn];
int ans[B][maxn];
int fac[maxn], inv[maxn], ifac[maxn], pw[maxn], pw2[maxn];
inline int calc(int x, int y) {return (ll)fac[x] * ifac[y] % mo * ifac[x - y] % mo;}
int main()
{
	q = read();
	scanf("%s", s + 1);
	int nowlen = strlen(s + 1) - 1;
	ru(i, 1, q)
	{
		vis[nowlen] = 1;
		int tp = read();
		if(tp == 1) {scanf("%s", s + 1); nowlen = strlen(s + 1) - 1;}
		else que[++tot] = read(), que2[tot] = nowlen;
	}
	fac[0] = fac[1] = inv[1] = ifac[0] = ifac[1] = 1;
	pw[0] = 1, pw[1] = 25, pw2[0] = 1, pw2[1] = 26;
	ru(i, 2, maxn - 1)
	{
		fac[i] = (ll)fac[i - 1] * i % mo;
		inv[i] = (ll)(mo - mo / i) * inv[mo % i] % mo;
		ifac[i] = (ll)ifac[i - 1] * inv[i] % mo;
		pw[i] = (ll)pw[i - 1] * 25 % mo; 
		pw2[i] = (ll)pw2[i - 1] * 26 % mo; 
	}
	int cnt = 0;
	ru(i, 0, maxn - 1) if(vis[i])
	{
		vis[i] = ++cnt;
		ans[cnt][0] = 1;
		ru(j, 1, maxn - 1)
		{
			ans[cnt][j] = (ll)26 * ans[cnt][j - 1] % mo;
			if(j - 1 - i >= 0) ans[cnt][j] = (ans[cnt][j] + mo - (ll)calc(j - 1, i) * pw[j - 1 - i] % mo) % mo;
//			printf("%d %d %d\n", i, j, ans[cnt][j]);
		}
	}
	ru(i, 1, tot) printf("%d\n", (mo + pw2[que[i]] - ans[vis[que2[i]]][que[i]]) % mo);
	return 0;
}