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

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;

const ld PI = 3.14159265358979323846;
const ld E = 2.718281828459;
ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

vl G[3001];

// this template contains edges...
// to initialize, call lca_dfs(1, 0)
const ll POW = 12, LCA_SIZE = 3000+3;
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
    return depth[a]+depth[b] - (depth[lca(a, b)]<<1);
}

// ll sz[3001][3001];
// void sz_dfs(ll root, ll u, ll par) {
//     sz[root][u] = 1;
//     for (auto v : G[u]) if (v != par) {
//         sz_dfs(root, v, u);
//         sz[root][u] += sz[root][v];
//     }
// }
ll sz[3001];
void sz_dfs(ll u, ll par) {
    sz[u] = 1;
    for (auto v : G[u]) if (v != par) {
        sz_dfs(v, u);
        sz[u] += sz[v];
    }
}

ll dp[3001][3001] = {0};
bool vis[3001][3001] = {0};

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
		ll n; cin >> n;
        REP(i, n-1) {
            ll u, v; cin >> u >> v;
            G[u].eb(v), G[v].eb(u);
        }

        // FOR(root, 1, n) sz_dfs(root, root, 0);
        sz_dfs(1, 0);
        lca_dfs(1, 0);

        // FOR(i, 1, n) cout << sz[i] << " "; cout << endl;

        ll ans = 0;
        queue<pll> que;
        FOR(i, 1, n) vis[i][i] = true, que.em(i, i);
        while (!que.empty()) {
            auto [i, j] = que.front(); que.pop();
            if (i != j) {
                ll root = lca(i, j), earn = sz[i] * sz[j], d = tree_dist(i, j);
                if (i == root) for (auto v : G[i]) if (tree_dist(v, j) < d) {
                    earn = (n-sz[v]) * sz[j];
                }
                if (j == root) for (auto v : G[j]) if (tree_dist(i, v) < d) {
                    earn = (n-sz[v]) * sz[i];
                }
                dp[i][j] += earn; chkmax(ans, dp[i][j]);
            }

            for (auto v : G[i]) {
                chkmax(dp[v][j], dp[i][j]);
                if (!vis[v][j]) vis[v][j] = 1, que.em(v, j);
            }
            for (auto v : G[j]) {
                chkmax(dp[i][v], dp[i][j]);
                if (!vis[i][v]) vis[i][v] = 1, que.em(i, v);
            }
        } 
        cout << ans << endl;
    }
    return 0;
}