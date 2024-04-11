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
ll MOD = 1e9+7;
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

void update(int l, int r, ll delta, vl &BIT) {
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

    const ll IN = 0, CHECK = 1, OUT = 2;

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, m; cin >> n >> m;
        ll p[n], s[n], b[n];
        REP(i, n) cin >> p[i]; REP(i, n) cin >> s[i]; REP(i, n) cin >> b[i]; 
        ll k[m], q[m]; vl ans(m);
        REP(i, m) cin >> k[i]; REP(i, m) cin >> q[i];

        vl v1, v2; REP(i, n) v1.eb(b[i]-p[i]), v2.eb(b[i]+p[i]);
        REP(i, m) v1.eb(q[i]-k[i]), v2.eb(q[i]+k[i]);
        sort(all(v1)), sort(all(v2));
        dbg(v1); dbg(v2);

        vector<t3l> seq;
        REP(i, n) seq.eb(p[i], IN, i), seq.eb(s[i], OUT, i);
        REP(i, m) seq.eb(k[i], CHECK, i); 
        sort(all(seq));
    
        ll tot = 0;
        vl b1(n+m+2, 0), b2(n+m+2, 0);
        for (auto [pos, type, idx] : seq) {
            // dbg(pos, type, idx);
            if (type == IN) {
                ll p1 = lb_pos(v1, b[idx]-p[idx])+1, p2 = lb_pos(v2, b[idx]+p[idx])+1;
                dbg(p1, p2);
                update(p1, n+m+1, 1, b1), update(p2, n+m+1, 1, b2); tot++;
            } else if (type == OUT) {
                ll p1 = lb_pos(v1, b[idx]-p[idx])+1, p2 = lb_pos(v2, b[idx]+p[idx])+1;
                update(p1, n+m+1, -1, b1), update(p2, n+m+1, -1, b2); tot--;
            } else {
                ll p1 = lb_pos(v1, q[idx]-pos), p2 = lb_pos(v2, q[idx]+pos)+1;
                ll k1 = query(p1, b1), k2 = tot-query(p2, b2);
                // k1 : smaller, k2: greater
                ans[idx] = tot - k1 - k2;
                dbg(q[idx], pos, p1, p2);
                dbg(tot, k1, k2);
            }
        }

        dbg(ans);
        REP(i, m) cout << ans[i] << " ";
        cout << endl; 
    }   
    return 0;
}