#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ld, ld, ld> t3l;
typedef tuple<ll, ll, ll, ll> t4l;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

#define FOR(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (ll (i) = (a); (i) >= (b); (i)--)
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
#define lb_pos(arr, key) lower_bound(all(arr), key) - (arr).begin()
#define ub_pos(arr, key) upper_bound(all(arr), key) - (arr).begin()

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

ll n, m;
ll p, k, a, b, c; 
vector<multiset<pll>> G;

ll target;
t3l victim;
bool dfs(ll u, ll par) {
    if (u == target) return true;
    for (auto [v, w] : G[u]) if (v != par) {
        bool found = dfs(v, u);
        if (found) {
            auto [u0, v0, w0] = victim;
            if (w < w0) victim = {u, v, w};
            return true;
        }
    }
    return false;
}

vector<t3l> seg;
ll getCost(ll x) {
    t3l tp = {x, 1e15, -1};
    ll idx = ub_pos(seg, tp) - 1;
    auto [p, d, c] = seg[idx];
    ll cost = c + (x - p) * d;
    return cost;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        cin >> n >> m;
        G = vector<multiset<pll>>(n+2);
        vector<t3l> E;
        REP(i, m) {
            ll u, v, w; cin >> u >> v >> w;
            E.eb(w, u, v);
        }
        sort(all(E));
        
        vl plan;
        vector<pld> mod;
        for (auto [w, u, v] : E) {
            target = v, victim = {-1, -1, 1e15};
            bool found = dfs(u, 0);

            G[u].em(v, w), G[v].em(u, w);
            mod.eb(w, 2);
            if (found) {
                auto [u0, v0, w0] = victim;
                ld pos = (w0 + w) / 2.0;
                G[u0].erase(G[u0].find(mp(v0, w0)));
                G[v0].erase(G[v0].find(mp(u0, w0)));
            
                mod.eb(pos, -2);
            } else {
                dbg(w, u, v);
                plan.eb(w);
            }
        }
        sort(all(mod));
        dbg(plan);

        vl ans(k, 0);
        ld delta = -n+1, crt = 0, last = 0;
        for (auto w : plan) crt += w;
        seg.eb(0, delta, crt);
        for (auto [pos, x] : mod) {
            crt += delta * (pos - last); last = pos;
            delta += x;
            seg.eb(pos, delta, crt);
            dbg(delta);
        }

        cin >> p >> k >> a >> b >> c;
        vl query(k); REP(i, p) cin >> query[i];
        FOR(i, p, k-1) query[i] = (query[i-1] * a + b)%c;

        ll outAns = 0;
        REP(i, k) outAns ^= getCost(query[i]);
        cout << outAns << endl;
    }   
    return 0;
}