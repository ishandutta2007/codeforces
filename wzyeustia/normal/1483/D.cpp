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
#define reset(x, y) memset(x, y, sizeof(x))
#define pb push_back
#define eb emplace_back
#define em emplace
#define mp make_pair
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

#define FILL0(arr) memset(arr, 0, sizeof(arr))

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
#define err(...)
#endif
// end

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;

const ld PI = 3.14159265358979323846;
const ld E = 2.718281828459;
const ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        // Taking solution from Origenes...
        // Core strategy: checking one edge -> find a best triple to check it.
        // brute force: O(N^2)
        // expand each triple to the whole graph.
        // get lim[i][j]: the maximum distance of valid paths from i to j.
        // with lim, we can check each edge in O(N) by finding most suitable point. 
        ll n, m; cin >> n >> m;
        vvl w(n+2, vl(n+2)), floyd(n+2, vl(n+2, 1e18));
        REP(i, m) {
            ll u, v, cost; cin >> u >> v >> cost;
            w[u][v] = w[v][u] = cost;
            floyd[u][v] = floyd[v][u] = cost;
        }
        FOR(i, 1, n) floyd[i][i] = 0;
        FOR(mid, 1, n) FOR(i, 1, n) FOR(j, 1, n) 
            chkmin(floyd[i][j], floyd[i][mid]+floyd[mid][j]);
        
        // FOR(i, 1, n) dbg(i, floyd[i]);
        
        ll q; cin >> q;
        vvl lim(n+2, vl(n+2, -1));
        REP(i, q) {
            ll u, v, l; cin >> u >> v >> l;
            FOR(node, 1, n) {
                chkmax(lim[u][node], l-floyd[node][v]);
                chkmax(lim[v][node], l-floyd[node][u]);
            }
        }

        vvl can(n+2, vl(n+2));
        FOR(node, 1, n) FOR(i, 1, n) FOR(j, 1, n)
            if (w[i][j] && floyd[node][i] + w[i][j] <= lim[node][j]) 
                can[i][j] = can[j][i] = true;
        
        ll ans = 0;
        FOR(i, 1, n) FOR(j, i+1, n) if (can[i][j]) ans++;
        dbg(ans);
        cout << ans << endl;
    }
    return 0;
}