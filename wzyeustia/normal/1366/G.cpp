#include <bits/stdc++.h>

using namespace std;

typedef int ll;
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
const ll SIZE = 2e6+5; 

const ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        string s, t; cin >> s >> t;
        ll n = s.length(), m = t.length();

        vl nxt(n+1, -1);
        stack<ll> st;
        REP(i, n) {
            if (s[i] == '.' && !st.empty()) {
                nxt[st.top()] = i+1; st.pop();
            }
            if (s[i] != '.') st.em(i);
        }

        dbg(nxt);

        vvl dp(n+2, vl(m+2, 1e6));
        dp[0][0] = 0;
        REP(i, n+1) REP(j, min(i, m)+1) {
            chkmin(dp[i+1][j], dp[i][j]+1);
            if (i<n && j<m && s[i] == t[j]) 
                chkmin(dp[i+1][j+1], dp[i][j]);
            if (i<n && j>0 && s[i] == '.')
                chkmin(dp[i+1][j-1], dp[i][j]);

            if (nxt[i] != -1) 
                chkmin(dp[nxt[i]][j], dp[i][j]);
        }
        dbg(dp[n][m]);
        cout << dp[n][m] << endl;
    }
    return 0;
}