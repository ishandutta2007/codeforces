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
const ld EPS = 1e-8;
ll MOD = 998'244'353;
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

void update(int pos, ll delta, vl &BIT) {
    for (int i = pos; i < BIT.size(); i+=lowbit(i)) {
        BIT[i] += delta;
    }
}


int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        vl a(n); REP(i, n) cin >> a[i];

        vl BIT(n+3, 0);
        vector<pll> seq;

        ll sign = 1;
        vl pre(n+1, 0); FOR(i, 1, n) {
            pre[i] = pre[i-1] + a[i-1] * sign;
            sign = -sign;
            if (i%2 == 1) update(i, 1, BIT);
            seq.eb(pre[i], i+1);
        } seq.eb(pre[0], 1ll);

        sort(all(seq));

        ll ans = 0;
        ll lastVal = -1e10, lastPos = -1, cnt = 0;
        for (auto [val, idx] : seq) {
            // dbg(val, idx);
            if (lastVal == val) {
                // dbg(lastPos, idx);
                ll invalid = query(idx-1, BIT) - query(lastPos, BIT);
                if (invalid) cnt = 0;
                else ans += (++cnt);
            } else cnt = 0;
            
            lastVal = val, lastPos = idx;
            if (idx % 2 == 1) {
                update(idx, -1, BIT);
            } else update(idx, 1, BIT);
        }

        dbg(ans);
        cout << ans << endl;

    }
    return 0;
}