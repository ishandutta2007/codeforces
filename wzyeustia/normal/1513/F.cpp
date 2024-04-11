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
#define reset(x, y) memset(x, y, sizeof(x))
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
        vl a(n), b(n);
        REP(i, n) cin >> a[i];
        REP(i, n) cin >> b[i];

        ll ans = 0;
        const ll RED = 0, BLUE = 1;
        vector<tuple<ll, ll, ll>> seq; 
        REP(i, n) {
            ll delta = a[i]-b[i];
            ans += abs(delta);
            if (delta<0) seq.eb(a[i], RED, i), seq.eb(b[i], RED, i);
            if (delta>0) seq.eb(a[i], BLUE, i), seq.eb(b[i], BLUE, i);
        }

        sort(all(seq));
        set<pll> red, blue; // red: a[i] smaller
        ll cut = 0;
        for (auto [pos, type, idx] : seq) {
            dbg(pos, type, idx);
            if (type == RED) {
                if (red.count(mp(a[idx], idx))) {
                    red.erase(mp(a[idx], idx));

                    if (!blue.empty()) {
                        ll best = max(a[idx], (*blue.begin()).first );
                        chkmax(cut, pos - best);
                        dbg(pos-best);
                    }
                } else {
                    red.em(pos, idx);
                }
            } else {
                if (blue.count(mp(b[idx], idx))) {
                    blue.erase(mp(b[idx], idx));

                    if (!red.empty()) {
                        ll best = max(b[idx], (*red.begin()).first );
                        chkmax(cut, pos - best);
                        dbg(pos-best);
                    }
                } else {
                    blue.em(pos, idx);
                }
            }
        }

        dbg(ans, cut*2);
        cout << ans - cut*2 << endl;
    }
    return 0;
}