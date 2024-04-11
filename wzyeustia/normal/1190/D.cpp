#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
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
ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

// BIT
int lowbit(int num) {return num & (-num);}

void init(vl &arr, int n, vl &BIT) {
    FOR(i, 1, n) {
        BIT[i] = arr[i] - arr[i-lowbit(i)];
    }
}

ll query(int k, vl &BIT) {
    ll sum = 0;
    for (int i = k; i > 0; i-=lowbit(i)) {
        sum += BIT[i];
    }
    return sum;
}

void update(int l, int r, ll delta, vl &BIT) {
    for (int i = l; i < BIT.size(); i+=lowbit(i)) {
        BIT[i] += delta;
    }
    for (int i = r+1; i < BIT.size(); i+=lowbit(i)) {
        BIT[i] -= delta;
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
        vector<pll> pa;
        map<ll, ll> cx, cy, sx, sy;
        REP(i, n) {
            ll x, y; cin >> x >> y;
            pa.eb(x, y);
            cx[x]++, cy[y]++;
        }

        ll tag = 0;
        for (auto [v, c] : cx) sx[v] = ++tag;
        tag = 0;
        for (auto [v, c] : cy) sy[v] = ++tag;
        cx.clear(), cy.clear();

        vector<pll> pt(n);
        REP(i, n) {
            auto [x0, y0] = pa[i];
            pt[i] = {sy[y0], sx[x0]};
            cx[sx[x0]]++;
        } sort(all(pt));

        vl BIT(n+3);
        for (auto [v, c] : cx) {
            update(v, n, 1, BIT);
        }

        ll lx = 0, ly = 0, ans = 0;
        for (auto [y, x] : pt) {
            dbg(x, y);
            if (y > ly) lx = 0;

            ll mid = query(x, BIT);
            ll left = 0;
            if (lx > 0) left = query(lx, BIT);
            ll tot = query(n, BIT);
            dbg(mid, left, tot);

            ll earn = (mid-left) * (tot-mid+1);
            dbg(earn);
            ans += earn;

            cx[x]--;
            if (cx[x] == 0) update(x, n, -1, BIT);
            lx = x, ly = y;
        }

        cout << ans << endl;
    }   
    return 0;
}