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
    cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        vl a(2*n+3); ll sum = 0;
        FOR(i, 1, 2*n) {
            cin >> a[i];
            if (a[i] == 1) sum++;
            else sum--;
        }
        
        ll more = 1, delta;
        if (sum < 0) more = 2;
        delta = abs(sum);

        vl lft(2*n+2, 1e8), rgt(2*n+2, 1e8); lft[0] = rgt[0] = 0;
        ll crt = 0;
        ROF(i, n, 1) {
            if (a[i] == more) crt++;
            else crt--;

            if (crt > 0) chkmin(lft[crt], n+1 - i);
        } 

        crt = 0;
        FOR(i, n+1, 2*n) {
            if (a[i] == more) crt++;
            else crt--;

            if (crt > 0) chkmin(rgt[crt], i-n);
        }
        dbg(more, delta);
        dbg(lft); dbg(rgt);

        ll ans = 2*n;
        FOR(i, 0, min(n, delta)) {
            chkmin(ans, lft[i] + rgt[delta-i]);
        }

        dbg(ans);
        cout << ans << endl;
    }
    return 0;
}