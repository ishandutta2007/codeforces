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
ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)


vl h, mx, d0, d1;
vvl G;
void dfs(ll u, ll par) {
    ll sum = 0, bigChild = -1;
    mx[u] = h[u], d0[u] = d1[u] = 1e16;

    bool has = false;
    for (auto v : G[u]) if (v != par) {
        has = true;
        dfs(v, u);
        sum += d0[v];
        if (mx[v] > mx[u]) {
            bigChild = v;
            mx[u] = mx[v];
        }
    }

    for (auto v : G[u]) if (v != par) {
        chkmin(d1[u], d1[v]-d0[v] + sum);
        if (v == bigChild) d0[u] = sum - d0[v] + d1[v] + mx[u];
    }

    if (bigChild == -1) d0[u] = d1[u] + mx[u];
    if (!has) d0[u] = mx[u], d1[u] = 0;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        h = vl(n+2); G = vvl(n+2);
        mx = vl(n+2), d0 = vl(n+2), d1 = vl(n+2);
        ll root = 1;
        FOR(i, 1, n) {
            cin >> h[i];
            if (h[i] > h[root]) root = i;
        }
        REP(i, n-1) {
            ll u, v; cin >> u >> v;
            G[u].eb(v), G[v].eb(u);
        }

        dbg(root);
        dfs(root, 0);
        dbg(d0); dbg(d1);

        ll ans = 2*h[root];
        vl earn;
        for (auto v : G[root]) {
            ans += d0[v];
            earn.eb(d1[v] - d0[v]);
        }
        sort(all(earn));
        dbg(earn);

        dbg(ans);
        if (earn.size() > 1) ans += earn[0]+earn[1];
        else ans += earn[0];

        cout << ans << endl;
    }   
    return 0;
}