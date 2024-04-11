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
#define pb push_back
#define eb emplace_back
#define em emplace
#define mp make_pair
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

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
#endif
// end

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;

const ld PI = 3.14159265358979323846;
const ld E = 2.718281828459;
const ll SIZE = 2e6+3; 

const ll MOD = 1e9+7;
ll myMod(ll n) {return (n % MOD + MOD) % MOD;}

ll mul(ll a, ll b) {return ( (a%MOD)*(b%MOD) )%MOD;}
ll plu(ll a, ll b) {return (a%MOD + b%MOD)%MOD;}

ll ans;

void calc(ll start, ll len, ll w, ll o) {
    dbg(start, len, w, o);
    ll base = o + (start-2000) * w; base %= MOD;
    base = mul(len, base);
    ll addition = mul(len*(len+1)/2, w);
    dbg(base, addition);
    
    ans = plu(ans, plu(base, addition));
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, m, q; cin >> n >> m >> q;
        vector<tuple<ll, ll, ll>> edges;
        REP(i, m) {
            ll u, v, w; cin >> u >> v >> w;
            edges.eb(u, v, w);
        }

        vvl dp(2002, vl(n+2, -9e9));
        dp[0][1] = 0;
        FOR(i, 1, 2000) {
            for (auto& [u, v, w] : edges) {
                chkmax(dp[i][u], dp[i-1][v] + w);
                chkmax(dp[i][v], dp[i-1][u] + w);
            }
        }

        ans = 0;
        FOR(i, 1, min(q, 2000ll)) {
            ll mx = 0;
            FOR(node, 1, n) chkmax(mx, dp[i][node]);
            ans = plu(ans, mx);
        }

        vector<pll> cycle;
        for (auto& [u, v, w] : edges) {
            ll offset = max(dp[2000][u], dp[2000][v]);
            cycle.eb(w, offset);
        }
        sort(all(cycle));

        ll idx = 0, last = 2000;
        while (idx < m-1 && last < q) {
            auto [w1, o1] = cycle[idx];
            dbg(idx, w1, o1);
            ll pos = -1, minTime = 2e9;

            FOR(nxt, idx+1, m-1) {
                auto [w2, o2] = cycle[nxt];
                dbg(nxt, w2, o2);
                if (w1 == w2 || o1 <= o2) {
                    pos = nxt; minTime = last; break;
                }
                
                ll delta = (o1-o2)/(w2-w1);
                ll time = delta + 2000;

                if (time <= minTime) {
                    pos = nxt;
                    minTime = time;
                }

                if (minTime <= last) break;
            }

            if (minTime > last) {
                chkmin(minTime, q);
                calc(last, minTime - last, w1, o1);

                last = minTime;
            }
            idx = pos;
        }

        if (idx == m-1 && last < q) {
            auto [w, o] = cycle[idx];
            calc(last, q-last, w, o);
        }

        dbg(ans);
        cout << ans << endl;
    }
    return 0;
}