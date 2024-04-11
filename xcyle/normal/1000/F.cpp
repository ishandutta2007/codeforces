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
#include <unordered_set>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define mid ((l + r) >> 1)
#define maxn 500005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn], q;
int ans[maxn], las[maxn][2];
vector<pair<int, int> > que[maxn];
vector<int> t[maxn * 4];
inline void modify(int x, int l, int r, int a, int b, int val)
{
	if(a > b) return;
	if(a <= l && r <= b)
	{
		t[x].push_back(val);
		return;
	}
	if(a <= mid) modify(lc(x), l, mid, a, b, val);
	if(b > mid) modify(rc(x), mid + 1, r, a, b, val);
}
inline int query(int x, int l, int r, int pos)
{
	while(!t[x].empty()) 
	{
		if(l > las[t[x].back()][0]) break;
		t[x].pop_back();
	}
	if(!t[x].empty()) return t[x].back();
	if(l == r) return 0;
	if(pos <= mid) return query(lc(x), l, mid, pos);
	else return query(rc(x), mid + 1, r, pos);
}
int main()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	q = read();
	for (int i = 1; i <= q; i++) {int l = read(), r = read(); que[r].push_back(make_pair(l, i));}
	for (int i = 1; i <= n; i++)
	{
		las[a[i]][0] = las[a[i]][1], las[a[i]][1] = i;
		modify(1, 1, n, las[a[i]][0] + 1, las[a[i]][1], a[i]);
		for (auto V: que[i]) ans[V.second] = query(1, 1, n, V.first);
	}
	for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
	return 0;
}