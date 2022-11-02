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

const ll FREE = 0, NOT_Y = 1, NOT_Z = 2;
ll period = -1, start = -1;

ll calc(ll num) {
    if (num < 0) return 0;
    if (num <= start) return num;
    return start + (num-start)%period;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll n, x, y, z; cin >> n >> x >> y >> z;
        vl a(n); REP(i, n) cin >> a[i];

        vvl sg(1e3, vl(3));
        period = -1, start = -1;
        map<ll, ll> ma;
        FOR(i, 1, 1e5-1) {
            REP(type, 3) {
                set<ll> se;
                se.em(sg[max(0ll, i-x)][FREE]);
                if (type != NOT_Y) se.em(sg[max(0ll, i-y)][NOT_Y]);
                if (type != NOT_Z) se.em(sg[max(0ll, i-z)][NOT_Z]);

                ROF(val, 3, 0) if (!se.count(val)) sg[i][type] = val;
            }

            if (i >= 4) {
                ll tag = 0;
                REP(k, 5) REP(type, 3) {
                    tag <<= 2; tag |= sg[i-k][type];
                }
                if (ma[tag]) {
                    period = i-ma[tag];
                    start = ma[tag]-4;
                    break;
                } else {
                    ma[tag] = i;
                }
            }
        }

        dbg(start, period);

        vl val(n); ll tot = 0; 
        REP(i, n) {
            val[i] = sg[calc(a[i])][FREE];
            tot ^= val[i];
        }

        ll ans = 0;
        REP(i, n) REP(type, 3) {
            ll delta = x; 
            if (type == NOT_Y) delta = y;
            if (type == NOT_Z) delta = z;
            
            ll last = sg[calc(a[i])][FREE], nxt = sg[calc(a[i] - delta)][type];
            // dbg(tot, last, nxt);

            ll status = tot ^ last ^ nxt;
            if (status == 0) ans++;
        }

        dbg(ans);
        cout << ans << endl;
    }
    return 0;
}