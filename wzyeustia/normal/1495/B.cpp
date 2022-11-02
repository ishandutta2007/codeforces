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

const ll MOD = 1e9+7;
ll myMod(ll n) {return (n % MOD + MOD) % MOD;}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        vl arr(n); REP(i, n) cin >> arr[i];

        vl hill;

        hill.eb(0);
        FOR(i, 1, n-2) {
            if (arr[i]>arr[i-1] && arr[i]>arr[i+1])
                hill.eb(i);
        }
        hill.eb(n-1);

        dbg(hill);
        vector<pll> slope;
        ll maxLen = 0;
        for (auto h : hill) {
            ll len1 = 0, len2 = 0, idx = h-1;
            while (idx >= 0 && arr[idx] < arr[idx+1]) len1++, idx--;
            idx = h+1;
            while (idx < n && arr[idx] < arr[idx-1]) len2++, idx++;

            chkmax(maxLen, max(len1, len2));
            slope.eb(len1, len2);

            dbg(len1, len2);
        }

        dbg(slope.size());
        ll cnt = 0, pos = -1;

        // if (!slope.empty()) {
            ll times = slope.size();
            REP(i, times) {
                dbg(i, slope.size());
                auto [l1, l2] = slope[i];
                if (l1 == maxLen || l2 == maxLen) {
                    cnt++; pos = i;
                }
            }
        // }
        

        dbg(cnt);

        bool win;
        if (cnt > 1 || hill.size() == 0) {
            win = false;
        } else {
            auto [l1, l2] = slope[pos];
            if (l1 < l2) swap(l1, l2);
            dbg(l1, l2);

            if (l1%2==1) win = false;
            else {
                if (l1 > l2) win = false;
                else win = true;
            }
        }

        dbg(win);

        if (win) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}