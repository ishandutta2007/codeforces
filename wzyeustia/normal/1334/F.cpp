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

// BIT
vl BIT;
int lowbit(int num) {return num & (-num);}

void init(vl &arr, int n) {
    FOR(i, 1, n) {
        BIT[i] = arr[i] - arr[i-lowbit(i)];
    }
}

ll query(int k) {
    ll sum = 0;
    for (int i = k; i > 0; i-=lowbit(i)) {
        sum += BIT[i];
    }
    return sum;
}

void update(int l, int r, ll delta) {
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
        vl a(n); REP(i, n) cin >> a[i];
        vl p(n); REP(i, n) cin >> p[i];

        ll m; cin >> m;
        vl b(m+1); FOR(i, 1, m) cin >> b[i];

        BIT = vl(m+5, 1e17); BIT[1] = 0;
        REP(i, n) {
            ll pos = lower_bound(all(b), a[i]) - b.begin();
            update(pos+1, m+1, min(0ll, p[i]));
            if (b[pos] == a[i]) {
                ll val = query(pos);
                ll last = query(pos+1);
                if (val < last) update(pos+1, pos+1, val-last);
            }
            update(1, pos, p[i]);

            // cout << "stat: ";
            // FOR(tt, 1, m+1) cout << query(tt) << " ";
            // cout << endl;
        }

        ll ans = query(m+1);
        if (ans <= 1e16) {
            cout << "YES" << endl;
            cout << ans << endl;
        } else cout << "NO" << endl;
    }
    return 0;
}