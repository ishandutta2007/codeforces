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
ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

const ll K = 1e8;

ll n, m; 
vl lo, hi, c;
vvl seg;
unordered_map<ll, ll> val;

ll solve(ll l, ll r) {
    if (val[l*K+r]) return val[l*K+r];
    if (l>r) return 1; // ???

    ll mx = n+1;
    FOR(i, 1, n) if (l <= lo[i] && hi[i] <= r) {
        mx = i; break;
    }
    dbg(l, r, mx);
    dbg(seg[mx]);

    ll sz = seg[mx].size(), tot = 1;
    REP(i, sz-1) {
        tot = tot * solve(seg[mx][i]+1, seg[mx][i+1]-1)%MOD;
    }

    ll left = lo[mx], right = hi[mx], l0 = left-1, r0 = right+1;
    dbg(left, right, tot);

    ll lAns = solve(l, l0), rAns = solve(r0, r);
    while (left != l) {
        ll cand = c[left-1];
        left = lo[cand];
        lAns = (lAns + solve(left, l0) * solve(l, left-1))%MOD;
    }
    while (right != r) {
        ll cand = c[right+1];
        right = hi[cand];
        rAns = (rAns + solve(r0, right) * solve(right+1, r))%MOD;
    }

    tot = tot * lAns%MOD * rAns%MOD;
    val[l*K+r] = tot;
    dbg(l, r, tot);
    return tot;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        cin >> n >> m;
        lo = vl(n+1, m+2), hi = vl(n+1, 0);
        seg = vvl(n+1);
        c = vl(m+2); FOR(i, 1, m) {
            cin >> c[i];
            chkmin(lo[c[i]], i);
            chkmax(hi[c[i]], i);
            seg[c[i]].eb(i);
        }

        dbg(lo); dbg(hi);

        cout << solve(1, m) << endl;
    }   
    return 0;
}