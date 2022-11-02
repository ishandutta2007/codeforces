#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
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

// FILL by byte!!!
#define FILL(arr, num) memset(arr, num, sizeof(arr))

#define ln printf("\n");

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
const ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

set<ll> se; 
vector<map<ll, ll>> edges;
ll rem;

struct dsu {
    vi F;
    ll sz;
    void init(ll n) {
        sz = n;
        F = vi(sz+2);
        FOR(i, 1, sz) F[i] = i;
    }
 
    int trace(int k) {
        return F[k] == k? k : F[k] = trace(F[k]);
    }
    
    bool connect(int u, int v) {
        // dbg(trace(u), trace(v));
        if (trace(u) == trace(v)) {
            return false;
        }
        // dbg(u, v);
        F[trace(u)] = trace(v);
        return true;
    }

    void show() {
        dbg(F);
    }
} dsu1, dsu2;

void dfs(ll u) {
    se.erase(u);
    auto iter = se.lower_bound(1);
    while (iter != se.end()) {
        ll v = (*iter);
        if (!edges[u][v]) {
            dsu1.connect(u, v); rem--; 
            dfs(v); 
        }
        iter = se.lower_bound(++v);
    }
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        // after reading tutorial's implementation...
        // how to do dfs on a quite large unweighted graph:
        // (M is #blocked_edges)
        // use a vector/set to save unvisited nodes
        // when doing dfs, use lower_bound to find next unvisited nodes in O(logN)
        // we will do N times dfs, fail at most M times
        // therefore time complexity bounded by O(N*logN + M*logN)
        ll n, m; cin >> n >> m;
        rem = n*(n-1)/2 - m;
        
        edges = vector<map<ll, ll>>(n+2);
        vector<tuple<ll, ll, ll>> seq;
        ll tot = 0;
        REP(i, m) {
            ll u, v, w; cin >> u >> v >> w;
            edges[u][v] = edges[v][u] = w;
            seq.eb(w, u, v);
            tot ^= w;
        }

        dsu1.init(n), dsu2.init(n);
        FOR(i, 1, n) se.em(i);
        FOR(i, 1, n) if (se.count(i)) dfs(i);
        
        dsu1.show();

        ll offset = tot, ans = 0;
        if (rem > 0) offset = 0;

        sort(all(seq));
        for (auto [w, u, v] : seq) {
            if (dsu1.connect(u, v)) {
                ans += w;
                dsu2.connect(u, v);
            } else if (dsu2.connect(u, v)) {
                chkmin(offset, w);
            }
        }

        dbg(ans + offset);
        cout << ans+offset << endl;
    }
    return 0;
}