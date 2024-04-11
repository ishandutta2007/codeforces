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

const ll MOD = 998'244'353;
ll myMod(ll n) {return (n % MOD + MOD) % MOD;}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, m; cin >> n >> m;
        vl a(n), b(m);
        REP(i, n) cin >> a[i];
        REP(i, m) cin >> b[i];
        
        bool flag = true;
        vl left(m, n-1), right(m, n-1);

        ROF(i, n-2, 0) chkmin(a[i], a[i+1]);
        dbg(a);

        if (a[0] != b[0]) flag = false;

        REP(i, m-1) {
            auto iter = lower_bound(all(a), b[i+1]);
            if ((*iter) != b[i+1]) flag = false;

            left[i] = iter - a.begin() - 1;

            iter = upper_bound(all(a), b[i+1]);
            right[i] = iter - a.begin() - 2;
        }

        dbg(left); dbg(right); dbg(flag);
        
        ll ans = 1;
        if (!flag) {
            ans = 0;
        } else {
            REP(i, m) {
                ans *= (right[i] - left[i] + 1ll);
                ans %= MOD;
            }
        }

        dbg(ans);
        cout << ans << endl;

    }
    return 0;
}