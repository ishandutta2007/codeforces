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
const ll SIZE = 3e2+3; 

const ll MOD = 998'244'353;
ll myMod(ll n) {return (n % MOD + MOD) % MOD;}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        map<ll, ll> myMap;
        REP(i, n) {ll num; cin >> num; myMap[num]++;}

        vl vec;
        for (auto key : myMap) {
            vec.eb(key.second);
        }
        sort(all(vec));
        dbg(vec);

        vl pre(vec.size()); partial_sum(all(vec), pre.begin());

        ll ans = pre[vec.size()-1];
        REP(i, vec.size()) {
            ll limit = vec[i];
            ll allGoneIdx = lower_bound(all(vec), limit) - vec.begin() - 1;

            ll allGone = 0;
            if (allGoneIdx != -1) {
                allGone = pre[allGoneIdx];
            }

            ll rest = pre[vec.size()-1] - allGone;
            ll reserved = (vec.size()-1 - allGoneIdx) * limit;

            ll thisResult = allGone + rest - reserved;
            chkmin(ans, thisResult);
        }

        dbg(ans);
        cout << ans << endl;
    }
    return 0;
}