#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
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
const ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll n, l, r; cin >> n >> l >> r;
        vl left(n+2), right(n+2);
        REP(i, l) {
            ll k; cin >> k; left[k]++; 
        }
        REP(i, r) {
            ll k; cin >> k; right[k]++; 
        }

        FOR(i, 1, n) {
            ll mx = min(left[i], right[i]);
            left[i] -= mx, right[i] -= mx;
            l -= mx, r -= mx;
        }

        ll ans = 0, delta = (l-r)/2;
        dbg(delta);
        if (delta >= 0) {
            FOR(i, 1, n) if (left[i]>=2) {
                ll cancel = min(delta, left[i]/2);

                ans += cancel; delta -= cancel;
                left[i] -= cancel*2;
            }

            ans += r+delta*2;
        } else {
            FOR(i, 1, n) if (right[i]>=2) {
                ll cancel = min(-delta, right[i]/2);

                ans += cancel; delta += cancel;
                right[i] -= cancel*2;
            }
            dbg(delta);

            ans += l-delta*2;
        }

        dbg(ans);
        cout << ans << endl;
    }
    return 0;
}