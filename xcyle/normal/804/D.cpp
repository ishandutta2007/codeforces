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
const int mo = 1e9 + 7;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m, q, color[maxn], cnt;
vector<double> chn[maxn], sum[maxn];
double len[maxn];
vector<int> G[maxn];
map<pair<int, int>, double> res;
int f[maxn], g[maxn];
void dfs1(int x, int fa)
{
	color[x] = color[fa];
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		if(V == fa) continue;
		dfs1(V, x);
		f[x] = max(f[x], f[V] + 1);
	}
}
int pre[maxn], suf[maxn];
void dfs2(int x, int fa)
{
	pre[0] = 0, suf[G[x].size()] = 0;
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		pre[i + 1] = pre[i];
		if(V == fa) continue;
		pre[i + 1] = max(pre[i + 1], f[V] + 1);
	}
	for (int i = G[x].size() - 1; i >= 0; i--)
	{
		int V = G[x][i];
		suf[i] = suf[i + 1];
		if(V == fa) continue;
		suf[i] = max(suf[i], f[V] + 1);
	}
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		if(V == fa) continue;
		g[V] = max(g[x] + 1, max(pre[i] + 1, suf[i + 1] + 1));
	}
	double mx = g[x], mx2 = 0;
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		if(V == fa) continue;
		if(f[V] + 1 > mx)
		{
			mx2 = mx;
			mx = f[V] + 1;
		}
		else if(f[V] + 1 > mx2)
		{
			mx2 = f[V] + 1;
		}
	}
	chn[color[x]].push_back(mx);
	len[color[x]] = max(len[color[x]], mx + mx2);
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		if(V == fa) continue;
		dfs2(V, x);
	}
}
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		if(!color[i])
		{
			color[i] = ++cnt;
			dfs1(i, i);
			dfs2(i, i);
			sort(chn[cnt].begin(), chn[cnt].end());
			for (int j = 0; j < chn[cnt].size(); j++) sum[cnt].push_back(0);
			double all = 0;
			for (int j = chn[cnt].size() - 1; j >= 0; j--)
			{
				all += chn[cnt][j];
				sum[cnt][j] = all;
			} 
//			printf("!!! %d %.1f\n", i, len[cnt]);
//			for (int j = 0; j < chn[cnt].size(); j++) printf("%.1f ", chn[cnt][j]);
//			printf("\n");
//			for (int j = 0; j < chn[cnt].size(); j++) printf("%.1f ", sum[cnt][j]);
//			printf("\n");
		}
	}
//	for (int i = 1; i <= cnt; i++)
//	{
//		for (int j = 0; j < chn[i].size(); j++) printf("%.1f ", chn[i][j]);
//		printf("\n");
//	}
	while(q--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a = color[a], b = color[b];
		if(chn[a].size() > chn[b].size()) swap(a, b);
		if(a == b)
		{
			printf("-1\n");
			continue;
		}
		if(res.find(make_pair(a, b)) != res.end())
		{
			printf("%.9f\n", res[make_pair(a, b)]);
			continue;
		}
		if(res.find(make_pair(b, a)) != res.end())
		{
			printf("%.9f\n", res[make_pair(b, a)]);
			continue;
		}
		double ans = 0, haha = max(len[a], len[b]);
//		printf("%d %d\n", a, b);
		for (int i = 0; i < chn[a].size(); i++)
		{
			int pos = upper_bound(chn[b].begin(), chn[b].end(), haha - chn[a][i] - 1) - chn[b].begin();
//			printf("??? %d %d\n", chn[a][i], pos);
			ans += (double)pos * haha;
			ans += (double)(chn[b].size() - pos) * (chn[a][i] + 1);
			ans += (double)sum[b][pos];
//			printf("%.1f\n", sum[b][pos]);
		}
		ans /= (double)chn[a].size() * chn[b].size();
		printf("%.9f\n", ans);
		res[make_pair(a, b)] = ans;
		res[make_pair(b, a)] = ans;
	}
	return 0;
}