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
ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

const ll MX = 3e5+2, POW = 20;

int lowbit(int num) {return num & (-num);}

ll query(int k, vl &BIT) {
    ll sum = 0;
    for (int i = k; i > 0; i-=lowbit(i)) {
        sum += BIT[i];
    }
    return sum;
}

void update(int l, int r, ll delta, vl &BIT) {
    for (int i = l; i < BIT.size(); i+=lowbit(i)) {
        BIT[i] += delta;
    }
    for (int i = r+1; i < BIT.size(); i+=lowbit(i)) {
        BIT[i] -= delta;
    }
}

vl F;
ll find(ll k) {
    return F[k] == k? k : F[k] = find(F[k]);
}

vector<pll> G[MX];
ll lo[MX], hi[MX], val[MX], fa[MX];
int depth[MX], p[MX][POW];
ll idx = 0;

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

vl vis;
void dfs(ll u, ll par) {
    // dbg(u, par);
    vis[u] = 1, fa[u] = par;

    if (par <= 0) depth[par] = val[par] = 0;
	depth[u] = depth[par] + 1;
	p[u][0] = par;
    FOR(i, 1, POW-1) p[u][i] = p[ p[u][i-1] ][i-1];

    lo[u] = ++idx;
    for (auto [v, w] : G[u]) if (v != par) {
        // dbg(u, v);
        val[v] = val[u] ^ w;
        dfs(v, u);
    }
    hi[u] = idx;
}

// meaningful problem of cycles on graph.
// main thought: generating a dfs tree in advance.
// then every other edge can represent a cycle by triple<u, v, lca(u, v)>
// using this representation make things easier.
int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, q; cin >> n >> q;
        F = vl(n+2); REP(i, n+2) F[i] = i;

        vl inTree(q, 0);
        vector<t3l> E(q);
        REP(i, q) {
            ll u, v, w; cin >> u >> v >> w;
            E[i] = {u, v, w};
            
            ll fu = find(u), fv = find(v);
            if (fu != fv) {
                inTree[i] = 1, F[fv] = fu;
                G[u].eb(v, w), G[v].eb(u, w);
            }
        }

        vis = vl(n+2, 0); FILL(val, 0);
        FOR(i, 1, n) if (!vis[i]) dfs(i, 0);

        vl BIT(n+2, 0), ans(q, 0);
        REP(tt, q) {
            auto [u, v, w] = E[tt];
            if (inTree[tt]) {
                ans[tt] = 1; continue;
            }
            
            ll cycle = val[u] ^ val[v] ^ w;
            // dbg(cycle);
            if (cycle == 0) continue;

            ll anc = lca(u, v);
            ll k1 = query(lo[u], BIT), k2 = query(lo[v], BIT), k0 = query(lo[anc], BIT);
            if (k1 > k0 || k2 > k0)
                continue;
        
            ans[tt] = 1;
            while (u != anc) update(lo[u], hi[u], 1, BIT), u = fa[u];
            while (v != anc) update(lo[v], hi[v], 1, BIT), v = fa[v];            
        }

        dbg(ans);
        REP(i, q) if (ans[i]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}