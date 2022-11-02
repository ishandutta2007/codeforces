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
ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

vl F, sz;
ll find(ll k) {
    return F[k] == k? k : F[k] = find(F[k]);
}

void mUnion(ll s, ll t) {
    s = find(s), t = find(t);
    if (s != t) {
        sz[t] += sz[s];
        F[s] = t;
    }
} 

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll n, m; cin >> n >> m;
        F = vl(2*n + 5); FOR(i, 1, 2*n+4) F[i] = i;
        sz = vl(2*n+3, 0); for (int i = 1; i <= 2*n+1; i+=2) sz[i] = 1;

        bool can = true;
        REP(tt, m) {
            ll u, v; cin >> u >> v;
            string s; cin >> s;

            ll s1 = find(2*u), s2 = find(2*u+1);
            ll t1 = find(2*v), t2 = find(2*v+1);
            // if (s1 == s2) break;
            // if (t1 == t2) break;

            if (s[0] == 'i') {
                mUnion(s1, t2);
                mUnion(s2, t1);
            } else {
                mUnion(s1, t1);
                mUnion(s2, t2);
            }

            if (find(2*u) == find(2*u+1)) can = false;
            if (find(2*v) == find(2*v+1)) can = false;
        }

        ll ans = 0;
        set<ll> done;
        FOR(i, 1, n) {
            ll f1 = find(2*i), f2 = find(2*i+1);
            dbg(f1, f2);
            dbg(sz[f1], sz[f2]);
            ll earn = 0;
            if (!done.count(f1)) chkmax(earn, sz[f1]);
            if (!done.count(f2)) chkmax(earn, sz[f2]);
            done.em(f1), done.em(f2);

            ans += earn;
        }

        if (!can) ans = -1;
        dbg(can, ans);
        cout << ans << endl;
    }
    return 0;
}