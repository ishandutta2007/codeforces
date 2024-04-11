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
#define int long long
using namespace std;
const int mo = 998244353;
const int INF = 2e9;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
char s[maxn];
int f[maxn][2][2][2], n;
signed main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int x = 0;
	ru(i, 1, n) x = (x * 2 % mo + s[i] - '0') % mo;
	x = (x + 1) % mo;
	f[0][1][1][1] = 1;
	ru(i, 1, n) ru(a, 0, 1) ru(na, 0, 1) 
	{
		int tpa = 1; 
		if(a == 0 || (na == 0 && s[i] == '1')) tpa = 0;
		if(a == 1 && s[i] == '0' && na == 1) continue;
		ru(b, 0, 1) ru(nb, 0, 1) 
		{
			int tpb = 1; 
			if(b == 0 || (nb == 0 && s[i] == '1')) tpb = 0;
			if(b == 1 && s[i] == '0' && nb == 1) continue;
			ru(c, 0, 1) ru(nc, 0, 1)
			{ 
				if(na == nc && nb != na) continue;
				int tpc = 1; 
				if(c == 0 || (nc == 0 && s[i] == '1')) tpc = 0;
				if(c == 1 && s[i] == '0' && nc == 1) continue;
				f[i][tpa][tpb][tpc] = (f[i][tpa][tpb][tpc] + f[i - 1][a][b][c]) % mo;
			} 
		} 
	} 
	int ans = 0;
	ru(a, 0, 1) ru(b, 0, 1) ru(c, 0, 1) ans = (ans + f[n][a][b][c]) % mo;
	ans = ((ll)x * x % mo * x % mo - (ll)3 * ans % mo + mo) % mo;
	ans = (ans + (ll)x * x % mo * 3 % mo) % mo;
	ans = (ans + mo - x) % mo;
	printf("%d", ans);
	return 0;
}