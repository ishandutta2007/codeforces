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
const ld EPS = 1e-8;
ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

vector<set<ll>> G, H;
vl vis, a;
ll s;
void dfs0(ll u, ll par) {
    dbg(u, par);
    vis[u] = 1;
    for (auto v : G[u]) {
        if (vis[v]) continue;
        H[u].em(v), dfs0(v, u);
    }
}

vl earn;
void dfs1(ll u, ll par) {
    for (auto v : G[u]) {
        if (!H[u].count(v) && v != par) {
            earn[u] = earn[v] = 1;
            // dbg(u, v);
        }
    }

    for (auto v : H[u]) {
        dfs1(v, u);
    }
}

ll ans = 0, offset = 0;
ll dfs2(ll u, ll par) {
    ll mx = 0;
    for (auto v : H[u]) {
        dbg(u, v);
        chkmax(mx, dfs2(v, u));
        if (earn[v]) earn[u] = 1;
    }

    if (earn[u]) {
        ans += a[u];
        chkmax(offset, mx);
        return 0;
    } else {
        return mx + a[u];
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
        a = vl(n+1); FOR(i, 1, n) cin >> a[i];
        G = vector<set<ll>>(n+2), H = vector<set<ll>>(n+2);
        REP(i, m) {
            ll u, v; cin >> u >> v;
            G[u].em(v), G[v].em(u);
        }
        cin >> s;

        vis = vl(n+2, 0);
        dfs0(s, 0);
        earn = vl(n+2, 0);
        dfs1(s, 0);
        dbg(earn);

        chkmax(offset, dfs2(s, 0));

        dbg(earn);
        dbg(ans, offset);
        ans += offset;
        cout << ans << endl;

        // ll s; cin >> s;
        // ll ans = a[s], mx = 0;
        // FOR(i, 1, n) if (i != s) {
        //     if (deg[i] >= 2) ans += a[i];
        //     else chkmax(mx, a[i]);
        // }

        // ans += mx;
        // cout << ans << endl;
    }
    return 0;
}