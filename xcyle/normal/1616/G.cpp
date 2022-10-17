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
#define maxn 150005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m, a[maxn], b[maxn], sum[maxn];
vector<int> G[maxn];
int f[maxn][2];// 
int g[maxn][2];
void solve()
{
	n = read(), m = read();
	for (int i = 0; i <= n; i++) sum[i] = 0, G[i].clear(), f[i][0] = f[i][1] = g[i][0] = g[i][1] = 0;
	for (int i = 1; i <= m; i++)
	{
		a[i] = read(), b[i] = read();
		if(b[i] == a[i] + 1) sum[b[i]] = 1;
	}
	for (int i = 1; i <= n; i++) sum[i] += sum[i - 1];
	if(sum[n] == n - 1)
	{
		printf("%lld\n", (ll)n * (n - 1) / 2);
		return;
	}
	for (int i = 1; i <= m; i++)
	{
		if(b[i] > a[i] + 1 && sum[b[i] - 1] - sum[a[i] + 1] == b[i] - a[i] - 2) G[a[i]].push_back(b[i] - 1);
	}
	int l = 0, r = 0; 
	for (int i = 2; i <= n; i++) if(sum[i] == sum[i - 1]) {l = i - 1; break;}
	for (int i = n; i >= 1; i--) if(sum[i] == sum[i - 1]) {r = i; break;}
	for (int i = 1; i <= l; i++) G[0].push_back(i);
	for (int i = r - 1; i < n; i++) G[i].push_back(n); 
	int cntl[4] = {0, 0, 0, 0}, cntr[4] = {0, 0, 0, 0}; 
	f[l][0] = 1;
	for (int i = l; i <= n; i++)
	{
		for (auto V: G[i]) f[V][0] |= f[i][1], f[V][1] |= f[i][0];
		if(i >= r) cntr[(f[i][0] << 1) + f[i][1]]++;
	}
	g[l][0] = 1;
	for (int i = l - 1; i >= 0; i--)
	{
		for (auto V: G[i]) g[i][0] |= g[V][1], g[i][1] |= g[V][0];
		cntl[(g[i][0] << 1) + g[i][1]]++;
	}
	ll ans = ((l + 1 < r - 1) & f[r - 1][0]);
	for (int i = 0; i <= min(r - 2, l - 1); i++) ans += (g[i][0] & f[r - 1][0]) | (g[i][1] & f[r - 1][1]);
	for (int i = max(l + 1, r); i <= n; i++) ans += (f[i][0] & g[l][0]) | (f[i][1] & g[l][1]);
	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) if(i & j) ans += (ll)cntl[i] * cntr[j];
	printf("%lld\n", ans);
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}