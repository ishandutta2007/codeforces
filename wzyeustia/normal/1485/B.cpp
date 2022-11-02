#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

#define ln cout << endl;

typedef unsigned long long ULL;
typedef unsigned int Uint;
typedef unsigned char Byte;
typedef long double ld;

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

const ld PI = 3.14159265358979323846;
const ld E = 2.718281828459;
const ll SIZE = 3e2+3; 

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    const ll MOD = 998'244'353;

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, q, k; cin >> n >> q >> k;
        vector<int> arr(n+5, 0);
        FOR(i, 1, n) {cin >> arr[i];}
        arr[n+1] = k+1;

        vector<int> pre(n+5, 0);
        FOR(i, 1, n+1) {
            pre[i] = pre[i-1] + arr[i]-arr[i-1]-1;
        }

        dbg(pre);

        REP(i, q) {
            ll l, r; cin >> l >> r;
            ll ans = pre[n+1] + pre[r] - pre[l] + (n-(r-l+1));
            dbg(pre[n+1], pre[r], pre[l]);
            dbg(ans);
            cout << ans << endl;
        }
    }
    return 0;
}