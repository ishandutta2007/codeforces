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

// FILL by byte!!!
#define FILL(arr, num) memset(arr, num, sizeof(arr))
#define ln cout << endl;

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
// end

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;

const ld PI = 3.14159265358979323846;
const ld E = 2.718281828459;
ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

const ll BACKBONE = 0, USED = 1, OTHER = 2;
vvl G, dp;
ll ans = 0;
void dfs(ll u, ll par) {
    ll single[2] = {0};
    ll cnt = G[u].size(); chkmax(ans, cnt);
    if (u != 1) cnt--;

    dp[u][BACKBONE] = cnt, dp[u][USED] = 1;

    for (auto v : G[u]) {
        if (v == par) continue;
        dfs(v, u);

        ll tot1 = single[BACKBONE] + max(dp[v][BACKBONE], dp[v][USED]) - 1;
        ll tot2 = single[USED] + dp[v][BACKBONE];
        chkmax(ans, max(tot1, tot2));

        chkmax(single[BACKBONE], max(dp[v][BACKBONE], dp[v][USED]) + cnt-1+(u!=1));
        chkmax(single[USED], dp[v][BACKBONE] + 1);

        // ll plan1 = mx[BACKBONE] + dp[v][BACKBONE] + 1;
        // ll plan2 = max(mx[BACKBONE], mx[USED]) + max(dp[v][BACKBONE], dp[v][USED]) + cnt-2;
        // if (u != 1) plan2++;
        // chkmax(ans, max(plan1, plan2));

        chkmax(dp[u][BACKBONE], max(dp[v][BACKBONE], dp[v][USED]) + cnt-1);
        chkmax(dp[u][USED], dp[v][BACKBONE] + 1);
    }
    chkmax(ans, max(single[BACKBONE], single[USED]));
    dbg(u, dp[u]);
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        G = vvl(n+2), dp = vvl(n+2, vl(2, 0));
        REP(i, n-1) {
            ll u, v; cin >> u >> v;
            G[u].eb(v), G[v].eb(u);
        }

        dfs(1, 0);
        dbg(ans);
        cout << ans << endl;
    }
    return 0;
}