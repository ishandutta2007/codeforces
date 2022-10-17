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
#define maxn 400005
using namespace std;
inline int read() {
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, fl;
struct mat {
	vector<int> v[maxn];
	vector<pii> G[maxn];
	int col[maxn], siz[maxn], match[maxn];
	void dfs(int x, int c) {
		col[x] = c;
		if(x <= n) siz[c]++;
		for (auto V: G[x]) if(!col[V.se]) dfs(V.se, c);
	}
	void init() {
		ru(i, 1, n) ru(j, 1, m) if(v[i][j]) {
			G[i].push_back(mp(v[i][j], n + j)), G[n + j].push_back(mp(v[i][j], i));
		}
		ru(i, 1, n + m) sort(G[i].begin(), G[i].end());
		ru(i, 1, n + m) if(!col[i]) dfs(i, i);
	}
	void clear(int x) {
		match[x] = 0;
		for (auto V: G[x]) if(match[V.se]) clear(V.se);
	}
}a, b;
int check(int x, int y) {
	if(a.match[x]) return a.match[x] == y && b.match[y] == x;
	if(a.G[x].size() != b.G[y].size()) return 0;
	a.match[x] = y, b.match[y] = x;
	ru(i, 0, (int)a.G[x].size() - 1) {
		if(a.G[x][i].fi == b.G[y][i].fi) {
			if(!check(a.G[x][i].se, b.G[y][i].se)) return 0;
		}
		else return 0;
	}
//	printf("!! %d %d %d %d\n", x, y, a.G[x][0].fi, a.G[x][0].se);
	return 1;
}
struct node {int a, b, c;};
vector<node> ans;
int main() {
	n = read(), m = read();
	ru(i, 1, max(n, m)) a.v[i].resize(min(n, m) + 1), b.v[i].resize(min(n, m) + 1);
	ru(i, 1, min(n, m)) a.v[i].resize(max(n, m) + 1), b.v[i].resize(max(n, m) + 1);
	ru(i, 1, n) ru(j, 1, m) a.v[i][j] = read();
	ru(i, 1, n) ru(j, 1, m) b.v[i][j] = read();
	if(n > m) {
		fl = 1;
		ru(i, 1, n) ru(j, 1, m) if(i > j) {
			swap(a.v[i][j], a.v[j][i]);
			swap(b.v[i][j], b.v[j][i]);
		}
		swap(n, m);
	}
	a.init(), b.init();
	int now = n + 1;
	ru(i, 1, n + m) if(a.col[i] == i) {
		if(i > n) {
			while(now <= n + m) { 
				if(b.col[now] == now && !b.siz[now]) {
					a.match[i] = now, b.match[now] = i, now++;
					break;
				}
				now++;
			}
		}
		else {
			ru(j, 1, n) if(!b.match[j] && a.siz[i] == b.siz[b.col[j]]) {
				if(check(i, j)) break;
				a.clear(i), b.clear(j);
			}
		}
		if(!a.match[i]) {
			printf("-1\n");
			return 0;
		}
	}
//	printf("row: "); ru(i, 1, n) printf("%d ", a.match[i]); printf("\n");
//	printf("col: "); ru(i, 1, m) printf("%d ", a.match[i + n] - n); printf("\n");
	ru(i, 1, n + m) if(a.match[i] != i) {
		int tmp = b.match[i];
		if(i <= n) ans.push_back({1 + fl, tmp, i});
		else ans.push_back({2 - fl, tmp - n, i - n});
		swap(a.match[i], a.match[tmp]), swap(b.match[a.match[i]], b.match[a.match[tmp]]);
	}
	printf("%d\n", ans.size());
	for (auto x: ans) printf("%d %d %d\n", x.a, x.b, x.c);
	return 0;
}