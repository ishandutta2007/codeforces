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
#define maxn 400005
#define NN 8000005
using namespace std;
const int INF = 0x3f3f3f3f;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, k, a[maxn], num;
char T[maxn];
int s[maxn], N;
map<int, int> ch[maxn];
int len[maxn], st[maxn], link[maxn], tot, now, rem;
int id[maxn], pos[maxn], alr = 1;
int ed[maxn], t[NN], tot2, ch2[NN][2];
inline int new_node(int S, int L)
{
	len[++tot] = L, st[tot] = S; return tot;
}
void insert(int x)
{
	s[++N] = x, rem++;
	for (int las = 1; rem; )
	{
		while(rem > len[ch[now][s[N - rem + 1]]]) rem -= len[now = ch[now][s[N - rem + 1]]];
		int &v = ch[now][s[N - rem + 1]]; int c = s[st[v] + rem - 1];
		if(!v || x == c)
		{
			link[las] = now, las = now;
			if(!v) v = new_node(N - rem + 1, INF);
			else break; 
		}
		else
		{
			int u = new_node(st[v], rem - 1);
			len[v] -= rem - 1, st[v] += rem - 1;
			ch[u][x] = new_node(N, INF), ch[u][c] = v;
			link[las] = v = u, las = u;
		}
		if(!now) rem--; else now = link[now];
		pos[tot] = id[alr++];
	}
}
ll ans[maxn];
int insert(int x, int l, int r, int pos) 
{
	int now = ++tot2;
	if(l == r)
	{
		t[now] = 1;
		return now;
	}
	int mid = (l + r) >> 1;
	ch2[now][0] = ch2[x][0], ch2[now][1] = ch2[x][1];
	if(pos <= mid) ch2[now][0] = insert(ch2[x][0], l, mid, pos);
	else ch2[now][1] = insert(ch2[x][1], mid + 1, r, pos);
	t[now] = t[ch2[now][0]] + t[ch2[now][1]];
	return now;
}
int merge(int x, int y, int l, int r)
{
	if(!x || !y) return x + y;
	int now = ++tot2, mid = (l + r) >> 1;
	if(l == r)
	{
		t[now] = t[x] | t[y];
		return now;
	}
	ch2[now][0] = merge(ch2[x][0], ch2[y][0], l, mid);
	ch2[now][1] = merge(ch2[x][1], ch2[y][1], mid + 1, r);
	t[now] = t[ch2[now][0]] + t[ch2[now][1]];
	return now;
}
void dfs(int x)
{
	if(pos[x]) ed[x] = insert(ed[x], 1, n, pos[x]);
	for (auto i: ch[x])
	{
		int V = i.second;
		dfs(V);
		ed[x] = merge(ed[x], ed[V], 1, n);
	}
//	if(st[x] >= 47) printf("%d %d %d %d\n", x, st[x], len[x], t[ed[x]]);
}
int dep[maxn];
void calc(int x)
{
	if(pos[x]) ans[pos[x]] += dep[x];
	for (auto i: ch[x])
	{
		int V = i.second;
		dep[V] = dep[x] + len[V] * (t[ed[V]] >= k);
		calc(V);
	}
}
int main()
{
	scanf("%d%d", &n, &k);
	len[0] = INF;
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", T + 1);
		a[i] = strlen(T + 1);
		num += a[i];
		for (int j = 1; j <= a[i]; j++) id[N + 1] = i, insert(T[j] - 'a');
		insert(26 + i);
	}
	if(k == 1)
	{
		for (int i = 1; i <= n; i++) printf("%lld ", (ll)a[i] * (a[i] + 1) / 2);
		return 0;
	}
	dfs(0);
	calc(0);
	for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
	return 0;
}