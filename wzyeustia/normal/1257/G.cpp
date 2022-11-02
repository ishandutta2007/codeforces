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

// Most of code learnt(especially NTT) from codeforces tutorial.

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

    dbg(a.size(), b.size(), sz);

    REP(i, sz) aa[i] = (i<a.size() ? a[i] : 0);
    REP(i, sz) bb[i] = (i<b.size() ? b[i] : 0);
    fft(aa, sz, false), fft(bb, sz, false);

    // cout << "a: ";
    // REP(i, sz) cout << aa[i] << " ";
    // cout << endl;
    
    REP(i, sz) cc[i] = aa[i]*bb[i]%MOD; // NTT/DFT
    fft(cc, sz, true);

    vl ans(cc, cc+sz);
    while (ans.back() == 0) ans.pop_back();
    return ans;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
		ll n; cin >> n;
        map<ll, ll> cnt;
        REP(i, n) {
            ll v; cin >> v;
            cnt[v]++;
        }

        auto cmp = [](const vl& a, const vl& b) {
            return a.size() < b.size();
        };
        multiset<vl, decltype(cmp)> polys(cmp);
        // multiset<vl, cmp0> polys;

        for (auto [v, c] : cnt) {
            polys.em(c+1, 1);
        }

        while (polys.size() > 1) {
            // dbg(polys.size());

            auto it2 = polys.begin();
            auto it1 = it2++;
            auto vec = multiply(*it1, *it2);
            
            // dbg(*it1); dbg(*it2);
            // dbg(vec);
            polys.insert(vec);
            polys.erase(it1);
            polys.erase(it2);
        }

        vl ans = *polys.begin();
        cout << ans[n/2] << endl;
    }
    return 0;
}