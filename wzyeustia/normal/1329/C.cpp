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
ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

ll h, g;
vl fix, a, dep;
void check(ll u) {
    ll l = u<<1, r = l|1;
    if (a[l] == a[r] && a[l] == 0) {
        if (dep[u] <= g) fix[u] = 1;
    }
    if (a[l] > a[r] && fix[l]) fix[u] = 1;
    if (a[l] < a[r] && fix[r]) fix[u] = 1;
}

void remove(ll u) {
    ll l = u<<1, r = l|1;
    if (a[l] == a[r] && a[l] == 0) {
        a[u] = 0;
        if (dep[u] <= g) fix[u] = 1;
        return;
    }

    if (a[l] > a[r]) {
        a[u] = a[l];
        remove(l);
    } else {
        a[u] = a[r];
        remove(r);
    }
    check(u);
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
		cin >> h >> g;
        ll sz = 1 << h, end = 1 << g;
        ll tot = 0;
        a = vl(sz*2, 0); FOR(i, 1, sz-1) {
            cin >> a[i];
            tot += a[i]; 
        }
        dep = vl(sz*2, 0); FOR(i, 1, 2*sz-1) dep[i] = dep[i/2]+1;
        dbg(dep);
        
        fix = vl(sz*2, 0); fix[0] = 1;
        
        vl seq;
        ll crt = 1;
        while (true) {
            while (crt < end && fix[crt]) crt++;
            if (crt == end) break;

            seq.eb(crt), tot -= a[crt];
            remove(crt);
        }
        // REP(tt, sz-end) {
        //     while (fix[crt]) {
        //         ll l = crt<<1, r = l|1;
        //         if (a[l] < a[r]) crt = l;
        //         else crt = r;
        //     }

        //     seq.eb(crt);
        //     tot -= a[crt], remove(crt);

        //     dbg(a); dbg(fix);
        // }

        cout << tot << endl;
        for (auto p : seq) cout << p << " ";
        cout << endl;
    }
    return 0;
}