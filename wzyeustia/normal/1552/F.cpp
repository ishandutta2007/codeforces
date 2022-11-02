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


int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    const ll POINT = 0, TO = 1;

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        vl stat(n+1), at(n+1), to(n+1);

        vector<t3l> seq;
        FOR(i, 1, n) {
            cin >> at[i] >> to[i] >> stat[i]; 
            seq.eb(at[i], POINT, i);
            seq.eb(to[i], TO, i);
        } sort(all(seq));
        at[0] = stat[0] = to[0] = 0;

        ll last = 0;
        vl come(n+1), dp(n+1);
        for (auto [pos, type, idx] : seq) {
            // dbg(pos, type, idx);
            if (type == TO) {
                come[idx] = last;
            } else {
                ll dist = at[idx] - at[idx-1];
                ll delta = to[idx] - at[come[idx]];

                dp[idx] = (dp[last] + dist)%MOD;
                dbg(dist, delta);
                
                ll back = come[idx];
                dp[idx] = (dp[idx] + MOD - delta )%MOD;

                // dbg(last, back, );
                dp[idx] = (dp[idx] + dp[last] - dp[back] + MOD)%MOD;

                dp[idx] = (dp[idx] + dist)%MOD;
                dbg(idx, dp[idx]);

                last = idx;
            }
        }

        ll ans = 0, pre = 0;
        FOR(i, 1, n) {
            if (stat[i] == 1) {
                ans = (ans + dp[i] - dp[i-1] + at[i-1]-at[pre] + 5*MOD)%MOD;
                pre = i;
            }
            dbg(ans);
        }

        ans = (ans + at[n]+1 - at[pre] + MOD)%MOD;
        cout << ans << endl;
    }
    return 0;
}