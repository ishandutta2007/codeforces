#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
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
ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

ll n, k, ans;
vl a, d0, d1;

void solve(ll l, ll r) {
    bool found = false;
    for (ll i = l; i <= r; i += 2) {
        if (a[i] != -1) found = true;
    }
    if (!found) {
        for (ll i = l; i < r; i += 2) ans = ans * (k-1)%MOD;
        ans = ans * k%MOD;
        return;
    }

    while (l <= r && a[l] == -1) {
        ans = ans * (k-1)%MOD;
        l += 2;
    }
    while (l <= r && a[r] == -1) {
        ans = ans * (k-1)%MOD;
        r -= 2;
    }
    ll cnt = 0, last = a[l];
    for (ll i = l+2; i <= r; i+=2) {
        if (a[i] == -1) cnt++;
        else {
            if (a[i] == last) ans = ans * d1[cnt]%MOD;
            else ans = ans * d0[cnt]%MOD;
            cnt = 0; last = a[i];
        }
    }
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        cin >> n >> k;
        a = vl(n); REP(i, n) cin >> a[i];

        d0 = vl(n+2, 1), d1 = vl(n+2, 1);
        d0[1] = max(0ll, k-2); d1[1] = max(0ll, k-1);
        FOR(i, 2, n) {
            d0[i] = (d0[i-1] * (k-2) + d1[i-1])%MOD;
            d1[i] = (d0[i-1] * (k-1))%MOD;
        }

        ans = 1;
        REP(i, n-2) if (a[i] == a[i+2] && a[i] != -1) ans = 0;

        ll l = 0, r = n-1; if (r%2 == 1) r--;
        solve(l, r);
        l = 1, r = n-1; if (r%2 == 0) r--;
        solve(l, r);
        cout << ans << endl;
    }   
    return 0;
}