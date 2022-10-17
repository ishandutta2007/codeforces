/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <bits/stdc++.h>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define ru(i, l, r) for (int i = (l); i <= (r); i++)
#define rd(i, r, l) for (int i = (r); i >= (l); i--)
#define mid ((l + r) >> 1)
#define maxn 800005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, q, p[maxn], pos[maxn];
ll sum1, sum2;
void work(int x, int val)
{
	if(x <= n + 1)
	{
		sum1 += val * ((pos[x] - pos[x == 1 ? n + 1 : x - 1] + 2 * n + 1) % (2 * n + 1));
		sum1 += val * ((pos[x == n + 1 ? 1 : x + 1] - pos[x] + 2 * n + 1) % (2 * n + 1));
	}
	if(x >= n + 1)
	{
		sum2 += val * ((pos[x] - pos[x == n + 1 ? 2 * n + 1 : x - 1] + 2 * n + 1) % (2 * n + 1));
		sum2 += val * ((pos[x == 2 * n + 1 ? n + 1 : x + 1] - pos[x] + 2 * n + 1) % (2 * n + 1));
	}
}
int mn[maxn], loc[maxn], sum[maxn];
void upd(int x, int l, int r, int pos)
{
	if(l == r) 
	{
		if(p[l] <= n) sum[x] = mn[x] = -1, loc[x] = l;
		else sum[x] = p[l] > n + 1, mn[x] = 0, loc[x] = l - 1;
		return;
	}
	if(pos <= mid) upd(lc(x), l, mid, pos);
	else upd(rc(x), mid + 1, r, pos);
	sum[x] = sum[lc(x)] + sum[rc(x)];
	mn[x] = min(mn[lc(x)], sum[lc(x)] + mn[rc(x)]);
	if(mn[lc(x)] == mn[x]) loc[x] = loc[lc(x)];
	else loc[x] = loc[rc(x)];
}
int que(int x, int l, int r, int pos)
{
	if(r <= pos) return sum[x];
	int res = que(lc(x), l, mid, pos);
	if(pos > mid) res += que(rc(x), mid + 1, r, pos);
	return res;
}
void check(int x, int l, int r)
{
//	printf("%d %d %d\n", l, r, sum[x]);
	if(l == r) return;
	check(lc(x), l, mid), check(rc(x), mid + 1, r);
}
int main()
{
	n = read(), q = read();
	ru(i, 1, 2 * n + 1) pos[p[i] = read()] = i;
	ru(i, 1, 2 * n + 1) upd(1, 1, 2 * n + 1, i);
	ru(i, 1, n + 1) sum1 += (2 * n + 1 + pos[i % (n + 1) + 1] - pos[i]) % (2 * n + 1);
	ru(i, n + 1, 2 * n + 1) sum2 += (2 * n + 1 + pos[i == 2 * n + 1 ? n + 1 : i + 1] - pos[i]) % (2 * n + 1);
	check(1, 1, 2 * n + 1);
	while(q--)
	{
		int u = read(), v = read();
		work(p[u], -1), pos[p[u]] = v, work(p[u], 1);
		work(p[v], -1), pos[p[v]] = u, work(p[v], 1);
		swap(p[u], p[v]);
		upd(1, 1, 2 * n + 1, u), upd(1, 1, 2 * n + 1, v);
//		printf("! %d\n", mn[1]);
		if(mn[1] != que(1, 1, 2 * n + 1, pos[n + 1])) printf("%d\n", loc[1] % (2 * n + 1));
		else if(sum1 != 2 * n + 1) printf("%d\n", pos[n + 1] % (2 * n + 1));  
		else if(sum2 != 2 * n + 1) printf("%d\n", pos[n + 1] - 1);  
		else printf("-1\n");
	}
	return 0;
}