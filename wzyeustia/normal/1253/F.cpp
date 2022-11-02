#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
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

mt19937_64 rng((unsigned ll) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<ll>(a, b)(rng)

vl F;
ll find(ll k) {
    return F[k] == k? k : F[k] = find(F[k]);
}

vl val;
vvl G;

// this template contains edges...
// to initialize, call lca_dfs(1, 0)
const ll POW = 20, LCA_SIZE = 2e5+3;
ll depth[LCA_SIZE], p[LCA_SIZE][POW];

void lca_dfs(ll node, ll par) {
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


int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, m, k, q; cin >> n >> m >> k >> q;
        vector<pll> G0[n+2];
        vector<t3l> edges;
        REP(i, m) {
            ll u, v, w; cin >> u >> v >> w;
            edges.eb(u, v, w);
            G0[u].eb(v, w), G0[v].eb(u, w);
        }
        
        vl dist(n+2, 1e17), from(n+2, -1);
        MinHeap<pll> heap1; FOR(i, 1, k) dist[i] = 0, from[i] = i, heap1.em(0, i);

        while (!heap1.empty()) {
            auto [d, u] = heap1.top(); heap1.pop();
            if (d != dist[u]) continue;

            for (auto [v, w] : G0[u]) if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w, from[v] = from[u]; heap1.em(dist[v], v);
            }
        }

        dbg(dist); dbg(from);
        
        vector<t3l> seq;
        for (auto [u, v, w] : edges) if (from[u] != from[v]) {
            ll cap = dist[u]+dist[v]+w;
            dbg(u, v, w, cap);
            seq.eb(dist[u]+dist[v]+w, from[u], from[v]);
        } sort(all(seq));

        F = vl(2*n+2); FOR(i, 1, 2*n+1) F[i] = i;
        G = vvl(2*n+2); val = vl(2*n+2);
        ll node = k;
        for (auto [cap, u, v] : seq) {
            ll x = find(u), y = find(v);
            if (x == y) continue;

            val[++node] = cap;
            G[node].eb(x), G[node].eb(y);
            G[x].eb(node), G[y].eb(node);

            F[x] = F[y] = node;
        }
        dbg(node);

        depth[0] = -1;
        lca_dfs(node, 0);


        REP(i, q) {
            ll u, v; cin >> u >> v;
            ll anc = lca(from[u], from[v]);
            cout << val[anc] << endl;
        }
    }
    return 0;
}