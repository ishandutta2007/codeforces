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

vl dec(ll n) {
    vl ret;
    ll base = 1e5;
    while (base > n) base /= 10;

    while (base > 0) {
        ret.eb(n / base);
        n %= base;
        base /= 10;
    }
    return ret;
}

struct Node {
    ll bit = -1, val = 0;
    ll from = 0;
    vl cand;
    ll nxt[10] = {0};
};

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;   
    REP(I, T) {
        ll n, m; cin >> n >> m;
        vector<pll> G[n+2];
        FOR(i, 1, m) {
            ll u, v; cin >> u >> v;
            G[u].eb(v, i), G[v].eb(u, i);
        }

        const ll SZ = 6*m+7;
        Node node[SZ];
        ll tot = 1;

        vl at(n+2, 0);
        bool vis[SZ]; FILL(vis, false);
        vis[0] = vis[1] = 1; 
        queue<ll> que; que.em(1); node[1].cand.eb(1);
        while (!que.empty()) {
            auto u = que.front(); que.pop();
            dbg(u);

            for (auto x : node[u].cand) if (!at[x]) {
                at[x] = u;
                dbg(x);

                for (auto [y, w] : G[x]) if (!at[y]) {
                    vl num = dec(w);
                    ll crt = u;
                    for (auto a : num) {
                        if (!node[crt].nxt[a]) {
                            node[crt].nxt[a] = ++tot;
                            node[tot].from = crt;
                            node[tot].bit = a;
                            node[tot].val = (node[crt].val*10 + a)%MOD;
                            // dbg(tot, node[tot].val);
                        }
                        crt = node[crt].nxt[a];
                    }
                    node[crt].cand.eb(y);
                }
            }
            

            REP(bit, 10) {
                ll v = node[u].nxt[bit];
                // dbg(bit, v);
                if (!vis[v]) que.em(v), vis[v] = 1;
            }

            // for (auto [v, w] : G[u]) {
            //     vl num = dec(w);

            //     ll crt = at[u];
            //     for (auto a : num) {
            //         if (!node[crt].nxt[a]) {
            //             node[crt].nxt[a] = 
            //         }
            //     }
            // }
        }

        dbg("done");

        FOR(i, 2, n) {
            ll ans = node[at[i]].val;
            cout << ans << endl;
        }

    }
    return 0;
}