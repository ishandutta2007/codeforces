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

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    const ll SZ = 2048;
    vl len(SZ, 0);
    FOR(i, 1, SZ) {
        ll bit = 1;
        while (i & bit) len[i]++, bit<<=1;
    }

    // dbg(len);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, m; cin >> n >> m;
        vl aggr(n); REP(i, n) cin >> aggr[i];
        vl cost(n); REP(i, n) cin >> cost[i];
        vl earn(n+m+21); FOR(i, 1, n+m) cin >> earn[i];
        vl pre(n+m+21); partial_sum(all(earn), pre.begin());

        vvl dp(n+m+2, vl(SZ, -1e15)); 
        FOR(i, 1, n+m) dp[i][0] = 0;
        
        ROF(i, n-1, 0) {
            ll crt = aggr[i];
            ROF(j, SZ-1, 1) {
                ll add = pre[crt+len[j-1]]-pre[crt-1] - cost[i];
                chkmax(dp[crt][j], dp[crt][j-1] + add);

                if (add > 1e9) {
                    dbg(i, crt, add);
                    dbg(j-1, crt+len[j-1]);
                }
                // if (crt == 1 && j == 1) dbg(add);
            }
            // dbg(crt); dbg(dp[crt]);

            ll range = SZ;
            FOR(level, crt+1, n+m) {
                range = max(1ll, range/2);
                REP(j, range) {
                    chkmax(dp[level][j], max(dp[level-1][j*2], dp[level-1][j*2+1]));
                }
            }
        }

        ll ans = 0;
        REP(i, SZ) chkmax(ans, dp[n+m][i]);
        cout << ans << endl;
    }
    return 0;
}