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

ll getInv(ll y) {
    return fastPow(y, MOD-2)%MOD;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        vl a(n); REP(i, n) cin >> a[i];

        vvl nxt(n+2, vl(2005, -1)), jmp(n+2);
        REP(i, n) nxt[i][a[i]] = i+1;

        FOR(val, 1, 2000) {
            REP(i, n) {
                if (nxt[i][val] != -1) {
                    // dbg(i, val);
                    ll pos = nxt[i][val];
                    jmp[i].eb(pos);
                    if (pos < n && nxt[pos][val] != -1) {
                        nxt[i][val+1] = nxt[pos][val];
                    }
                }
            }
        }

        vl dp(n+2, 0);
        REP(i, n) {
            dbg(i); dbg(jmp[i]);
            for (auto idx : jmp[i]) {
                chkmax(dp[idx], dp[i] + idx-i-1);
            }
            chkmax(dp[i+1], dp[i]);
        }

        dbg(dp);
        cout << n - dp[n] << endl;
    }
    return 0;
}