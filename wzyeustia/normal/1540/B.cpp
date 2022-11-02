#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> t3l;
typedef tuple<ll, ll, ll, ll> t4l;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define ef emplace_front
#define em emplace
#define mp make_pair
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define _1 first
#define _2 second

// FILL by byte!!!
#define FILL(arr, num) memset(arr, num, sizeof(arr))
#define ln cout << endl;

#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m " << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#define err(...)
#endif
// end

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;

const ld PI = 3.14159265358979323846;
const ld E = 2.718281828459;
ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

vvl G;
// this template contains edges...
// to initialize, call lca_dfs(1, 0)
const ll POW = 10, LCA_SIZE = 203;
// vl edges[LCA_SIZE];
ll depth[LCA_SIZE], p[LCA_SIZE][POW];

void lca_dfs(ll node, ll par) {
    if (par <= 0) depth[par] = 0;
	depth[node] = depth[par] + 1;
	p[node][0] = par;

	FOR(i, 1, POW-1)
		p[node][i] = p[ p[node][i-1] ][i-1];
    
	for (auto child : G[node]) {
		if (child == par) continue;
		lca_dfs(child, node);
	}
}

ll lca(ll a, ll b) {
	if (depth[a] > depth[b]) swap(a, b);
	if (depth[a] < depth[b]) {   //a,b
		ll del = depth[b] - depth[a];
		REP(i, POW) if (del & (1 << i)) b = p[b][i];
	}

	if (a != b) {    //lca
		ROF(i, POW-1, 0) if (p[a][i] != p[b][i])
            a = p[a][i], b = p[b][i];
		a = p[a][0], b = p[b][0];
	}
	return a;
}

ll tree_dist(ll a, ll b) {
    return depth[a]+depth[b] - 2*depth[lca(a, b)];
}

ll dist[LCA_SIZE][LCA_SIZE] = {0};
void getDist(ll root) {
	vl vis(LCA_SIZE, 0);
	queue<ll> que; que.em(root); vis[root] = 1;
	while (!que.empty()) {
		ll u = que.front(); que.pop();
		for (auto v : G[u]) if (!vis[v]) {
			dist[root][v] = dist[root][u]+1;
			vis[v] = 1, que.em(v);
		}
	}
}

ll getInv(ll a, ll p) {
 return (a == 1 ? 1 : (1 - p * getInv(p % a, a)) / a + p);
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
		ll n; cin >> n;
		G = vvl(n+2);
		REP(i, n-1) {
			ll u, v; cin >> u >> v;
			G[u].eb(v), G[v].eb(u);
		}	

		lca_dfs(1, 0);
		FOR(i, 1, n) getDist(i);
		
		ll dp[n+2][n+2];
		const ll HALF = getInv(2, MOD);
		FOR(i, 1, n) dp[0][i] = 0, dp[i][0] = 1;
		FOR(i, 1, n) FOR(j, 1, n) {
			dp[i][j] = HALF * (dp[i-1][j]+dp[i][j-1]) %MOD;
		}

		ll ans = 0;
		FOR(i, 1, n) FOR(j, i+1, n) FOR(k, 1, n) {
			ll mx = 0;
			ll p1 = lca(i, j), p2 = lca(j, k), p3 = lca(i, k);
			if (depth[p1] > depth[mx]) mx = p1;
			if (depth[p2] > depth[mx]) mx = p2;
			if (depth[p3] > depth[mx]) mx = p3;

			ll d1 = dist[mx][i], d2 = dist[mx][j];
			// dbg(i, j, k);
			// dbg(mx, d1, d2);
			ans = (ans + dp[d1][d2])%MOD;
		}

		ans = ans * getInv(n, MOD) %MOD;
		dbg(ans);
		cout << ans << endl;
	}
    return 0;
}