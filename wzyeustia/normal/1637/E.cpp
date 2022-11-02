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


int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    const ll KK = 1e9+2;

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll n, m; cin >> n >> m;
        map<ll, ll> cnt;
        vl a(n); REP(i, n) {
            cin >> a[i];
            cnt[a[i]]++;
        }

        unordered_map<ll, bool> ban;
        REP(i, m) {
            ll x, y; cin >> x >> y;
            ban[x*KK+y] = 1;
        } 

        unordered_map<ll, vl> vec;
        for (auto [val, c] : cnt) {
            vec[c].eb(val);
        }
        for (auto& [c, v] : vec) sort(all(v), greater<ll>());

        ll ans = 0;
        for (auto& [c1, v1] : vec) {
            for (auto& [c2, v2] : vec) if (c1 <= c2) {
                ll s1 = v1.size(), s2 = v2.size();
                queue<pll> que; que.em(0, 0);
                while (!que.empty()) {
                    auto [u, v] = que.front(); que.pop();
                    ll x = v1[u], y = v2[v];
                    ll earn = (x+y)*(c1+c2);
                    if (x>y) swap(x, y);

                    if (x!=y && !ban[x*KK+y]) {
                        chkmax(ans, (x+y)*(c1+c2));
                    } else {
                        if (v==0 && u+1<s1) que.em(u+1, v);
                        if (v+1<s2) que.em(u, v+1);  
                    }
                }
            }
        }

        dbg(ans);
        cout << ans << endl;
    }   
    return 0;
}