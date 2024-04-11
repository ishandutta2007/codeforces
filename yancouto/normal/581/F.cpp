#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
int distr(int, int, int, bool);
vector<pii> adj[5009];
int memo[5002][2502][2];
int solve(int u, int l, bool bf) {
	if(adj[u].empty()) {
		if(l > 1) return 1000000;
		if(l == 1) return !bf;
		else return bf;
	}
	int &r = memo[u][l][bf];
	if(r != -1) return r;
	r = min(distr(u, adj[u].size(), l, true) + !bf, distr(u, adj[u].size(), l, false) + bf);
	return r;
}

int memo2[5002][2502][2];
int distr(int u, int m, int l, bool b) {
	int &r = memo2[adj[u][m-1].fst][l][b];
	if(r != -1) return r;
	if(m == 1) return r = solve(adj[u][0].fst, l, b);
	r = 1000000;
	for(int i = max(l - adj[u][m-2].snd, 0); i <= l && i <= adj[u][m-1].snd - adj[u][m-2].snd; i++)
		r = min(r, solve(adj[u][m-1].fst, i, b) + distr(u, m - 1, l - i, b));
	return r;
}

int dfs(int u, int p) {
	if(p != -1) {
		int i;
		for(i = 0; adj[u][i].fst != p; i++);
		swap(adj[u][i], adj[u].back());
		adj[u].pop_back();
	}
	if(adj[u].empty()) return 1;
	for(pii &e : adj[u])
		e.snd += dfs(e.fst, u);
	for(int i = 1; i < adj[u].size(); i++)
		adj[u][i].snd += adj[u][i-1].snd;
	return adj[u].back().snd;
}

int main() {
	int i, n, a,b;
	scanf("%d", &n);
	int l = 0;
	for(i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b);
		adj[--a].pb(pii(--b, 0));
		adj[b].pb(pii(a, 0));
	}
	for(i = 0; i < n; i++)
		l += adj[i].size() == 1;
	if(n == 2) { puts("1"); return 0; }
	memset(memo, -1, sizeof memo);
	memset(memo2, -1, sizeof memo2);
	for(i = 0; adj[i].size() == 1; i++);
	dfs(i, -1);
	printf("%d\n", min(distr(i, adj[i].size(), l / 2, true), distr(i, adj[i].size(), l / 2, false)));
}