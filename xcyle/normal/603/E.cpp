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
int n, m, ans[maxn], pos[maxn];
struct node
{
	int u, v, w, id;
	inline bool friend operator < (node aa, node bb)
	{
		return aa.w < bb.w;
	}
}p[maxn]; 
int fa[maxn], siz[maxn];
struct opt
{
	int u, v, su, sv;
}sta[maxn];
int top;
int cnt = 0;
inline int find(int x)
{
	while(x != fa[x]) x = fa[x];
	return x;
}
void add(int edge)
{
	int fx = find(p[edge].u), fy = find(p[edge].v);
	if(fx == fy) return;
	if(siz[fx] < siz[fy]) swap(fx, fy);
	sta[++top] = {fx, fy, siz[fx], siz[fy]};
	if(siz[fx] & 1) cnt--;
	if(siz[fy] & 1) cnt--;
	siz[fx] += siz[fy], fa[fy] = fx;
	if(siz[fx] & 1) cnt++;
}
void del()
{
	int fu = sta[top].u, fv = sta[top].v;
	if(siz[fu] & 1) cnt--;
	siz[fu] = sta[top].su, siz[fv] = sta[top].sv;
	fa[fu] = fu, fa[fv] = fv;
	top--;
	if(siz[fu] & 1) cnt++;
	if(siz[fv] & 1) cnt++;
}
void solve(int l, int r, int a, int b)
{
//	printf("%d %d %d %d\n", l, r, a, b);
	if(l > r) return;
	int mid = (l + r) >> 1, now = top;
	for (int i = l; i <= mid; i++)
	{
		if(pos[i] < a) add(pos[i]);
	}
	for (ans[mid] = a; ans[mid] <= b; ans[mid]++)
	{
		if(p[ans[mid]].id <= mid) add(ans[mid]);
		if(cnt == 0 || ans[mid] == b) break;
	}
	while(top != now) del();
	for (int i = a; i < ans[mid]; i++) if(p[i].id < l) add(i);
	solve(l, mid - 1, ans[mid], b);
	while(top != now) del();
	for (int i = l; i <= mid; i++) if(pos[i] < a) add(pos[i]);
	solve(mid + 1, r, a, ans[mid]);
	while(top != now) del();
}
int main()
{
	scanf("%d%d", &n, &m);
	cnt = n;
	for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
	for (int i = 1; i <= m; i++) p[i].u = read(), p[i].v = read(), p[i].w = read(), p[i].id = i;
	sort(p + 1, p + m + 1);
	for (int i = 1; i <= m; i++) pos[p[i].id] = i;
	solve(1, m, 1, m + 1);
	for (int i = 1; i <= m; i++)
	{
//		printf("%d\n", ans[i]);
		if(ans[i] > m) printf("-1\n");
		else printf("%d\n", p[ans[i]].w);
	}
	return 0; 
}