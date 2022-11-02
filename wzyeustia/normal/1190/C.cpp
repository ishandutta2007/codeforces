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
ll MOD = 1e9+7;
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
        ll n, k; cin >> n >> k;
        string s; cin >> s;
        
        vl p0, p1;
        REP(i, n) {
            if (s[i] == '0') p0.eb(i);
            else p1.eb(i);
        }

        bool has = false;
        ll sz0 = p0.size(), sz1 = p1.size();
        REP(i, sz0-1) if (p0[i+1] - p0[i] >= k+1) has = true;
        REP(i, sz1-1) if (p1[i+1] - p1[i] >= k+1) has = true;
        if (sz0>0 && (p0[0] >= k || n - p0.back() >= k+1)) has = true;
        if (sz1>0 && (p1[0] >= k || n - p1.back() >= k+1)) has = true;

        bool win = false, tie = true;
        if (p0.empty() || p1.empty()) win = true;
        else {
            ll d0 = p0.back() - p0[0], d1 = p1.back() - p1[0];
            if (min(d0, d1) <= k-1) win = true;
            else {
                if (max(d0, d1) >= k+1 || has) tie = true;
                else tie = false;
            }
        }

        if (win) cout << "tokitsukaze" << endl;
        else if (tie) cout << "once again" << endl;
        else cout << "quailty" << endl;
    }   
    return 0;
}