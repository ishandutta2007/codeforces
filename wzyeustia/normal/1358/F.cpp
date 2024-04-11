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
vl a, b;
ll sum2 = 0;

ll maybe() {
    bool match1 = true, match2 = true;
    REP(i, n) {
        if (a[i] != b[i]) match1 = false;
        if (a[i] != b[n-1-i]) match2 = false;
    }

    if (match1) return 1; if (match2) return 2;
    return 0;
}

ll comp() {
    bool inc = true, dec = true;
    REP(i, n-1) {
        ll delta = b[i] - b[i+1];
        if (delta <= 0) dec = false;
        if (delta >= 0) inc = false;
    }

    if (inc) return 1; if (dec) return 2;
    return 0;
}

stack<char> process() {

    stack<char> ret;
    stack<pll> ret2;
    
    ll last = 1;
    while (true) {
        ll result = maybe();
        if (result) {
            if (last != result) ret.em('R');
            return ret;
        }

        ll flag = comp(); if (!flag) break;

        // dbg(b); dbg(flag, last);
        if (flag != last) ret.em('R');
        last = flag;

        if (flag == 1) {
            ROF(i, n-1, 1) b[i] -= b[i-1];
        } else {
            FOR(i, 0, n-2) b[i] -= b[i+1];
        }
        ret.em('P'); sum2++;
    }

    return ret;
}

vector<pair<char, ll>> process2() {

    vector<pair<char, ll>> ret;

    while (true) {
        dbg(b);
        if (maybe()) {
            if (maybe() == 2) ret.eb('R', 1);
            return ret;
        }

        if (b[1] < b[0]) {swap(b[0], b[1]); ret.eb('R', 1);}

        if (b[1] == b[0]) break;
        if (b[0] == 0 || b[1] == 0) break;
        if (b[1]+b[0] <= a[1]+a[0]) break;

        ll div = b[1]/b[0];
        if (b[1]%b[0] + b[0] < a[1]+a[0]) {
            ll delta = a[1]+a[0] - b[0] - b[1]%b[0];
            div -= delta/b[0];
        }
        ret.eb('P', div); b[1] -= b[0] * div; sum2 += div;
    }

    return ret;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        cin >> n;
        a = vl(n), b = vl(n);
        REP(i, n) cin >> a[i];
        REP(i, n) cin >> b[i];

        
        stack<char> ans;
        if (n > 2) ans = process();
        else if (n == 2) { 
            vector<pair<char, ll>> temp = process2();
            if (sum2 <= 2e5) {
                for (auto [ch, num] : temp) {
                    REP(i, num) ans.em(ch);
                }
            }
        }
        dbg("process done");

        if (!maybe()) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            if (sum2 > 2e5) {
                cout << "BIG" << endl;
                cout << sum2 << endl;
            } else {
                cout << "SMALL" << endl;
                cout << ans.size() << endl;
                
                while (!ans.empty()) {
                    cout << ans.top(); ans.pop();
                }ln;
            }
        }
    }
    return 0;
}