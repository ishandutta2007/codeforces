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
const int INF = 1e9 + 1;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, q, c[maxn], r[maxn], ed[maxn], tot, sta[maxn], T[maxn], top, ch[maxn * 40][2];
ll t[maxn * 40][2], tmp[maxn];
int insert(int x, int l, int r, int a, int b)
{
	int now = ++tot;
	t[now][0] = t[x][0] + a, t[now][1] = t[x][1] + b, ch[now][0] = ch[x][0], ch[now][1] = ch[x][1];
	if(l == r) return now;
	int mid = (l + r) >> 1;
	if(b / a <= mid) ch[now][0] = insert(ch[x][0], l, mid, a, b);
	else ch[now][1] = insert(ch[x][1], mid + 1, r, a, b);
	return now;
}
inline ll query(int x, int l, int r, int a, int b, int tp)
{
	if(a > b) return 0;
	if(a <= l && r <= b) return t[x][tp];
	int mid = (l + r) >> 1;
	ll res = 0;
	if(a <= mid) res += query(ch[x][0], l, mid, a, b, tp);
	if(b > mid) res += query(ch[x][1], mid + 1, r, a, b, tp);
	return res;
}
inline ll calc(int pos, int tt)
{
//	printf("query %d %d\n", pos, tt);
	return query(ed[pos], 1, INF, 1, tt - 1, 1) + query(ed[pos], 1, INF, tt, INF, 0) * tt;
}
int main()
{
	n = read();
	for (int i = 1; i <= n; i++) c[i] = read(), r[i] = read(), ed[i] = insert(ed[i - 1], 1, INF, r[i], c[i]);
	q = read();
	sta[top = 1] = n, T[top] = -INF, tmp[top] = 0; ll ans = 0;
	while(q--)
	{
		int tn = read();
		ll h;
		scanf("%lld", &h);
		sta[top + 1] = 0;
//		printf("\n");
//		for (int i = 1; i <= top; i++) printf("%d %d %lld\n", sta[i], T[i], tmp[i]);
		while(top)
		{
			ll dt = tn - T[top], temp = calc(sta[top] - 1, dt) - calc(sta[top + 1], dt);
//			printf("? %lld\n", temp);
			if(temp > h)
			{
				int l = sta[top + 1] + 1, r = sta[top] - 1, mid;
				while(l < r)
				{
					mid = (l + r) >> 1;
					if(calc(mid, dt) - calc(sta[top + 1], dt) > h) r = mid;
					else l = mid + 1;
				}
				tmp[top + 1] = calc(l, dt) - calc(sta[top + 1], dt) - h;
				sta[++top] = l, T[top] = tn;
//				printf("%d\n", l);
				break;
			}
			h -= temp;
			temp = min((ll)c[sta[top]], (ll)dt * r[sta[top]] + tmp[top]);
			if(temp > h)
			{
				tmp[top] = temp - h;
				T[top] = tn;
				break;
			}
			h -= temp, top--;
		}
		if(!top) ans += h, sta[top = 1] = n, T[top] = tn, tmp[top] = 0;
	}
	printf("%lld", ans);
	return 0;
}