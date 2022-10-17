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
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, vis[maxn], st[maxn];
ll val[maxn], t[maxn], ans;
void dfs(int step)
{
	vector<int> tmp;
	tmp.clear();
	ll sum[2] = {0, 0};
	for (int i = 1; i <= n; i++)
	{
		if(vis[i]) continue;
		int k = ((t[i] >> step) & 1);
		sum[k] += val[i];
		if(k) tmp.push_back(i), vis[i] = 1;
	}
	if(sum[1] > sum[0])
	{
		ans ^= (1ll << step);
		for (int i = 1; i <= n; i++)
		{
			if((t[i] >> step) & 1) st[i] ^= 1;
		}
		return;
	}
	dfs(step + 1);
	sum[0] = sum[1] = 0;
	for (auto x: tmp) sum[st[x]] += val[x];
	if(sum[0] < sum[1]) return;
	ans ^= (1ll << step);
	for (int i = 1; i <= n; i++)
	{
		if((t[i] >> step) & 1) st[i] ^= 1;
	}
}
int main()
{
	n = read();
	ll sum = 0;
	for (int i = 1; i <= n; i++) scanf("%lld%lld", &val[i], &t[i]);
	for (int i = 1; i <= n; i++) sum += val[i];
	if(sum < 0)
	{
		for (int i = 1; i <= n; i++) val[i] = -val[i];
	} 
	dfs(0);
	printf("%lld", ans);
	return 0;
}