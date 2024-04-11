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
#define maxn 100005
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define B 305
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, Q, a[maxn], cnt[maxn]; ll ans[maxn];
struct node
{
	int l, r, id;
	inline bool operator < (const node &a) const
	{
		return l / B == a.l / B ? r < a.r : l / B < a.l / B;
	}
}p[maxn];
priority_queue<int> q;
multiset<int> t;
int num[B + 5], tmp[B + 5];
inline void modify(int pos, int val)
{
	if(cnt[pos] > B) t.erase(t.find(cnt[pos]));
	else num[cnt[pos]]--;
	cnt[pos] += val;
	if(cnt[pos] > B) t.insert(cnt[pos]);
	else num[cnt[pos]]++;
}
int main()
{
	n = read();
	ru(i, 1, n) a[i] = read();
	Q = read();
	ru(i, 1, Q) p[i] = {read(), read(), i};
	sort(p + 1, p + Q + 1);
	int nl = 1, nr = 0;
	ru(i, 1, Q)
	{
		while(nr < p[i].r) modify(a[++nr], 1);
		while(nl > p[i].l) modify(a[--nl], 1);
		while(nr > p[i].r) modify(a[nr--], -1);
		while(nl < p[i].l) modify(a[nl++], -1);
		ru(j, 1, B) tmp[j] = num[j];
		while(!q.empty()) q.pop();
		for (auto x: t) q.push(-x);
		int las = 0;
		ru(j, 1, B) if(tmp[j])
		{
			if(las)
			{
				las += j; ans[p[i].id] += las; tmp[j]--;
				if(las > B) q.push(-las);
				else tmp[las]++;
				las = 0;
			}
			if(tmp[j] & 1) las = j;
			ans[p[i].id] += (ll)2 * j * (tmp[j] / 2);
			if(2 * j > B) ru(k, 1, tmp[j] / 2) q.push(-2 * j);
			else tmp[2 * j] += tmp[j] / 2;
		}
		if(las) q.push(-las);
		while(q.size() > 1)
		{
			int x = -q.top(); q.pop();
			int y = -q.top(); q.pop();
			ans[p[i].id] += x + y;
			q.push(- x - y);
		}
	}
	ru(i, 1, Q) printf("%lld\n", ans[i]);
	return 0;
}