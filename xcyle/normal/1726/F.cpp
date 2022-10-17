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
#define ru(i, l, r) for (int i = (l); i <= (r); i++)
#define rd(i, r, l) for (int i = (r); i >= (l); i--)
#define mid ((l + r) >> 1)
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define maxn 200005
using namespace std;
const ll INF = 1e16;
inline int read() {
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, t, l[maxn], r[maxn], c[maxn], d[maxn];
ll tag[maxn * 50]; int tot = 1;
int ch[maxn * 50][2];
void pushdown(int x) {
	if(!ch[x][0]) ch[x][0] = ++tot;
	if(!ch[x][1]) ch[x][1] = ++tot;
	if(tag[x]) {
		tag[ch[x][0]] = tag[x], tag[ch[x][1]] = tag[x];
		tag[x] = 0;
	}
}
inline void add(int x, int l, int r, int a, int b, ll c) {
	if(a <= l && r <= b) {
		tag[x] = c;
		return;
	}
	pushdown(x);
	if(a <= mid) add(ch[x][0], l, mid, a, b, c);
	if(b > mid) add(ch[x][1], mid + 1, r, a, b, c);
}
inline ll que(int x, int l, int r, int pos) {
	if(l == r) {
		if(!tag[x]) return 0;
		return tag[x] - pos;
	}
	pushdown(x);
	if(pos <= mid) return que(ch[x][0], l, mid, pos);
	else return que(ch[x][1], mid + 1, r, pos);
}
ll dfs(int x, int l, int r) {
	if(!x) return 0;
	if(tag[x]) return tag[x] - r; 
	return min(dfs(ch[x][0], l, mid), dfs(ch[x][1], mid + 1, r));
}
int main() {
	n = read(), t = read();
	ru(i, 1, n) l[i] = read(), r[i] = t - 1, c[i] = read();
	ll sum = 0;
	ru(i, 2, n) d[i] = read(), sum += d[i];
	ru(i, 1, n) {
		d[i] = (d[i] + d[i - 1]) % t;
		c[i] = (c[i] + d[i]) % t;
		l[i] = (l[i] + t - c[i]) % t;
		r[i] = (r[i] + t - c[i]) % t;
	}
	rd(i, n, 1) {
		ll res = que(1, 0, t - 1, (r[i] + 1) % t) + r[i] + 1;
		if(l[i] <= r[i]) add(1, 0, t - 1, l[i], r[i], res);
		else {
			add(1, 0, t - 1, 0, r[i], res);
			add(1, 0, t - 1, l[i], t - 1, res + t);
		}
	}
	ll ans = dfs(1, 0, t - 1);
	printf("%lld\n", ans + sum);
	return 0;
}