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

vl F;
ll find(ll k) {
    return F[k] == k? k : F[k] = find(F[k]);
}

vl lo, hi;
void comb(ll x, ll y) {
    ll fx = find(x), fy = find(y);
    if (fx == fy) return;

    F[fy] = fx;
    chkmin(lo[fx], lo[fy]), chkmax(hi[fx], hi[fy]);
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, m; cin >> n >> m;
        F = vl(n+2), lo = vl(n+2), hi = vl(n+2); 
        FOR(i, 1, n) F[i] = lo[i] = hi[i] = i;

        REP(i, m) {
            ll u, v; cin >> u >> v;
            comb(u, v);
        }

        const ll IN = 0, OUT = 1;
        set<ll> se;
        vector<t3l> seq;
        FOR(i, 1, n) {
            ll fa = find(i);
            if (!se.count(fa)) {
                seq.eb(lo[fa], fa, IN);
                se.em(fa);
                // seq.eb(hi[fa], fa, OUT);
            }
        } sort(all(seq));

        ll lim = -1, ans = 0;
        for (auto [pos, idx, type] : seq) {
            if (pos < lim) {
                dbg(pos, idx);
                ans++;
            }
            chkmax(lim, hi[idx]);
        }

        dbg(ans);
        cout << ans << endl;
        
    }
    return 0;
}