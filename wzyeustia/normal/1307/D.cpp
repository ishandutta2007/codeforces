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
ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, m, k; cin >> n >> m >> k;
        vl able(k); REP(i, k) cin >> able[i];
        
        vvl G(n+2);
        REP(i, m) {
            ll u, v; cin >> u >> v;
            G[u].eb(v), G[v].eb(u);
        }

        vl dis1(n+2), dis2(n+2);
        vl vis1(n+2), vis2(n+2);

        queue<ll> que; que.em(1); vis1[1] = 1;
        while (!que.empty()) {
            ll u = que.front(); que.pop();
            for (auto v : G[u]) {
                if (vis1[v]) continue;
                vis1[v] = 1;
                dis1[v] = dis1[u] + 1;
                que.em(v);
            }
        }

        que.em(n); vis2[n] = 1;
        while (!que.empty()) {
            ll u = que.front(); que.pop();
            for (auto v : G[u]) {
                if (vis2[v]) continue;
                vis2[v] = 1;
                dis2[v] = dis2[u] + 1;
                que.em(v);
            }
        }

        dbg(dis1); dbg(dis2);

        ll ans = 0;
        // bool can = false;

        vl to(n+2, -1);
        vector<pll> seq;
        for (auto u : able) {
            if (to[dis1[u]] != -1) ans = dis1[n];
            else {
                to[dis1[u]] = dis2[u];
                seq.eb(dis1[u], dis2[u]);
            }
        } sort(all(seq));
        dbg(to); dbg(ans);

        ll last = -1;
        FOR(i, 0, n) {
            if (to[i] != -1) {
                if (last != -1) {
                    chkmax(ans, min(last+to[i], i+to[last]) + 1);
                } last = i;
            }
        } chkmin(ans, dis1[n]);

        dbg(ans);
        cout << ans << endl;
    }
    return 0;
}