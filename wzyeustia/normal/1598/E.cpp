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
#define lb_pos(arr, key) lower_bound(all(arr), key) - (arr).begin()
#define ub_pos(arr, key) upper_bound(all(arr), key) - (arr).begin()

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
const ld EPS = 1e-8;
ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

const ll UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3;
ll n, m, q;
bool can[1003][1003];

bool valid(ll x, ll y) {
    return (x>=1 && x<=n && y>=1 && y<=m);
}

ll up(ll x, ll y, ll dir) {
    ll ret = 0;
    while (valid(x, y) && can[x][y]) {
        ret++;
        if (dir == UP) {
            y--, dir = LEFT; continue;
        }
        if (dir == LEFT) {
            x--,dir = UP; continue;
        }
        if (dir == DOWN) {
            y++, dir = RIGHT; continue;
        }
        if (dir == RIGHT) {
            x++, dir = DOWN;continue;
        }
    }
    return ret;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        FILL(can, true);
        cin >> n >> m >> q;
        ll tot = 0, a = 1, b = 1, p = 0;
        while (max(a, b) <= max(n, m)) {
            // dbg(a, b, tot);
            if (a<=n && b<=m) tot += (n-a+1)*(m-b+1);
            if (a<=m && b<=n) tot += (n-b+1)*(m-a+1);
            if (p) a++; else b++;
            p = 1-p;
        } tot -= n*m;

        dbg(tot);

        // set<ll> bound[n+m+3];
        // FOR(x, 1, n) {
        //     ll y = 0;
        //     bound[x+m].em(x);
        // }
        // FOR(y, 1, m) {
        //     ll x = 0;
        //     bound[m-y].em(y);
        // }


        REP(tt, q) {
            ll x, y; cin >> x >> y;
            bool last = can[x][y];
            can[x][y] = 1;

            vl cnt(4); REP(i, 4) cnt[i] = up(x, y, i);
            dbg(cnt);

            ll earn = cnt[0]*cnt[1] + cnt[2]*cnt[3] - 1;
            if (last) tot -= earn;
            else tot += earn;

            dbg(tot);
            cout << tot << endl;
            // dbg(last);
            can[x][y] = (!last);
        }
    }
    return 0;
}