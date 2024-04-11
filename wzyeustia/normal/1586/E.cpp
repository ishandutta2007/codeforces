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

vvl G;
vl par, vis, dep;
void dfs(ll u) {
    vis[u] = 1;
    for (auto v : G[u]) if (!vis[v]) {
        par[v] = u, dep[v] = dep[u] + 1;
        dfs(v);
    }
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, m; cin >> n >> m;
        G = vvl(n+2), par = vl(n+2, 0), vis = vl(n+2, 0);
        REP(i, m) {
            ll u, v; cin >> u >> v;
            G[u].eb(v), G[v].eb(u);
        }

        dep = vl(n+2, 1);
        dfs(1);
        dbg(par);

        ll q; cin >> q;
        vector<pll> pa;
        vl cnt(n+2, 0);
        REP(i, q) {
            ll u, v; cin >> u >> v;
            pa.eb(u, v);
            cnt[u]++, cnt[v]++;
        }

        ll tot = 0;
        FOR(i, 1, n) if (cnt[i] % 2 == 1) tot++;

        if (tot == 0) {
            cout << "YES" << endl;
            REP(i, q) {
                auto [u, v] = pa[i];
                vl path;
                stack<ll> other;

                while (u != v) {
                    if (dep[u] > dep[v]) {
                        path.eb(u);
                        u = par[u];
                    } else {
                        other.em(v);
                        v = par[v];
                    }
                }
                path.eb(u);

                while (!other.empty()) {
                    auto p = other.top(); other.pop();
                    path.eb(p);
                }

                ll sz = path.size(); cout << sz << endl;
                for (auto p : path) {
                    cout << p << " ";
                } cout << endl;
            }
        } else {
            cout << "NO" << endl;
            cout << tot / 2 << endl;
        }
    }
    return 0;
}