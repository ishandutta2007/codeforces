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
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define maxn 1000005
using namespace std;
inline int read() {
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, k;
vector<int> G[maxn];
ll s[maxn], mx[maxn];
ll ans;
priority_queue<ll> q;
void work(int x, int k) {
	if(G[x].size() == 0) {
		ans += s[x] * k;
//		printf("%lld %d %d\n", x, s[x], k);
		mx[x] = s[x];
		return;
	}
	for (auto V: G[x]) {
		s[V] += s[x];
		work(V, k / G[x].size());
	}
	k %= G[x].size();
	while(!q.empty()) q.pop();
	for (auto V: G[x]) {
		q.push(mx[V]);
	}
	ll tmp = q.top();
	while(k--) {
		ans += q.top(); q.pop();
	}
	if(q.empty()) mx[x] = tmp;
	else mx[x] = q.top();
}
void solve() {
	ans = 0;
	n = read(), k = read();
	ru(i, 1, n) G[i].clear();
	ru(i, 2, n) G[read()].push_back(i);
	ru(i, 1, n) s[i] = read();
	work(1, k);
	printf("%lld\n", ans);
}
int main() {
	int T = read();
	while(T--) solve();
	return 0;
}