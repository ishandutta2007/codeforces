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
vl mx;
ll n, k;

void dfs(ll node, ll par) {
    dp[node][0] = 1;
    for (auto child : edges[node]) {
        if (child == par) continue;
        
        dfs(child, node);

        ll temp = mx[node];
        vl nxt(k+2, 0);
        FOR(h1, 0, temp) FOR(h2, 0, mx[child]) {
            // first cut it...
            nxt[h1] += M(dp[node][h1] * dp[child][h2]); nxt[h1] %= MOD;
            // if not cut...
            if (h1 + h2+1 <= k) { // we should be able to cut
                nxt[max(h1, h2+1)] += M(dp[node][h1] * dp[child][h2]); 
                nxt[max(h1, h2+1)] %= MOD;
                chkmax(mx[node], h2+1);    
            }
        }

        FOR(i, 0, mx[node]) dp[node][i] = nxt[i];
    }
    dbg(node); dbg(dp[node]);
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        // After reading tutorial...
        cin >> n >> k;
        edges = vvl(n+2);
        REP(i, n-1) {
            ll u, v; cin >> u >> v;
            edges[u].eb(v); edges[v].eb(u);
        }

        dp = vvl(n+2, vl(k+2));
        mx = vl(n+2, 0);
        dfs(1, -1);

        ll ans = 0; REP(i, k+1) ans += dp[1][i], ans %= MOD;
        dbg(mx);
        dbg(ans);
        cout << ans << endl;
    }
    return 0;
}