#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define FOR(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (ll (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define pb push_back
#define eb emplace_back
#define em emplace
#define mp make_pair
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

#define FILL0(arr) memset(arr, 0, sizeof(arr))

#define ln cout << endl;

// Can I use this?
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
const ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}

// this template contains edges...
// to initialize, call lca_dfs(1, 0)
const ll POW = 20, LCA_SIZE = 2e5+3;
vl edges[LCA_SIZE];
ll depth[LCA_SIZE], p[LCA_SIZE][POW];

void lca_dfs(ll node, ll par) {
    if (par <= 0) depth[par] = 0;
	depth[node] = depth[par] + 1;
	p[node][0] = par;

	FOR(i, 1, POW-1)
		p[node][i] = p[ p[node][i-1] ][i-1];
    
	for (auto child : edges[node]) {
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

ll dist(ll a, ll b) {
    return depth[a]+depth[b] - 2*depth[lca(a, b)];
}

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
            edges[u].eb(v), edges[v].eb(u);
        }

        lca_dfs(1, 0);
        ll q; cin >> q;
        REP(i, q) {
            ll x, y, a, b, k; cin >> x >> y >> a >> b >> k;
            bool can = false;

            ll path0 = dist(a, b);
            ll ax = dist(a, x), ay = dist(a, y), bx = dist(b, x), by = dist(b, y);
            ll path1 = ax + by + 1, path2 = ay + bx + 1;
            
            if (path0 <= k && (path0-k)%2 == 0) can = true;
            if (path1 <= k && (path1-k)%2 == 0) can = true;
            if (path2 <= k && (path2-k)%2 == 0) can = true;
            
            if (can) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}