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

// main idea from IceKnight1093's comment on Codeforces Tutorial
// What an elegant binary lifting solution!
int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
		ll n, m; cin >> n >> m;
        vl a(n); REP(i, n) cin >> a[i];
        sort(all(a));

        ll xum[m+1][20] = {0}, odd[m+1][20] = {0};
        REP(i, n) odd[a[i]][0] ^= 1;
        
        REP(bit, 20) FOR(l, 1, m) {
            ll nxt = l + (1<<bit);
            if (nxt + (1<<bit) > m+1) break;

            xum[l][bit+1] = xum[l][bit] ^ xum[nxt][bit];
            odd[l][bit+1] = odd[l][bit] ^ odd[nxt][bit];
            if (odd[nxt][bit]) xum[l][bit+1] ^= 1<<bit; 
        }

        // REP(bit, 5) {
        //     FOR(l, 1, m) cout << xum[l][bit] << " ";
        //     cout << endl;
        // }
        
        ll q; cin >> q;
        vector<char> vec(q, 'B');
        REP(tt, q) {
            ll l, r; cin >> l >> r; r++;
            ll ans = 0, mask = 0;
            ROF(bit, 19, 0) {
                if (l + (1<<bit) > r) continue;
                
                ans ^= xum[l][bit];
                if (odd[l][bit]) ans ^= mask;
                l += 1<<bit, mask |= 1<<bit;
            }
            dbg(ans);
            if (ans) vec[tt] = 'A';
        }

        dbg(vec);
        for (auto c : vec) cout << c;
        cout << endl;

    }
    return 0;
}