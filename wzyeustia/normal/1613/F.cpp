#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> t3l;
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
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

// Fast Fourier Transform
// NTT/FFT:integer ver
// Most of code from codeforces tutorial.
const ll LOGN = 18;
const ll MX = (1 << LOGN) + 3;
const ll MOD = 998'244'353;
int g = 3; // MOD (???)

ll getInv(ll a, ll p) {
    return (a == 1 ? 1 : (1 - p * getInv(p % a, a)) / a + p);
}

ll fastPow(ll num, ll exp) {
    if (exp == 0) return 1;
    if (exp == 1) return num;
    else {
        ll half = fastPow(num, exp/2);
        if (exp % 2 == 1) 
            return sqr(half)%MOD * num % MOD;
        else 
            return sqr(half)%MOD;
    }
}

ll norm(ll n) {
    while (n>=MOD) n-=MOD;
    while (n<0) n+=MOD;
    return n;
}

vl w[LOGN], rv;
// precalculate w(for mul) and rv(fot bit-reversal permutation)
bool precalced = false;
void precalc() {
    if (precalced) return;
    precalced = true;

    // only for NTT, precalculate multipliers
    ll wb = fastPow(g, (MOD-1) / (1<<LOGN)); // smallest unit root
    REP(st, LOGN) {
        w[st].assign(1<<st, 1);

        ll bw = fastPow(wb, 1 << (LOGN-st-1)); // base unit root 
        ll cw = 1; // current unit root

        REP(k, 1<<st) {
            w[st][k] = cw;
            cw = cw * bw % MOD;
        }
    }

    // bit-reversal permutation
    // same for FFT/NTT
    rv.assign(1<<LOGN, 0);
    FOR(i, 1, rv.size()-1)
        rv[i] = (rv[i>>1] >> 1) | ((i&1) << (LOGN-1));
}

void fft(ll a[MX], int n, bool inv) {
    precalc();

    int ln = 0;
    while ((1 << ln) < n) ++ln;
    assert((1<<ln) == n);
    assert((1<<ln) < MX);

    // bit-reversal permutation
    REP(i, n) {
        int j = rv[i] >> (LOGN - ln);
        if (i < j) swap(a[i], a[j]);
    }

    REP(st, ln) {
        ll len = (1 << st);
        for (int k = 0; k < n; k+=(len<<1)) {
            FOR(pos, k, k+len-1) {
                ll l = a[pos], r = a[pos+len] * w[st][pos-k] %MOD; // NTT/DFT
                a[pos] = norm(l+r), a[pos+len] = norm(l-r);
            }
        }
    }

    if (inv) {
        ll offset = getInv(n, MOD);
        REP(i, n) a[i] = a[i]*offset%MOD; // NTT/DFT
        reverse(a+1, a+n);
    }
}

ll aa[MX], bb[MX], cc[MX];

// multiply 2 polynomial (a & b), 
// return result polynomial c using FFT.
// complexity: O(NlogN), where N = sz(a)+sz(b)
vl multiply(const vl &a, const vl &b) {
    int sz = 1;
    while (sz < a.size()+b.size()) sz<<=1;

    // dbg(a.size(), b.size(), sz);

    REP(i, sz) aa[i] = (i<a.size() ? a[i] : 0);
    REP(i, sz) bb[i] = (i<b.size() ? b[i] : 0);
    fft(aa, sz, false), fft(bb, sz, false);
    
    REP(i, sz) cc[i] = aa[i]*bb[i]%MOD; // NTT/DFT
    fft(cc, sz, true);

    vl ans(cc, cc+sz);
    while (ans.back() == 0) ans.pop_back();
    return ans;
}
// NTT finished

// factor precalculation
const ll FAC_SIZE = 3e5+3;
ll fac[FAC_SIZE], inv[FAC_SIZE];
void initFac(ll sz) {
    fac[0] = 1, inv[0] = 1;
    FOR(i, 1, sz-1) fac[i] = fac[i-1]*i%MOD;
    inv[FAC_SIZE-1] = getInv(fac[FAC_SIZE-1], MOD);
    ROF(i, sz-2, 1) inv[i] = inv[i+1]*(i+1)%MOD;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    initFac(FAC_SIZE);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        int n; cin >> n;
        vl cnt(n+2, 0);
        vvi G(n+2);
        REP(i, n-1) {
            int u, v; cin >> u >> v;
            G[u].eb(v), G[v].eb(u);
        }

        vi vis(n+2, 0); vis[1] = 1;
        queue<ll> que; que.em(1);
        while (!que.empty()) {
            auto u = que.front(); que.pop();
            for (auto v : G[u]) if (!vis[v]) {
                vis[v] = 1, cnt[u]++, que.em(v);
            }
        }

        dbg(cnt);

        multiset<vl> poly;
        FOR(i, 1, n) if (cnt[i]) {
            vl vec(2, 1);
            vec[1] = cnt[i];
            poly.em(vec);
        } 

        while (poly.size() > 1) {
            auto i1 = poly.begin();
            auto v1 = *i1; poly.erase(i1);
            auto i2 = poly.begin();
            auto v2 = *i2; poly.erase(i2);

            vl v0 = multiply(v1, v2);
            poly.em(v0);
        }

        auto vec = *poly.begin();
        dbg(vec);
        ll crt = n, sign = 1, ans = 0;
        for (auto a : vec) {
            ll weight = fac[crt] * a %MOD;
            dbg(weight, sign);
            if (!sign) weight = MOD - weight;
            ans = (ans + weight)%MOD;
            sign = 1 - sign, crt--;
        }

        cout << ans << endl;
    }
    return 0;
}