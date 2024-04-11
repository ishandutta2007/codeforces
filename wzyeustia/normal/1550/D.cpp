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

mt19937_64 rng((unsigned ll) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<ll>(a, b)(rng)

ll getInv(ll a, ll p) {
 return (a == 1 ? 1 : (1 - p * getInv(p % a, a)) / a + p);
}

// factor precalculation
const ll FAC_SIZE = 2e5+3;
ll fac[FAC_SIZE], inv[FAC_SIZE];
void initFac(ll sz) {
    fac[0] = 1, inv[0] = 1;
    FOR(i, 1, sz-1) fac[i] = fac[i-1]*i%MOD;
    inv[FAC_SIZE-1] = getInv(fac[FAC_SIZE-1], MOD);
    ROF(i, sz-2, 1) inv[i] = inv[i+1]*(i+1)%MOD;
}
// combinatorics
ll comb(ll x, ll y) { // select y from x
    if (x < y) return 0;
    return fac[x] * inv[y]%MOD * inv[x-y]%MOD;
}

ll calc(ll n, ll lo, ll hi) {
    ll earn, free = n-lo-hi; 
    if (n%2 == 0) {
        earn = comb(free, n/2 - lo);
    } else {
        earn = comb(free, n/2 - lo) + comb(free, n/2+1 - lo);
    }
    if (lo > (n+1)/2 || hi > (n+1)/2) earn = 0;
    return earn%MOD;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    initFac(FAC_SIZE);

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll n, l, r; cin >> n >> l >> r;
        ll mx = 2e9;
        FOR(i, 1, n) {
            ll lim1 = i-l, lim2 = r-i;
            chkmin(mx, max(lim1, lim2));
        }

        const ll FREE = 0, LO = 1, HI = 2;

        ll lo = 0, hi = 0;
        vl stat(n+2);
        vector<pll> seq;
        FOR(i, 1, n) {
            ll lim1 = i-l, lim2 = r-i;
            if (lim1 >= mx && lim2 >= mx) stat[i] = FREE;
            if (lim1 >= mx && lim2 < mx) {
                stat[i] = LO, lo++;
                seq.eb(lim2, i);
            }
            if (lim1 < mx && lim2 >= mx) {
                stat[i] = HI, hi++;
                seq.eb(lim1, i);
            }
        }
        dbg(mx, lo, hi);

        sort(all(seq), greater<pll>());
        ll last = mx, ans = 0;
        for (auto [lim, idx] : seq) {
            ll delta = last - lim;
            last = lim;

            // ll earn, free = n-lo-hi; 
            // if (n%2 == 0) {
            //     earn = comb(free, n/2 - lo);
            // } else {
            //     earn = comb(free, n/2 - lo) + comb(free, n/2+1 - lo);
            // }
            // if (lo > (n+1)/2 || hi > (n+1)/2) earn = 0;

            ll earn = calc(n, lo, hi);
            dbg(lim, idx, earn);
            ans = (ans + earn * delta %MOD)%MOD;

            if (stat[idx] == LO) lo--;
            else hi--;
        }

        ans = (ans + last * calc(n, lo, hi)%MOD)%MOD;

        cout << ans << endl;
    }
    return 0;
}