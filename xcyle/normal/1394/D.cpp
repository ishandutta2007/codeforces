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
#define maxn 200005
using namespace std;
const ll INF = 1e12;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int b[maxn], n, F;
ll a[maxn], f[maxn][2], ans = INF;
vector<int> G[maxn];
inline bool cmp(int x, int y)
{
	if(x == F) return 0;
	if(y == F) return 1;
	return f[x][1] - f[x][0] < f[y][1] - f[y][0];
}
void dfs(int x, int fa)
{
	f[x][0] = f[x][1] = INF;
	for (auto V: G[x]) if(V != fa) dfs(V, x);
	F = fa, sort(G[x].begin(), G[x].end(), cmp);
	if(x != 1) G[x].pop_back();
	int cnt0 = G[x].size(), cnt1 = 0;
	ll now = 0;
	for (auto V: G[x]) now += f[V][0];
	if(x == 1) ans = min(ans, now + a[x] * max(cnt0, cnt1));
	f[x][0] = min(f[x][0], now + a[x] * max(cnt0, cnt1 + 1));
	f[x][1] = min(f[x][1], now + a[x] * max(cnt0 + 1, cnt1));
	for (auto V: G[x])
	{
		now += f[V][1] - f[V][0];
		cnt0--, cnt1++;
//		printf("%d %lld %d %d\n", x, now, cnt0, cnt1);
		if(x == 1) ans = min(ans, now + a[x] * max(cnt0, cnt1));
		f[x][0] = min(f[x][0], now + a[x] * max(cnt0, cnt1 + 1));
		f[x][1] = min(f[x][1], now + a[x] * max(cnt0 + 1, cnt1));
	}
	if(b[x] < b[fa]) f[x][1] = INF;
	if(b[x] > b[fa]) f[x][0] = INF;
//	printf("%d %lld %lld\n", x, f[x][0], f[x][1]);
}
int main()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= n; i++) b[i] = read();
	for (int i = 1; i < n; i++) {int x = read(), y = read(); G[x].push_back(y), G[y].push_back(x);}
	dfs(1, 1); printf("%lld", ans);
	return 0;
}