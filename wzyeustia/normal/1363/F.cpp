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
#define pb push_back
#define eb emplace_back
#define em emplace
#define mp make_pair
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

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
const ll SIZE = 2e6+3; 

const ll MOD = 1e9+7;
ll myMod(ll n) {return (n % MOD + MOD) % MOD;}


ll n;
void calc(string &s, vvl &pre) {
    REP(i, n) {
        ll ch = s[i]-'a';
        REP(j, 26) pre[i+1][j] = pre[i][j] + (j==ch);
    }
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        // After reading tutorial...
        cin >> n;
        string s, t; cin >> s >> t;

        vvl preS(n+2, vl(26, 0)), preT(n+2, vl(26, 0));
        calc(s, preS); calc(t, preT);

        bool can = true;
        REP(i, 26) if (preS[n][i] != preT[n][i]) can = false;

        vvl dp(n+2, vl(n+2, 1e9));
        REP(i, n+1) dp[0][i] = 0;

        FOR(i, 1, n) {
            FOR(j, 1, n) {
                ll ch = t[j-1]-'a';
                
                chkmin(dp[i][j], dp[i-1][j]+1);
                if (preS[i][ch] < preT[j][ch]) 
                    chkmin(dp[i][j], dp[i][j-1]);
                if (s[i-1] == t[j-1]) chkmin(dp[i][j], dp[i-1][j-1]);
            }
        }
        
        dbg(dp[n][n]);
        if (can) {
            cout << dp[n][n] << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}