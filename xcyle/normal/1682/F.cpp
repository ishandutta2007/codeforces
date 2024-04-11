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
#define maxn 200005
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int mo = 1e9 + 7;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, q, a[maxn], b[maxn]; ll sum[maxn], ans[maxn];
vector<pii> que[maxn];
ll t[maxn], tcnt[maxn], cnt[maxn], val[maxn]; int rnd[maxn], ch[maxn][2], tot, rt, x, y;
inline void pushup(int x)
{
	tcnt[x] = tcnt[ch[x][0]] + tcnt[ch[x][1]] + cnt[x];
	t[x] = ((ll)cnt[x] * (val[x] % mo + mo) % mo + t[ch[x][0]] + t[ch[x][1]]) % mo;
}
int merge(int x, int y)
{
	if(!x || !y) return x + y;
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
void split(int now, ll k, int &x, int &y)
{
	if(!now) {x = y = 0; return;}
	if(val[now] <= k) split(ch[now][1], k, ch[x = now][1], y);
	else split(ch[now][0], k, x, ch[y = now][0]);
	pushup(now);
}
inline void ins(int C, ll V)
{
	split(rt, V, x, y);
	tot++, t[tot] = (ll)(V % mo + mo) * C % mo; val[tot] = V, tcnt[tot] = cnt[tot] = C, rnd[tot] = (ll)rand() * rand() % (int)1e9;
	rt = merge(merge(x, tot), y);
}
inline ll query(ll k)
{
	split(rt, k, x, y);
	ll res = t[y] - (ll)k % mo * tcnt[y] % mo + (ll)k % mo * tcnt[x] % mo - t[x];
	rt = merge(x, y); return (res % mo + mo) % mo;
}
int main()
{
	srand(time(NULL));
	n = read(), q = read();
	ru(i, 1, n) a[i] = read();
	ru(i, 1, n) b[i] = read();
	ru(i, 1, q) {int l = read(), r = read(); que[r].push_back(mp(l - 1, i)); que[l].push_back(mp(l - 1, i));} 
	sum[0] = 0;
	ru(i, 1, n)
	{
		ins(a[i] - a[i - 1], sum[i - 1]);
		sum[i] = sum[i - 1] + b[i];
		for (auto x: que[i])
		{
			if(x.fi == i - 1) ans[x.se] -= query(sum[x.fi]);
			else ans[x.se] += query(sum[x.fi]);
		}
	}
	ru(i, 1, q) printf("%lld\n", (ans[i] % mo + mo) % mo);
	return 0;
}