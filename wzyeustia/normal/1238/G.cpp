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

#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
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
ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

void see(set<t3l> &se, ll crt) {
    dbg(crt);
    for (auto [cost, sz, idx] : se) {
        dbg(cost, sz, idx);
    }
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll n, m, lim, init; cin >> n >> m >> lim >> init;
        vector<t4l> event(n);
        REP(i, n) {
            ll t, mx, cost; cin >> t >> mx >> cost;
            event[i] = {t, mx, cost, i};
        } 
        event.eb(0, init, 0, -1);
        sort(all(event), greater<t4l>());

        bool can = true;
        set<t3l> source; //{cost, size} 
        ll last = m;
        ll lower = -lim, upper = 0, crt = 0;
        // lower: fixed part
        // upper: maximum cap
        // crt: source size for now
        ll tot = 0;
        for (auto [t, mx, cost, idx] : event) {
            ll past = last - t;
            last = t;

            lower += past, upper = min(upper + past, lim);
            while (!source.empty() && lower > 0) {
                auto [cost, sz, _] = *source.begin();
                source.erase({cost, sz, _});

                // dbg(cost, sz); assert(sz != 0);

                ll used = min(lower, sz);
                sz -= used;
                if (sz > 0) source.em(cost, sz, _);
                
                tot += used * cost, lower -= used, crt -= used;
            }
            if (lower > 0) can = false;

            source.em(cost, mx, idx), crt += mx;

            ll bound = min(lim, upper);
            while (crt > bound) {
                auto [cost, sz, _] = *source.rbegin();
                source.erase({cost, sz, _});

                ll used = min(crt - bound, sz);
                sz -= used;
                if (sz > 0) source.em(cost, sz, _);
                
                crt -= used;
                dbg(crt);
            }
            // if (crt < upper) can = false;

            // see(source, crt);
        }

        if (crt < upper) can = false;
        for (auto [cost, sz, _] : source) {
            tot += cost * sz;
        }

        dbg(tot, can);
        if (can) cout << tot << endl;
        else cout << -1 << endl;
    }
    return 0;
}