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
#define maxn 2000005
using namespace std;
inline int read() {
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
vector<int> G[maxn];
int n, m, vis[maxn];
vector<pii> t;
map<pii, int> id;
int ans[maxn];
int F[maxn], dep[maxn];
void dfs(int x, int fa) {
	vis[x] = 1, F[x] = fa, dep[x] = dep[fa] + 1;
	for (auto V: G[x]) {
		if(!vis[V]) dfs(V, x);
		else if(dep[V] > dep[x]) {
			ans[id[mp(x, V)]] = 1;
			int y = x, z = V;
			if(y > z) swap(y, z);
			t.push_back(mp(y, z));
//			printf("!!!%d %d\n", y, z);
		}
	}
}
void solve() {
	n = read(), m = read(); t.clear();
	ru(i, 1, n) G[i].clear(), vis[i] = 0; id.clear();
	ru(i, 1, m) {
		ans[i] = 0;
		int x = read(), y = read();
		G[x].push_back(y), G[y].push_back(x);
		id[mp(x, y)] = id[mp(y, x)] = i;
	}
	dfs(1, 0);
	if(t.size() == 3) {
		sort(t.begin(), t.end());
//		for (auto x: t) printf("%d %d\n", x.fi, x.se);
		if(t[0].first == t[1].first && t[0].second == t[2].first && t[1].second == t[2].second) {
			int y = t[2].first, z = t[2].second;
			if(dep[y] > dep[z]) swap(y, z);
			ans[id[mp(y, z)]] = 0;
			ans[id[mp(z, F[z])]] = 1;
		}
	}
	ru(i, 1, m) printf("%d", ans[i]); printf("\n");
}
int main() {
	int T = read();
	while(T--) solve(); 
	return 0;
}