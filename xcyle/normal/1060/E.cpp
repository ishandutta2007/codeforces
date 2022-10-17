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
#define maxn 500005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, siz[maxn], dep[maxn], cnt[2];
ll ans;
vector<int> G[maxn];
void dfs(int x, int fa)
{
	dep[x] = dep[fa] ^ 1, cnt[dep[x]]++;
	siz[x] = 1;
	for (auto V: G[x]) if(V ^ fa) dfs(V, x), siz[x] += siz[V];
	ans += (ll)siz[x] * (n - siz[x]);
}
int main()
{
	n = read();
	for (int i = 1; i < n; i++)
	{
		int x = read(), y = read();
		G[x].push_back(y), G[y].push_back(x);
	}
	dfs(1, 0);
	ans = (ans + (ll)cnt[0] * cnt[1]) / 2;
	printf("%lld\n", ans);
	return 0;
}