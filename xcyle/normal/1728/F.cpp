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
#define maxn 1005
using namespace std;
inline int read() {
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn], vis[maxn], match[maxn];
int dfs(int x) {
	ru(i, 1, n) if(x % a[i] == 0 && !vis[i]) {
		vis[i] = 1;
		if(!match[i] || dfs(match[i])) return match[i] = x, 1;
	}
	return 0;
}
set<int> t;
int main() {
	n = read(); 
	ru(i, 1, n) {
		a[i] = read();
		ru(j, 1, n) t.insert(a[i] * j);
	}
	ll ans = 0;
	for (auto i: t) if(dfs(i)) {
		ans += i;
		ru(j, 1, n) vis[j] = 0;
	}
	printf("%lld\n", ans);
	return 0;
}