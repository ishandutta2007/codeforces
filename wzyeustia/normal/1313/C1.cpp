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
const ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        vl a(n); REP(i, n) cin >> a[i];

        vl pre(n), suf(n);
        stack<pll> st; // [height, cnt]
        ll tot = 0;
        REP(i, n) {
            ll cnt = 1;
            while (!st.empty() && st.top().first > a[i]) {
                auto [h, c] = st.top(); st.pop();
                cnt += c;
                tot -= h * c;
            }
            st.em(a[i], cnt);
            tot += a[i] * cnt;
            pre[i] = tot;
        }

        st = stack<pll>(), tot = 0;
        ROF(i, n-1, 0) {
            ll cnt = 1;
            while (!st.empty() && st.top().first > a[i]) {
                auto [h, c] = st.top(); st.pop();
                cnt += c;
                tot -= h * c;
            }
            st.em(a[i], cnt);
            tot += a[i] * cnt;
            suf[i] = tot;
        }

        dbg(pre); dbg(suf);
        ll ans = 0, pos = -1;
        REP(i, n) {
            if (ans < pre[i] + suf[i] - a[i]) {
                ans = pre[i]+suf[i]-a[i];
                pos = i;
            }
        }
        dbg(ans, pos);

        vl plan(n); plan[pos] = a[pos];
        ROF(i, pos-1, 0) {
            plan[i] = min(plan[i+1], a[i]);
        } 
        FOR(i, pos+1, n-1) {
            plan[i] = min(plan[i-1], a[i]);
        }

        dbg(plan);

        REP(i, n) {
            cout << plan[i] <<" ";
        }cout << endl;
    }
    return 0;
}