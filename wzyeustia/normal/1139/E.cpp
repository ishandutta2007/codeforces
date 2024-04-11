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
ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

ll ans = 0, crt = 1;

const ll MAX_NODE = 2*5000 + 8, DELTA = 5000+2;
vvl G(MAX_NODE), H(MAX_NODE);
ll match[MAX_NODE];
bool inPath[MAX_NODE];

bool augmentPath(ll u) {
    for (auto v : G[u]) if (!inPath[v]) {
        inPath[v] = 1;
        if (!match[v] || augmentPath(match[v])) {
            // dbg(u, v, match[v]);
            match[u] = v, match[v] = u;
            return true;
        }
    }
    return false;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, m; cin >> n >> m;
        vl p(n+2); FOR(i, 1, n) cin >> p[i];
        vl c(n+2); FOR(i, 1, n) cin >> c[i];
        ll d; cin >> d;
        vl k(d), keep(n+2, 1); REP(i, d) {
            cin >> k[i];
            keep[k[i]] = 0;
        }

        FILL(match, 0);
        FOR(i, 1, n) if (keep[i]) {
            ll u = c[i], v = p[i];
            if (v < crt) {
                G[u].eb(v+DELTA), G[v+DELTA].eb(u);
                if (!match[u]) {
                    FILL(inPath, 0);
                    if (augmentPath(u)) ans++;
                }
                if (!match[v+DELTA]) {
                    FILL(inPath, 0);
                    if (augmentPath(v+DELTA)) ans++;
                }
            } else H[v+DELTA].eb(u);

            dbg(u, v);

            while (ans == crt) {
                for (auto u : H[crt+DELTA]) {
                    G[u].eb(crt+DELTA), G[crt+DELTA].eb(u);
                } 
                FILL(inPath, 0);
                if (augmentPath(crt+DELTA)) ans++;
                crt++;
            }
        }

        vl cnt(d);
        ROF(i, d-1, 0) {
            dbg(ans);
            cnt[i] = ans;
            ll u = c[k[i]], v = p[k[i]];
            if (v < crt) {
                G[u].eb(v+DELTA), G[v+DELTA].eb(u);
                if (!match[u]) {
                    FILL(inPath, 0);
                    if (augmentPath(u)) ans++;
                }
                if (!match[v+DELTA]) {
                    FILL(inPath, 0);
                    if (augmentPath(v+DELTA)) ans++;
                }
            } else H[v+DELTA].eb(u);

            dbg(u, v);

            while (ans == crt) {
                for (auto u : H[crt+DELTA]) {
                    G[u].eb(crt+DELTA), G[crt+DELTA].eb(u);
                } 
                FILL(inPath, 0);
                if (augmentPath(crt+DELTA)) ans++;
                crt++;
            }
            dbg(ans, crt);

            // FOR(v, 1+DELTA, ans+DELTA) dbg(v, match[v]);
        }

        // FOR(v, 1+DELTA, ans+DELTA) dbg(v, match[v]);
        REP(i, d) cout << cnt[i] << endl;
    }   
    return 0;
}