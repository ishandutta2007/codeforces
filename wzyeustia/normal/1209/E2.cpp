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


int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    int T = 1;
    cin >> T;   
    REP(I, T) {
        ll n, m; cin >> n >> m;
        vl mx(m);
        ll a[n][m]; REP(i, n) REP(j, m) {
            cin >> a[i][j];
            chkmax(mx[j], a[i][j]);
        }

        vector<pll> pa;
        REP(i, m) pa.eb(mx[i], i);
        sort(all(pa), greater<pll>());

        ll sz = min(n, m), MASK = (1ll << n);
        vl col[sz];
        ll sum[sz][MASK]; FILL(sum, 0);
        REP(p, sz) {
            auto [_, j] = pa[p];
            REP(i, n) col[p].eb(a[i][j]);

            dbg(col[p]);
            REP(mask, MASK) {
                REP(offset, n) {
                    ll crt = 0;
                    REP(bit, n) {
                        ll i = (bit+offset)%n;
                        if ((1<<bit) & mask) crt += col[p][i]; 
                    }
                    chkmax(sum[p][mask], crt);
                }
            }
        }

        ll dp[sz+1][MASK]; FILL(dp, 0);
        REP(i, sz) REP(mask, MASK) {
            chkmax(dp[i+1][mask], sum[i][mask]);
            for (ll sub = mask; sub>0; sub = (sub-1)&mask) {
                ll earn = dp[i][sub] + sum[i][mask ^ sub];
                chkmax(dp[i+1][mask], earn);
            }
        }

        ll ans = dp[sz][MASK-1];
        cout << ans << endl;
    }
    return 0;
}