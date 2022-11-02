#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
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
const ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

// ll n, m; 
// vvvl dp(800, vvl(2, vl(2, 0))), done(800, vvl(2, vl(2, 0)));

// ll calc(ll len, ll l, ll r) {
//     dbg(len, l, r);
//     if (done[len][l][r]) return dp[len][l][r];
//     done[len][l][r] = 1;
    
//     dp[len][l][r] = 0;
//     FOR(s1, 0, len-1) {
//         dp[len][l][r] = (dp[len][l][r] + calc(s1, l, 1)*calc(len-1-s1, 1, r)%m)%m;
//         if (len == 3) dbg(s1, dp[len][l][r]);
//     }
//     return dp[len][l][r];
// }

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    // dp[0][0][0] = dp[0][0][1] = dp[0][1][0] = dp[0][1][1] = 1;
    // dp[1][1][1] = 1;
    // done[0][0][0] = done[0][0][1] = done[0][1][0] = done[0][1][1] = 1;
    // done[1][1][1] = 1;

    int T = 1;
    cin >> T;
    REP(I, T) {
        // cin >> n >> m;
        // cout << calc(n, 0, 0) << endl;

        ll n, x; cin >> n >> x;
        vl w(n); ll sum = 0; 
        REP(i, n) {
            cin >> w[i];
            sum += w[i];
        }

        bool can = false;
        if (sum < x) can = true;
        sort(all(w));
        if (w[0] != w[n-1]) can = true;
        if (x%w[0]) can = true;
        if (sum == x) can = false;

        if (can) {
            cout << "YES" << endl;
            vl used(n), ans;
            ll crt = 0;
            ROF(i, n-2, 0) if (crt+w[i]<x) {
                crt += w[i], used[i] = 1, ans.eb(w[i]);
            } used[n-1] = 1, ans.eb(w[n-1]);

            REP(i, n) if (!used[i]) {
                ans.eb(w[i]);
            }

            dbg(ans);
            REP(i, n) {
                cout << ans[i] << " ";
            }cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}