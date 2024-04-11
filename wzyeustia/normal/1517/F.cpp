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

ll getInv(ll a, ll p) {
 return (a == 1 ? 1 : (1 - p * getInv(p % a, a)) / a + p);
}

ll fastPow(ll num, ll exp) {
    if (exp == 0) return 1;
    if (exp == 1) return num;
    else {
        ll half = fastPow(num, exp/2);
        if (exp % 2 == 1) 
            return sqr(half)%MOD * num % MOD;
        else 
            return sqr(half)%MOD;
    }
}

ll cover[302][302], depth[302][302], sz[302];
// vvl cover, depth;
ll r, mx = 0;
vl G[302];
void dfs(ll u, ll par, ll k) {
    chkmax(mx, k);
    sz[u] = 1, depth[u][0] = 1, cover[u][r] = 1;
    for (auto v : G[u]) {
        if (v == par) continue;
        dfs(v, u, k+1);

        // ll nc[302] = {0}, nd[302] = {0};
        vl nc(r+2), nd(r+2);
        FOR(d1, 0, r) {
            if (d1 > sz[u] && d1 < r-sz[u]) d1 = r-sz[u];
            FOR(d2, 0, r) {
                if (d2 > sz[v] && d2 < r-sz[v]) d2 = r-sz[v];
                if (d2 >= d1+1) {
                    nc[d2-1] += cover[u][d1] * cover[v][d2] %MOD;
                    nc[d2-1] += depth[u][d1] * cover[v][d2] %MOD;
                } else {
                    nc[d1] += cover[u][d1] * cover[v][d2] %MOD;
                    nd[d1] += depth[u][d1] * cover[v][d2] %MOD;
                }
                if (d1 >= d2+1) {
                    nd[d1] += depth[u][d1] * depth[v][d2] %MOD;
                    nc[d1] += cover[u][d1] * depth[v][d2] %MOD;
                } else {
                    nd[d2+1] += depth[u][d1] * depth[v][d2] %MOD;
                    nd[d2+1] += cover[u][d1] * depth[v][d2] %MOD;
                }
            }
        }
        FOR(i, 0, r) cover[u][i] = nc[i]%MOD, depth[u][i] = nd[i]%MOD;
        sz[u] += sz[v];
        // dbg(nc); dbg(nd);
    }
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        REP(i, n-1) {
            ll u, v; cin >> u >> v;
            G[u].eb(v), G[v].eb(u);
        }

        vl pre(n+2);
        for (r = 0; r <= n; r++) {
            FILL(depth, 0), FILL(cover, 0);
            // cover = vvl(n+2, vl(n+2, 0)), depth = vvl(n+2, vl(n+2, 0));
            dfs(1, 0, 0);
            REP(i, r+1) {
                pre[r] += cover[1][i]; 
            } pre[r] %= MOD;
        }
        dbg(pre);

        vl cnt(n+2);
        FOR(i, 1, n) {
            cnt[i] = pre[i]-pre[i-1]+MOD;
        }
        dbg(cnt);

        ll ans = 0;
        FOR(i, 1, n+1) {
            ans += cnt[i] * (i-1); ans %= MOD;
        } ans += n-1;

        dbg(ans);
        ans = (ans * getInv(fastPow(2, n), MOD))%MOD;
        dbg(ans);
        cout << ans << endl;
    }
    return 0;
}