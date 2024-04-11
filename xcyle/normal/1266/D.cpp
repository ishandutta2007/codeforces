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
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define maxn 1000005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m;
ll d[maxn];
struct node
{
	int u, v; ll w;
}; 
vector<node> ans;
int main()
{
	n = read(), m = read();
	ru(i, 1, m)
	{
		int x = read(), y = read(), z = read();
		d[x] += z, d[y] -= z;
	}
	
	int pos1 = 1, pos2 = 1;
	ru(i, 1, n)
	{
		if(d[i] > 0)
		{
			while(pos1 <= n)
			{
				if(d[pos1] < 0)
				{
					ll tmp = min(d[i], -d[pos1]);
					ans.push_back({i, pos1, tmp});
					d[i] -= tmp;
					d[pos1] += tmp;
					if(d[i] == 0) break;
				}
				pos1++;
			}
		} 
		else if(d[i] < 0)
		{
			while(pos2 <= n)
			{
				if(d[pos2] > 0)
				{
					ll tmp = min(-d[i], d[pos2]);
					ans.push_back({pos2, i, tmp});
					d[i] += tmp;
					d[pos2] -= tmp;
					if(d[i] == 0) break;
				}
				pos2++;
			}
		} 
	}
	printf("%d\n", (int)ans.size());
	for (auto x: ans) printf("%d %d %lld\n", x.u, x.v, x.w);
	return 0;
}