#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define FOR(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (ll (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define pb push_back
#define eb emplace_back
#define em emplace
#define mp make_pair
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

#define FILL0(arr) memset(arr, 0, sizeof(arr))

#define ln cout << endl;

// Can I use this?
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
const ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}

vl solve(ll len) {
    vl dp(len+2, 0);
    ll sum = 0, offset = 0;
    
    FOR(i, 1, len) {
        dp[i] = sum + offset + i/2; dp[i] %= MOD;
        sum += dp[i]; sum %= MOD;
        offset = offset * 2 + i/2; offset %= MOD;
    }
    // dbg(dp);
    return dp;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    ll SZ = 3e5;
    vl pow(3e5+2, 1);
    FOR(i, 1, SZ) pow[i] = pow[i-1] * 2 %MOD;

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, m; cin >> n >> m;
        vl dp = solve(max(n, m)); dbg(dp);

        vvl G(n+2, vl(m+2));
        ll cnt = 0;
        FOR(i, 1, n) FOR(j, 1, m) {
            char ch; cin >> ch; G[i][j] = ch;
            if (ch == 'o') cnt++;
        }
        dbg(cnt);

        ll ans = 0;
        FOR(i, 1, n) {
            ll len = 0;
            FOR(j, 1, m) {
                if (G[i][j] == '*'){
                    ans += dp[len] * pow[cnt-len] % MOD;
                    ans %= MOD, len = 0;
                }
                else len++;
            } 
            ans += dp[len] * pow[cnt-len] % MOD;
            ans %= MOD, len = 0;
        }

        FOR(i, 1, m) {
            ll len = 0;
            FOR(j, 1, n) {
                if (G[j][i] == '*') {
                    ans += dp[len] * pow[cnt-len] % MOD;
                    ans %= MOD, len = 0;
                }
                else len++;
            } 
            ans += dp[len] * pow[cnt-len] % MOD;
            ans %= MOD, len = 0;
        }

        dbg(ans);
        cout << ans << endl;
    }
    return 0;
}