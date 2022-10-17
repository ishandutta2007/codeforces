
/*
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC target("avx")

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
#define maxn 400005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, tp[maxn], h[maxn], vis[maxn], ans[maxn], dis[maxn];
vector<int> G[maxn], buc[maxn];
int q[2][maxn], l[2], r[2];
int main()
{
	n = read();
	for (int i = 1; i <= n; i++) tp[i] = read();
	for (int i = 1; i < n; i++) {int x = read(), y = read(); G[x].push_back(y), G[y].push_back(x);}
	for (int i = 1; i <= n; i++) if(tp[i] == 1) buc[1].push_back(i), h[i] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (auto x: buc[i]) for (auto V: G[x]) if(!h[V]) h[V] = i + 1, buc[i + 1].push_back(V);
		buc[i].clear();
	}
	for (int i = 1; i <= n; i++) for (auto V: G[i]) if(h[i] == h[V]) buc[h[i]].push_back(i);
	for (int i = 1; i <= n; i++) ans[i] = h[i] - 1;
	for (int i = n; i >= 1; i--)
	{
		if(buc[i].size() == 0) continue;
		for (int j = 1; j <= n; j++) dis[j] = n;
		l[0] = 1, r[0] = 0;
		int las = 0, now = 1;
		for (auto x: buc[i]) dis[x] = 0, q[las][++r[las]] = x;
		for (int j = i; j <= n; j++)
		{
			l[now] = 1, r[now] = 0;
			while(l[las] <= r[las])
			{
				int x = q[las][l[las]];
				for (auto V: G[x])
				{
					if(h[V] == h[x] && dis[V] > dis[x] + 1) dis[V] = dis[x] + 1, q[las][++r[las]] = V;
					if(h[V] == h[x] + 1 && dis[V] > max(0, dis[x] - 1)) dis[V] = max(0, dis[x] - 1), q[now][++r[now]] = V;
				}
				l[las]++;
			}
			swap(las, now);
		}
		for (int j = 1; j <= n; j++) if(!dis[j]) ans[j] = 2 * h[j] - i - 1;
	}
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	return 0;
}