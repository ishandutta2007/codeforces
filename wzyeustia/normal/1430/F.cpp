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

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, k; cin >> n >> k;
        vl l(n+2), r(n+2), a(n+2);
        FOR(i, 1, n) cin >> l[i] >> r[i] >> a[i];

        vl pre(n+2); FOR(i, 1, n) pre[i] = pre[i-1] + a[i];
        vvl dp(n+1, vl(n+1, 1e14));
        dp[0][0] = 0;

        FOR(i, 1, n) {
            REP(j, i) {
                if (dp[i-1][j] == -1) continue;
                ll last = k - (pre[i-1]-pre[j]) % k;
                if (j != i-1 && last == k) last = 0;

                ll time = (a[i]-last + k-1) / k;
                if (l[i] + time > r[i]) dp[i][j] = -1;
                else {
                    dp[i][j] = dp[i-1][j];
                    if (l[i] + time < r[i] || l[i+1] > r[i]) {
                        ll crt = k - (pre[i]-pre[j])%k; if (crt == k) crt = 0;
                        chkmin(dp[i][i], dp[i-1][j] + crt);
                    }
                }
            }
            dbg(dp[i]);
        }

        ll ans = 1e14;
        FOR(i, 0, n) {
            if (dp[n][i] != -1) chkmin(ans, dp[n][i]);
        } dbg(ans);
        if (ans >= 1e14) {
            cout << -1 << endl;
        } else {
            cout << ans + pre[n] << endl;
        }
        
    }
    return 0;
}