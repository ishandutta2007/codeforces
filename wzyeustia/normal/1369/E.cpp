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
        ll n, m; cin >> n >> m;
        vl foods(n+2); FOR(i, 1, n) cin >> foods[i];
        vector<multiset<pll>> another(n+2);

        FOR(i, 1, m) {
            ll x, y; cin >> x >> y;
            another[x].emplace(y, i);
            another[y].emplace(x, i);
        }

        vector<bool> checked(n+2, 0), arranged(m+2, 0);
        queue<ll> enough;
        stack<ll> ans;

        FOR(i, 1, n) {
            if (foods[i] >= another[i].size()) {
                enough.emplace(i);
                checked[i] = 1;
            }
        }

        while (!enough.empty()) {
            ll idx = enough.front(); enough.pop();
            dbg(idx);
            for (auto [num, pos]: another[idx]) {
                dbg(num, pos);
                if (!arranged[pos]) {arranged[pos] = 1; ans.emplace(pos);}

                another[num].erase(another[num].find(make_pair(idx, pos) ));
                if (foods[num] >= another[num].size() && !checked[num]) {
                    enough.emplace(num);
                    checked[num] = 1;
                }
            }
        }

        bool flag = true;
        FOR(i, 1, n) {
            if (!checked[i]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << "ALIVE" << endl;
            while (!ans.empty()) {
                ll num = ans.top(); ans.pop();
                cout << num << " ";
            }ln;
        } else {
            cout << "DEAD" << endl;
        }
    }
    return 0;
}