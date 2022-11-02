#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// typedef pair<ld, ld> pld;
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

ll getInv(ll a, ll p) {
 return (a == 1 ? 1 : (1 - p * getInv(p % a, a)) / a + p);
}

// factor precalculation
const ll FAC_SIZE = 2e5+3;
ll fac[FAC_SIZE], inv[FAC_SIZE];
void initFac(ll sz) {
    fac[0] = 1, inv[0] = 1;
    FOR(i, 1, sz-1) fac[i] = fac[i-1]*i%MOD;
    inv[FAC_SIZE-1] = getInv(fac[FAC_SIZE-1], MOD);
    ROF(i, sz-2, 1) inv[i] = inv[i+1]*(i+1)%MOD;
}
// combinatorics
ll comb(ll x, ll y) { // select y from x
    if (x < y) return 0;
    return fac[x] * inv[y]%MOD * inv[x-y]%MOD;
}

ll n, k;
vvl G;
vl sz, lo, sum, ans;
void dfs(ll u, ll par) {
    dbg(u, par);
    sz[u] = 1, lo[u] = 0;
    for (auto v : G[u]) if (v != par) {
        dfs(v, u);
        sz[u] += sz[v];
        sum[u] = (sum[u] + comb(sz[v], k))%MOD;
    }
    if (sz[u] < k) lo[u] = 0;
    else lo[u] = (MOD - sum[u] + comb(sz[u], k))%MOD;
    sum[u] = (sum[u] + comb(n-sz[u], k))%MOD;
}

void dfs1(ll u, ll par) {
    for (auto v : G[u]) if (v != par) {
        ll prevCnt = (comb(n, k) - sum[u] + MOD)%MOD;
        ll cut = (prevCnt * n + sz[v] * lo[v])%MOD;

        ll crtCnt1 = (comb(n-sz[v], k) + MOD-sum[u] + comb(sz[v], k))%MOD;
        ll crtCnt2 = (comb(n, k) + MOD-sum[v])%MOD;
        ll gain = ((n-sz[v])*crtCnt1 + n*crtCnt2)%MOD;
        ans[v] = (ans[u] + MOD - cut + gain)%MOD;
        dfs1(v, u);
    }
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    initFac(FAC_SIZE);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        cin >> n >> k;
        G = vvl(n+2), sz = vl(n+2);
        lo = vl(n+2), sum = vl(n+2), ans = vl(n+2);
        REP(i, n-1) {
            ll u, v; cin >> u >> v;
            G[u].eb(v), G[v].eb(u);
        }

        dfs(1, 0);
        FOR(u, 1, n) ans[1] = (ans[1] + sz[u] * lo[u])%MOD;

        dfs1(1, 0);
        dbg(lo);
        dbg(ans);

        ll answer = 0;
        FOR(u, 1, n) answer = (answer + ans[u])%MOD;
        cout << answer << endl;
    }

    return 0;
}