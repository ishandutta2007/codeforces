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
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m, k, rt, x, y, z;
int b[maxn], a[maxn];
int tot, rnd[maxn], val[maxn], val2[maxn], tmx[maxn], tag[maxn], siz[maxn], ch[maxn][2];
inline int new_node(int v, int t)
{
	rnd[++tot] = (ll)rand() * rand() % 1000000000;
	val[tot] = v, val2[tot] = tmx[tot] = t, siz[tot] = 1;
	return tot;
}
inline void pushup(int x){siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + 1; tmx[x] = max(max(tmx[ch[x][0]], tmx[ch[x][1]]), val2[x]);}
inline void pushdown(int x){tag[0] = val2[0] = tmx[0] = -1e9; tag[ch[x][0]] += tag[x], tmx[ch[x][0]] += tag[x], val2[ch[x][0]] += tag[x], tag[ch[x][1]] += tag[x], tmx[ch[x][1]] += tag[x], val2[ch[x][1]] += tag[x], tag[x] = 0;} 
inline void split(int now, int pos, int &x, int &y)
{
//	printf("%d %d %d %d\n", now, pos, x, y);
	if(!now) {x = y = 0; return;}
	pushdown(now);
	if(val[now] <= pos)
	{
		x = now;
		split(ch[now][1], pos, ch[x][1], y);
	}
	else
	{
		y = now;
		split(ch[now][0], pos, x, ch[y][0]);
	}
	pushup(now);
}
inline int merge(int x, int y)
{
//	printf("%d %d\n", x, y);
	if(!x || !y) return x + y;
	pushdown(x), pushdown(y);
	if(rnd[x] < rnd[y])
	{
		ch[x][1] = merge(ch[x][1], y);
		pushup(x);
		return x;
	}
	else
	{
		ch[y][0] = merge(x, ch[y][0]);
		pushup(y);
		return y;
	}
}
int main()
{
	val2[0] = tmx[0] = -1e9;
	srand(time(NULL));
	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; i++) b[i] = read();
	sort(b + 1, b + m + 1); 
	for (int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + m + 1, k - read()) - b;
//	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
//	printf("\n");
	int ans = 0;
	for (int i = n; i >= n - m + 1; i--)
	{
		split(rt, a[i], x, y);
		tag[y]--, tmx[y]--, val2[y]--;
		rt = merge(merge(x, new_node(a[i], a[i] - siz[x] - 1)), y);
	}
	if(tmx[rt] <= 0) ans++;
	for (int i = n - m; i >= 1; i--)
	{
		split(rt, a[i], x, y);
		tag[y]--, tmx[y]--, val2[y]--;
		rt = merge(merge(x, new_node(a[i], a[i] - siz[x] - 1)), y);
		split(rt, a[i + m], x, y);
		split(x, a[i + m] - 1, rt, z);
		tag[ch[z][1]]++, tmx[ch[z][1]]++, val2[ch[z][1]]++;
		z = merge(ch[z][0], ch[z][1]);
		tag[y]++, tmx[y]++, val2[y]++;
		rt = merge(merge(rt, z), y);
		if(tmx[rt] <= 0) ans++;
	}
	printf("%d\n", ans);
	return 0;
}