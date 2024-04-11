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

vvl G;
vl ban;
ll crt, sz, n;
pll pa;

void find() {
    ll last = -1, far = -1;
    vl vis(n+2, 0);
    queue<ll> q; q.em(crt), vis[crt] = 1;
    while (!q.empty()) {
        ll u = q.front(); q.pop();
        last = u;
        dbg(last);

        for (auto v : G[u]) if (!ban[v] && !vis[v])
            vis[v] = 1, q.em(v);
    }
    dbg(last);

    FOR(i, 1, n) vis[i] = 0;
    q.em(last), vis[last] = 1;
    while (!q.empty()) {
        ll u = q.front(); q.pop();
        far = u;
        dbg(far);

        for (auto v : G[u]) if (!ban[v] && !vis[v])
            vis[v] = 1, q.em(v);
    }

    pa = {last, far};
}

ll query() {
    cout << "? " << pa._1 << " " << pa._2 << endl;
    cout.flush();
    ll ret; cin >> ret;
    return ret;
}

void dfs(ll u) {
    if (u == crt) return;
    if (!ban[u]) ban[u] = 1, sz--;
    for (auto v : G[u]) if (!ban[v]) {
        dfs(v);
    }
}

// bool dfs(ll u, ll par, bool stat) {
//     if (u != crt && (u == pa._1 || u == pa._2)) stat = true;

//     for (auto v : G[u]) if (!ban[v] && v != par) {
//         if (dfs(v, u, stat) && u!=crt) stat = true;
//     }
//     dbg(u, stat);

//     if (stat && !ban[u]) ban[u] = 1, sz--;
//     return stat;
// }

void answer() {
    cout << "! " << crt << endl;
    cout.flush();
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        cin >> n;
        G = vvl(n+2); REP(i, n-1) {
            ll u, v; cin >> u >> v;
            G[u].eb(v), G[v].eb(u);
        }

        ban = vl(n+2, 0);
        crt = 1, sz = n;
        while (sz > 1) {
            find();
            crt = query();
            dbg(pa._1, pa._2);

            // dfs(crt, -1, 0);
            dfs(pa._1), dfs(pa._2);
            dbg(ban); dbg(crt, sz);
        }

        answer();
    }
    return 0;
}