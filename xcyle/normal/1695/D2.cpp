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
int n, v[maxn];
vector<int> G[maxn];
void solve()
{
	n = read(); 
	ru(i, 1, n) G[i].clear(), v[i] = 0;
	ru(i, 1, n - 1)
	{
		int x = read(), y = read(); G[x].push_back(y), G[y].push_back(x);
	}
	if(n == 1) {printf("0\n"); return;}
	int fl = 1;
	ru(i, 1, n) fl &= (G[i].size() <= 2);
	if(fl) {printf("1\n"); return;}
	ru(i, 1, n) if(G[i].size() == 1)
	{
		int las = i, now = G[i][0];
		while(G[now].size() <= 2)
		{
			int tmp = now;
			now = G[now][0] ^ G[now][1] ^ las;
			las = tmp;
		}
		v[now]++;
	}
	int ans = 0;
	ru(i, 1, n) ans += max(0, v[i] - 1);
	printf("%d\n", ans);
}
int main()
{
	int T = read();
	while(T--) solve(); 
	return 0;
}