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
#define mid ((l + r) >> 1)
#define maxn 200005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn], pos[maxn];
ll nowc[maxn], m;
struct node
{
	int id, nxt;
	ll val, val2;
	inline bool operator < (const node &a) const
	{
		return val2 < a.val2;
	}
};
priority_queue<node> q;
int main()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = n; i >= 1; i--) a[i] -= a[i - 1];
	scanf("%lld", &m);
	for (int i = 1; i <= n; i++) 
	{
		m -= (ll)a[i] * a[i];
		pos[i] = 1;
		nowc[i] = (ll)a[i] * (a[i] - 1);
		ll te = a[i] / 2;
		ll tmp = (ll)a[i] * a[i] - te * te - (a[i] - te) * (a[i] - te);
		q.push({i, 2, tmp, tmp});
	}
	m = -m;
	if(m <= 0) {printf("0\n"); return 0;}
	ll ans = 0;
	while(1)
	{
		node x = q.top(); q.pop();
		int p = x.id;
		if(x.val >= m)
		{
			int t = a[p] / pos[p];
			ll tmp = (ll)t * (t + 1);
			printf("%lld\n", ans + (m + tmp - 1) / tmp);
			return 0;
		}
		m -= x.val, nowc[p] -= x.val; ans += x.nxt - pos[p], pos[p] = x.nxt;
		x.nxt = max(x.nxt + 1, a[p] / (a[p] / pos[p]));
		int t = a[p] / x.nxt;
		x.val = nowc[p] - (ll)t * (2ll * a[p] - x.nxt * (t + 1));
		x.val2 = x.val / (x.nxt - pos[p]);
		q.push(x);
	}
	return 0;
}