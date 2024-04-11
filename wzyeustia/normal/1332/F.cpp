#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define FOR(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (ll (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define em emplace
#define mp make_pair
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

#define ln cout << endl;

// Can I use this?
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m " << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
// end

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;

const ld PI = 3.14159265358979323846;
const ld E = 2.718281828459;
const ll SIZE = 2e6+3; 

const ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

vvl edges, dp;
ll n;

const ll NO_USE = 0, USE_SAFE = 1, USE_UNSAFE = 2;

void dfs(ll node, ll par) {
    dp[node][0] = dp[node][1] = dp[node][2] = 1;
    for (auto child : edges[node]) {
        if (child == par) continue;
        
        dfs(child, node);

        dp[node][0] *= M(2*(dp[child][0] + dp[child][1]) + dp[child][2]);
        dp[node][1] *= M(2*dp[child][0] + dp[child][1]);
        dp[node][2] *= M(dp[child][0] + dp[child][1]);

        dp[node][0] %= MOD, dp[node][1] %= MOD, dp[node][2] %= MOD;
    }

    dp[node][1] -= dp[node][2]; dp[node][1] = M(dp[node][1]);
    dbg(node); dbg(dp[node]);
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        cin >> n;
        edges = vvl(n+2);
        REP(i, n-1) {
            ll u, v; cin >> u >> v;
            edges[u].eb(v); edges[v].eb(u);
        }

        dp = vvl(n+2, vl(3, 0));
        dfs(1, -1);

        ll ans = dp[1][0] + dp[1][1];
        dbg(ans);
        cout << M(ans-1) << endl;
        // ll ans = 0; REP(i, k+1) ans += dp[1][i], ans %= MOD;
        // dbg(mx); dbg(ans);
        // cout << ans << endl;
    }
    return 0;
}