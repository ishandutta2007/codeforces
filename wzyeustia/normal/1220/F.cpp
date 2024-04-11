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
const ld EPS = 1e-8;
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
        ll n; cin >> n;
        ll one = -1;
        vl a(n); REP(i, n) {
            cin >> a[i];
            if (a[i] == 1) one = i;
        }

        vl left(n), right(n);
        
        stack<pll> st;
        FOR(i, 1, n-1) {
            ll val = a[(one + i) % n], dep = st.size();
            while (!st.empty()) {
                auto [v0, d0] = st.top();
                if (v0 > val) {
                    chkmax(dep, d0);
                    st.pop();
                } else break;
            }
            st.em(val, dep+1);
            left[i] = max(left[i-1], dep+1);
        }

        while (!st.empty()) st.pop();
        FOR(i, 1, n-1) {
            ll val = a[(one + n - i) % n], dep = st.size();
            while (!st.empty()) {
                auto [v0, d0] = st.top();
                if (v0 > val) {
                    chkmax(dep, d0);
                    st.pop();
                } else break;
            }
            st.em(val, dep+1);
            right[i] = max(right[i-1], dep+1);
        }

        dbg(left); dbg(right);

        ll ans = n, times = n;
        REP(i, n) {
            ll mx = max(left[i], right[n-1-i]), pos = (one + i + 1)%n;
            if (ans == mx) chkmin(times, pos);
            if (ans > mx) {
                times = pos, ans = mx;
            }

        }
        cout << ans+1 << " " << times << endl;
    }
    return 0;
}