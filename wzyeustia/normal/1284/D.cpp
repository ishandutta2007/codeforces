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

const ll IN = 0, OUT = 1;
bool can = true;

void check(vector<t3l> &seq, vector<pll> &seg) {
    set<pll> lft, rgt; lft.em(0, -1), rgt.em(1e9+2, -1);
    for (auto [pos, type, idx] : seq) {
        auto [l, r] = seg[idx];
        if (type == IN) {
            lft.em(l, idx), rgt.em(r, idx);
        } else {
            lft.erase({l, idx}), rgt.erase({r, idx});
        }
        if (lft.rbegin()->first > rgt.begin()->first) can = false;

        // ll k1 = lft.rbegin()->first, k2 = rgt.begin()->first;
        // dbg(k1, k2);
    }
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        vector<t3l> seq1, seq2;
        vector<pll> seg1(n+2), seg2(n+2);
        FOR(i, 1, n) {
            ll x1, x2, y1, y2; cin >> x1 >> x2 >> y1 >> y2;
            seg1[i] = {y1, y2}; seg2[i] = {x1, x2};
            seq1.eb(x1, IN, i), seq1.eb(x2, OUT, i);
            seq2.eb(y1, IN, i), seq2.eb(y2, OUT, i);
        } sort(all(seq1)), sort(all(seq2));

        check(seq1, seg1); check(seq2, seg2);

        if (can) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}