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
#define maxn 200005
using namespace std;
inline int read() {
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, k, tp[maxn];
vector<int> G[maxn];
void dfs(int x) {
	for (auto V: G[x]) {
		tp[V] = tp[x] ^ 1, dfs(V);
		if(!tp[V]) k++;
	}
}
void solve() {
	k = 0, n = read();
	ru(i, 0, n + 1) G[i].clear();
	ru(i, 1, n) G[read()].push_back(i);
	tp[0] = 0, tp[n + 1] = 1, dfs(0), dfs(n + 1);
	int now = 0;printf("%d\n", k);
	while(!G[now].empty()) {
		for (auto x: G[now]) {
			if(G[x].empty()) printf("%d ", x);
		}
		int fl = 0;
		for (auto x: G[now]) if(!G[x].empty()) {
			printf("%d ", x);
			now = x;
			fl = 1;
			break;
		}
		if(!fl) break;
	}
	now = n + 1;
	while(!G[now].empty()) {
		for (auto x: G[now]) {
			if(G[x].empty()) printf("%d ", x);
		}
		int fl = 0;
		for (auto x: G[now]) if(!G[x].empty()) {
			printf("%d ", x);
			now = x;
			fl = 1;
			break;
		}
		if(!fl) break;
	}
	printf("\n");
}
int main() {
	int T = read();
	while(T--) solve();
	return 0;
}