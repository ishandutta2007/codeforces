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
// ll MOD = 998'244'353;
// ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

// Fast Fourier Transform
// NTT/FFT:integer ver
// Most of code from codeforces tutorial.
const ll LOGN = 20;
const ll MX = (1 << LOGN) + 3;
const ll MOD = 998'244'353;
int g = 3; // MOD (???)

// should use get_minimum_primitive_root(MOD) to get g.
// make sure g exists(MOD in {2, 4, p^k, 2 * p^k}, where p is an odd prime);
// int get_minimum_primitive_root(int m)
// {
//     int phiM = phi(m); // euler function
//     for (int i = 1;; ++i)
//     {
//         if (__gcd(i, m) != 1)
//             continue;
//         auto factors = get_factors(phiM); // decompose
//         bool ok = true;
//         for (auto e : factors)
//             if (e != phiM && fastPow(i, e) == 1) // make sure MOD is what we want to get g!
//             {
//                 ok = false;
//                 break;
//             }
//         if (ok)
//             return i;
//     }
// }

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

    dbg(a.size(), b.size(), sz);

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
const ll FAC_SIZE = 1e6+3;
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

vl get1(ll n) {
    vl ret(n+1);
    ll offset = 1;
    FOR(i, 0, n) {
        ret[i] = comb(n, i) * offset %MOD;
        offset = (offset << 1)%MOD;
    }
    return ret;
}

vl get2(ll n) {
    vl ret((n<<1)+1);
    FOR(i, 0, 2*n) {
        ret[i] = comb(2*n, i);
    }
    return ret;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    const ll MX = 3e5;
    initFac(FAC_SIZE);

    int T = 1;
    // cin >> T;
    REP(I, T) {
		ll n, k; cin >> n >> k;
        vl cnt(MX+2, 0);
        REP(i, n) {
            ll len; cin >> len;
            cnt[len]++;
        }

        vl chk(MX+2); REP(i, k) {
            ll red; cin >> red;
            chk[red] = 1;
        }

        ll q; cin >> q;
        vl peri(q), ans(q, 0); REP(i, q) {
            cin >> peri[i]; peri[i]>>=1;
        }

        ll idx = 0, one = 0, two = 0;
        FOR(len, 1, MX) {
            if (chk[len]) {
                vl v1 = get1(one), v2 = get2(two);
                dbg(one, two);
                dbg(v1); dbg(v2);

                vl vec = multiply(v1, v2);
                REP(i, q) {
                    ll val = peri[i] - len - 1;
                    if (val < 0 || val >= vec.size()) continue;
                    ans[i] = (ans[i] + vec[val])%MOD;
                }

                idx++;
            }

            if (cnt[len] == 1) one++;
            if (cnt[len] >= 2) two++; 
        }

        dbg(ans);
        REP(i, q) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}