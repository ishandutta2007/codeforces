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
#define db double
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 200005
using namespace std;
const int mo = 1e9 + 7;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn], b[maxn], t[maxn], isep[maxn], lev[maxn];
vector<int> ep, pos[maxn];
int f[maxn], g[maxn], tmp[maxn];
inline void clear(int *A)
{
	for (int i = 0; i <= n; i++) A[i] = 0;
}
inline void add(int x, int d)
{
	for (; x <= n; x += (x & (-x))) t[x] = (t[x] + d) % mo;
}
inline int que(int x)
{
	int res = 0;
	for (; x; x -= (x & (-x))) res = (res + t[x]) % mo;
	return res;
}
void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) b[i] = a[i] = read();
	sort(b + 1, b + n + 1);
	int len = unique(b + 1, b + n + 1) - b - 1;
	for (int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + len + 1, a[i]) - b;
	int mx = 0; ep.clear();
	clear(isep);
	for (int i = 0; i <= n; i++) pos[i].clear();
	for (int i = n; i >= 1; i--)
	{
		if(a[i] >= mx)
		{
			mx = a[i]; isep[i] = 1;
			ep.push_back(i);
		}
	}
	int ans = 0;
	clear(t);
	for (int i = 1; i <= n; i++)
	{
		f[i] = (que(a[i] - 1) + 1) % mo;
		add(a[i], f[i]);
		tmp[i] = f[i];
	}
	clear(t);
	for (int i = 1; i <= n; i++)
	{
		g[i] = (que(a[i] - 1) + f[i]) % mo;
		add(a[i], g[i]);
		if(!isep[i]) ans = (ans + g[i]) % mo;
	}
	clear(t);
//	printf("%d\n", ans);
	for (int i = 1; i <= n; i++)
	{
		if(isep[i]) continue;
		int l = 0, r = ep.size() - 1, mid;
		while(l < r)
		{
			mid = (l + r) >> 1;
			if(a[ep[mid]] > a[i]) r = mid;
			else l = mid + 1;
		}
//		printf("%d ", l);
		lev[i] = l;
		pos[l].push_back(i);
	}
//	printf("\n");
	for (int i = 0; i < ep.size(); i++)
	{
		for (int j = pos[i].size() - 1; j >= 0; j--)
		{
			int loc = pos[i][j];
			if(loc > ep[i])
			{
				g[loc] = 0;
				continue;
			}
			g[loc] = (que(n) - que(a[loc]) + mo + 1) % mo;
//			printf("! %d %d\n", loc, g[loc]);
			add(a[loc], g[loc]);
		}
		for (auto loc: pos[i]) add(a[loc], -g[loc]);
	}
	for (int i = n; i >= 1; i--)
	{
		if(isep[i])
		{
			add(a[i], 1);
			continue;
		}
		f[i] = (que(n) - que(a[i]) + mo) % mo;
		add(a[i], f[i]);
		ans = (ans + (ll)tmp[i] * (f[i] - g[i] + mo) % mo) % mo;
	}
	for (int i = 1; i <= n; i++)
	{
		if(isep[i]) continue;
//		printf("%d %d\n", f[i], g[i]);
	}
	printf("%d\n", ans);
}
int main()
{
// 	freopen("data.in", "r", stdin);
// 	freopen("data.out", "w", stdout);
	int T = read();
	while(T--) solve();
	return 0;
}