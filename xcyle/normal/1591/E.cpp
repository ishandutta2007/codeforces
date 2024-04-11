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
#define maxn 1000005
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int T, n, q, a[maxn];
vector<int> G[maxn];
set<int> id[maxn];
int cnt[maxn], num[maxn];
struct node
{
	int l, k, id;
};
vector<node> que[maxn];
int ans[maxn];
void dfs(int x)
{
	if(cnt[a[x]]) id[cnt[a[x]]].erase(a[x]);
	id[++cnt[a[x]]].insert(a[x]);
	num[cnt[a[x]]]++;
	for (int i = 0; i < que[x].size(); i++)
	{
		node t = que[x][i];
		if(num[t.l] < t.k)
		{
			ans[t.id] = -1;
			continue;
		}
		int need = num[t.l] - t.k + 1;
		int l = t.l, r = n, mid;
		while(l < r)
		{
			mid = (l + r + 1) >> 1;
			if(num[mid] >= need) l = mid;
			else r = mid - 1;
		}
		ans[t.id] = (*id[l].begin());
	}
	for (int i = 0; i < G[x].size(); i++) dfs(G[x][i]);
	num[cnt[a[x]]]--;
	id[cnt[a[x]]--].erase(a[x]);
	if(cnt[a[x]]) id[cnt[a[x]]].insert(a[x]);
}
void solve()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) G[i].clear(), que[i].clear();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 2; i <= n; i++) G[read()].push_back(i);
	for (int i = 1; i <= q; i++)
	{
		int v = read(), l = read(), k = read();
		que[v].push_back({l, k, i});	
	}
	dfs(1);
	for (int i = 1; i <= q; i++) printf("%d ", ans[i]);
	printf("\n");
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}