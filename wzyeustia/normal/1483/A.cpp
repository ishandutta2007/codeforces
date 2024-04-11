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
#define err(...)
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
    cin >> T;
    REP(I, T) {
        ll num, days; cin >> num >> days;
        dbg(num, days);
        vvl list;
        vector<pll> toSelect;
        REP(i, days) {
            ll cnt; cin >> cnt;
            vl can(cnt); REP(j, cnt) cin >> can[j];
            toSelect.eb(cnt, i);
            list.eb(can);
        }

        sort(all(toSelect));

        // cout << "select : ";
        // for (auto [cnt, idx] : toSelect) {
        //     cout << cnt << " " << idx << " | ";
        // }ln;

        bool can = true;
        vl used(num+2, 0), ans(days+2, 0);
        REP(i, days) {
            auto [cnt, idx] = toSelect[i];
            ll selected = -1;
            for (auto fri : list[idx]) {
                // dbg(fri);
                if (selected == -1 || used[selected] > used[fri])
                    selected = fri;
            }

            ans[idx] = selected;
            used[selected]++;
            if (used[selected] > (days+1)/2) can = false;
            dbg(used);
        }

        if (can) {
            cout << "YES" << endl;
            REP(i, days) {
                cout << ans[i] << ' ';
            }ln;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}