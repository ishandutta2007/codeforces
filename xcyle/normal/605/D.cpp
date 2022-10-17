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
const int INF = 0x3f3f3f3f;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, dis[maxn];
int a[maxn], b[maxn], c[maxn], d[maxn], tmp[maxn], las[maxn], id[maxn], rk[maxn];
queue<int> q;
void out(int x)
{
	if(!x) return;
	out(las[x]);
	printf("%d ", x);
}
int t[1000005];
void modify(int x, int l, int r, int aim)
{
	if(l == r)
	{
		t[x] = id[l];
		return;
	}
	int mid = (l + r) >> 1;
	if(aim <= mid) modify(lc(x), l, mid, aim);
	else modify(rc(x), mid + 1, r, aim);
	t[x] = b[t[lc(x)]] > b[t[rc(x)]] ? t[rc(x)] : t[lc(x)];
}
int que(int x, int l, int r, int A, int B)
{
	if(A > B) return n + 1;
	if(A <= l && r <= B) return t[x];
	int mid = (l + r) >> 1, res = n + 1, temp;
	if(A <= mid) temp = que(lc(x), l, mid, A, B), res = (b[temp] >= b[res] ? res : temp);
	if(B > mid) temp = que(rc(x), mid + 1, r, A, B), res = (b[temp] >= b[res] ? res : temp);
	return res;
}
inline int cmp(int x, int y)
{
	return a[x] == a[y] ? b[y] < b[x] : a[x] < a[y];
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) a[i] = read(), b[i] = read(), c[i] = read(), d[i] = read(), tmp[i] = a[i];
	for (int i = 1; i <= n; i++) id[i] = i;
	sort(id + 1, id + n + 1, cmp);
	sort(tmp + 1, tmp + n + 1);
	for (int i = 1; i <= n; i++) c[i] = upper_bound(tmp + 1, tmp + n + 1, c[i]) - tmp - 1;
	for (int i = 1; i <= n; i++) modify(1, 1, n, i), rk[id[i]] = i;
	b[n + 1] = INF;
	for (int i = 1; i <= n; i++)
	{
		dis[i] = INF;
		if(a[i] == 0 && b[i] == 0)
		{
			dis[i] = 1;
			b[i] = INF;
			modify(1, 1, n, rk[i]);
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		while(1)
		{
			int pos = que(1, 1, n, 1, c[x]);
			if(b[pos] > d[x]) break;
			dis[pos] = dis[x] + 1, las[pos] = x;
			b[pos] = INF;
			modify(1, 1, n, rk[pos]);
			q.push(pos);
		}
	}
	if (dis[n] == INF) printf("-1\n");
	else
	{
		printf("%d\n", dis[n]);
		out(n);
	}
	return 0;
}