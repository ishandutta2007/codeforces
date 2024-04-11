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
ll MOD = (1ll << 31) - 1;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)


int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        vl a(n); REP(i, n) cin >> a[i];
        ll l = 0, cl = 0;
        while (l<n && a[l] == 0) l++, cl++;

        if (l == n) {
            if (n == 1) cout << 0 << endl;
            else cout << 1 << endl;
            continue;
        }

        ll r = n-1, cr = 0;
        while (r>=0 && a[r] == 0) r--, cr++;

        multiset<ll> s0, s1;
        ll idx = l, tot = 0;
        ll free0 = n/2, free1 = n - free0;
        while (idx != r) {
            ll odd = (a[idx++]%2), cnt = 0;
            if (odd) free1--; else free0--;

            while (a[idx] == 0) idx++, cnt++;

            if (odd != (a[idx]%2) ) {
                tot++;
            } else {
                if (!cnt) continue;
                tot += 2;
                if (odd) s1.em(cnt);
                else s0.em(cnt);
            } 
        }
        dbg(tot);

        if (a[r] % 2) free1--; else free0--;
        dbg(free1, free0, cl, cr);

        for (auto len : s1) {
            dbg(len);
            if (free1 >= len) free1 -= len, tot-=2;
        }
        dbg("");
        for (auto len : s0) {
            dbg(len);
            if (free0 >= len) free0 -= len, tot-=2;
        }

        dbg(tot);

        if (a[l] % 2) 
            if (free1 < cl && cl > 0) tot++; else free1 -= cl;
        else 
            if (free0 < cl && cl > 0) tot++; else free0 -= cl;

        if (a[r] % 2) 
            if (free1 < cr && cr > 0) tot++; else free1 -= cr;
        else 
            if (free0 < cr && cr > 0) tot++; else free0 -= cr;

        dbg(tot);
        cout << tot << endl;
    }
    return 0;
}