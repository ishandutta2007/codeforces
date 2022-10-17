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
#define int long long
#define maxn 500005
using namespace std;
const int mo = 998244353;
const int INF = 1e16;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int SG[maxn], vis[100];
void init()
{
	ru(i, 0, 500000)
	{
		ru(j, 0, 50) vis[j] = 0;
		ru(j, 0, min(50ll, i - 2)) vis[SG[j] ^ SG[i - j - 2]] = 1;
		rd(j, 50, 0) if(!vis[j]) SG[i] = j;
	}
}
char s[maxn];
void solve()
{
	int n = read();
	scanf("%s", s + 1);
	int sum = 0;
	ru(i, 1, n)
	{
		if(s[i] == 'R') sum++;
		else sum--;
	}
	if(sum > 0) printf("Alice\n");
	if(sum < 0) printf("Bob\n");
	if(sum == 0)
	{
		int res = 0;
		int las = 1;
		ru(i, 2, n)
		{
			if(s[i] == s[i - 1])
			{
				res ^= SG[i - las];
				las = i;
			}
		}
		res ^= SG[n + 1 - las];
		if(res) printf("Alice\n");
		else printf("Bob\n");
	}
}
signed main()
{
	init();
	int T = read();
	while(T--) solve();
	return 0;
}