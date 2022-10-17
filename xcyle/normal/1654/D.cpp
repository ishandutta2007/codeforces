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
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, ans;
vector<int> G[maxn], val[maxn], val2[maxn];
int cnt[maxn];
int sum = 1;
int mx[maxn];
inline int ksm(int x, int step)
{
	int res = 1;
	for (; step; step >>= 1)
	{
		if(step & 1) res = (ll)res * x % mo;
		x = (ll)x * x % mo;
	}
	return res;
}
inline void work(int x, int tp)
{
	if(tp == -1) sum = (ll)sum * x % mo;
	else sum = (ll)sum * ksm(x, mo - 2) % mo;
	for (int i = 2; i * i <= x; i++)
	{
		if(x % i != 0) continue;
		int num = 0;
		while(x % i == 0) x /= i, num++;
		cnt[i] += tp * num;
		mx[i] = max(mx[i], cnt[i]);
	}
	if(x != 1)
	{
		cnt[x] += tp;
		mx[x] = max(mx[x], cnt[x]);
	}
}
void dfs(int x, int fa)
{
	if(x != 1)
	{
		int ta, tb;
		for (int i = 0; i < G[x].size(); i++) 
		{
			if(G[x][i] == fa) ta = val[x][i], tb = val2[x][i];
		}
		work(tb, -1), work(ta, 1);
	}
	ans = (ans + sum) % mo;
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		if(V == fa) continue;
		dfs(V, x);
	}
	if(x != 1)
	{
		int ta, tb;
		for (int i = 0; i < G[x].size(); i++) 
		{
			if(G[x][i] == fa) ta = val[x][i], tb = val2[x][i];
		}
		work(ta, -1), work(tb, 1);
	}
}
void solve()
{
	ans = 0, sum = 1;
	n = read();
	for (int i = 1; i <= n; i++) cnt[i] = mx[i] = 0, G[i].clear(), val[i].clear(), val2[i].clear();
	for (int i = 1; i < n; i++)
	{
		int pi = read(), pj = read(), x = read(), y = read();
		G[pi].push_back(pj), val[pi].push_back(y), val2[pi].push_back(x);
		G[pj].push_back(pi), val[pj].push_back(x), val2[pj].push_back(y);
	}
	sum = 1;
	dfs(1, 1);
	for (int i = 1; i <= n; i++)
	{
		ans = (ll)ans * ksm(i, mx[i]) % mo;
	}
	printf("%d\n", ans);
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}