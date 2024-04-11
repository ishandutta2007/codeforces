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

map<ll, ll> idx;
vector<vector<pll>> G;
vl link, dist, dfn, pa, stat, cycle;
vvl comb;

ll mask, cnt = 0;
void dfs(ll u, ll par) {
    dfn[u] = ++cnt;
    for (auto [v, w] : G[u]) {
        if (v == par) continue;
        if (dfn[v] && dfn[u] > dfn[v] && mask != -1) {
            ll cycle = dist[u]^dist[v]^w; 
            // TODO: how to not recalculate cycle?
            // solution: we only need back edge & not the edge to par.
            // dbg(dist[u], dist[v]);
            // dbg(u, v, cycle);

            if (cycle == 0) mask = -1;
            else mask = comb[mask][idx[1 << cycle]];
        }
        if (!dfn[v]) {
            dist[v] = dist[u]^w;
            dfs(v, u);
        } 
    }
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        vl sub; sub.eb(0), idx[0] = 0;
        REP(i, sub.size()) {
            ll m0 = sub[i];
            FOR(j, 1, 31) if (!(m0 >> j & 1)) {
                ll m1 = m0;
                REP(p, 32) if (m0 >> p & 1) {
                    m1 |= 1 << (p^j);
                } m1 |= 1 << j;
                
                if (!idx.count(m1)) {
                    idx[m1] = sub.size();
                    sub.eb(m1);
                }
            }
        }

        ll sz = sub.size();
        comb = vvl(sz, vl(sz, -1));
        REP(i, sz) REP(j, sz) {
            ll m1 = sub[i], m2 = sub[j];
            if (sub[i] & sub[j]) continue;

            ll x = m1|m2;
            REP(p1, 32) REP(p2, 32) if (m1>>p1 & 1 && m2>>p2 & 1) {
                x |= 1<<(p1^p2);
            } comb[i][j] = idx[x];
        }

        ll n, m; cin >> n >> m;
        G = vector<vector<pll>>(n+2);
        link = vl(n+2, 0), dist = vl(n+2, 0), pa = vl(n+2, 0), cycle = vl(n+2, 0);
        vector<t3l> allEdge;
        REP(tt, m) {
            ll u, v, w; cin >> u >> v >> w;
            if (u>v) swap(u, v);
            allEdge.eb(u, v, w);
        } sort(all(allEdge));

        for (auto [u, v, w] : allEdge) {
            if (u == 1) link[v] = 1, dist[v] = w;
            else if (link[u] && link[v]) {
                pa[u] = v, pa[v] = u;
                cycle[u] = cycle[v] = dist[u]^dist[v]^w;
            } else G[u].eb(v, w), G[v].eb(u, w);
        }

        vector<t3l> seq;
        dfn = vl(n+2, 0); dfn[1] = 0;
        stat = vl(n+2, 0);
        FOR(i, 2, n) if (!dfn[i]) {
            mask = 0, dfs(i, 0);
            stat[i] = mask;
        }

        dbg(dfn); dbg(cycle);

        ll t = 0;
        vvl dp(2, vl(sz, 0)); dp[0][0] = 1;
        FOR(i, 2, n) if (link[i] && pa[i] < i) {

            t ^= 1, dp[t] = dp[t^1];
            mask = stat[i];
            if (pa[i] == 0 && mask != -1) {
                REP(m1, sz) if (comb[m1][mask] != -1)
                    dp[t][comb[m1][mask]] = (dp[t][comb[m1][mask]] + dp[t^1][m1])%MOD;
            } else { 
                ll mask2 = stat[pa[i]];
                
                ll k1 = -1, k2 = -1;
                if (mask != -1 && mask2 != -1) k1 = comb[mask][mask2];
                if (k1 != -1 && cycle[i] != 0) k2 = comb[k1][idx[1<<cycle[i]]];


                mask = k1, mask2 = k2;
                if (mask2 != -1) {
                    REP(m1, sz) if (comb[m1][mask2] != -1)
                        dp[t][comb[m1][mask2]] = (dp[t][comb[m1][mask2]] + dp[t^1][m1])%MOD;
                }
                if (mask != -1) {
                    REP(m1, sz) if (comb[m1][mask] != -1)
                        dp[t][comb[m1][mask]] = (dp[t][comb[m1][mask]] + 2*dp[t^1][m1])%MOD;
                }
            }
        }

        ll ans = accumulate(all(dp[t]), 0ll);
        dbg(ans);
        cout << ans%MOD << endl;
    }
    return 0;
}