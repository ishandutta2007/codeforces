#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> t3l;
typedef tuple<ll, ll, ll, ll> t4l;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
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
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

const ll SIGMA = 26, MOD = 998'244'353;
const ll MX = (1<<23);
short lim[MX][SIGMA]; 
int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        short cnt[n][SIGMA]; FILL(cnt, 0);
        REP(i, n) {
            string s; cin >> s;
            for (auto c : s) cnt[i][c-'a']++;
        }

        FILL(lim, 0x7f);
        const ll SZ = 1ll << n;
        REP(mask, SZ) REP(p, n) if ((1<<p) & mask) {
            REP(j, SIGMA) chkmin(lim[mask][j], cnt[p][j]);
        }
        vl dp(SZ, 0);
        REP(mask, SZ) {
            dp[mask] = 1;
            REP(j, SIGMA) dp[mask] = dp[mask] * (lim[mask][j] + 1)%MOD;
            if (__builtin_popcount(mask) % 2 == 0) dp[mask] = MOD - dp[mask];
        } dp[0] = 0;
        dbg(dp);

        REP(p, n) REP(mask, SZ) if ((1<<p) & mask) {
            dp[mask] = (dp[mask] + dp[mask ^ (1<<p)])%MOD;
        }
        dbg(dp);

        ll ans = 0;
        REP(mask, SZ) {
            ll sum = 0, k = __builtin_popcount(mask);
            REP(p, n) if ((1<<p) & mask) {
                sum += p+1;
            }
            ans ^= sum * k * dp[mask];
        }

        cout << ans << endl;
    }
}