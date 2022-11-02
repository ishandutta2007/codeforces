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

#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
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
ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937_64 rng((unsigned ll) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<ll>(a, b)(rng)


int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll k1, k2, k3; cin >> k1 >> k2 >> k3;
        ll n = k1+k2+k3;

        vl from(n+2); 
        REP(i, k1) {
            ll v; cin >> v;
            from[v] = 1;
        }
        REP(i, k2) {
            ll v; cin >> v;
            from[v] = 2;
        }
        REP(i, k3) {
            ll v; cin >> v;
            from[v] = 3;
        }
        dbg(from);

        vl suf2(n+2, 0), suf3(n+2, 0);
        ROF(i, n, 0) {
            suf2[i] = suf2[i+1], suf3[i] = suf3[i+1];
            if (from[i] == 2) suf2[i]++;
            if (from[i] == 3) suf3[i]++;
        }

        vl pre1(n+2, 0);
        FOR(i, 1, n+1) {
            pre1[i] = pre1[i-1];
            if (from[i] == 1) pre1[i]++;
        }
        ll tot1 = pre1[n];
        dbg(pre1); dbg(suf2); dbg(suf3);

        vl offset(n+2, 0);
        ROF(i, n, 0) offset[i] = suf2[i]-suf3[i];
        ROF(i, n, 0) chkmin(offset[i], offset[i+1]);
        dbg(offset);

        ll ans = n;
        FOR(cut, 0, n) {
            ll cost1 = cut-pre1[cut] + tot1-pre1[cut];
            ll cost2 = suf3[cut] + offset[cut];
            dbg(cut, cost1, cost2);
            chkmin(ans, cost1+cost2);
        }

        dbg(ans);
        cout << ans << endl;
    }
    return 0;
}