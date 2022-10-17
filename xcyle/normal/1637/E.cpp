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
#define maxn 300005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m, a[maxn];
set<int> hav;
vector<int> buc[maxn];
vector<int> tmp;
map<int, int> cnt;
map<pair<int, int>, int> vis;
void solve()
{
	n = read(), m = read();
	vis.clear(), cnt.clear(), tmp.clear();
	for (int i = 1; i <= n; i++) buc[i].clear(), cnt[a[i] = read()]++, hav.clear();
	for (int i = 1; i <= m; i++){int x = read(), y = read(); vis[make_pair(x, y)] = vis[make_pair(y, x)] = 1;}
	for (auto x: cnt) buc[x.second].push_back(x.first), hav.insert(x.second);
	ll ans = 0;
	for (auto i: hav) for (auto j: hav)
	{
		for (int i2 = buc[i].size() - 1; i2 >= 0; i2--)
		{
			for (int j2 = buc[j].size() - 1; j2 >= 0; j2--)
			{
				if(buc[i][i2] == buc[j][j2]) continue;
				if(!vis[make_pair(buc[i][i2], buc[j][j2])])
				{
					ans = max(ans, (ll)(i + j) * (buc[i][i2] + buc[j][j2]));
					break;
				}
			}
			if(buc[i][i2] != buc[j][buc[j].size() - 1] && !vis[make_pair(buc[i][i2], buc[j][buc[j].size() - 1])]) break;
		}
	}
	printf("%lld\n", ans);
}
int main()
{
	int T = read(); while(T--) solve();
	return 0;
}