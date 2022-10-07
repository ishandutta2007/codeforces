#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define y1 y122
 
 
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
/*
#pragma comment(linker, "/STACK: 20000000005")
*/
using namespace std;
 
const int MAXN = 200005;
const ll INF = 1e18;
 
int n, m, s;
 
map < pair < int, int >, bool > M;
 
int P[MAXN];
 
vector < int > g[MAXN];
 
vector < int > br[MAXN], cyc[MAXN], BR[MAXN];
 
 
 
int T;
int in[MAXN];
int up[MAXN];
bool F[MAXN];
 
void dfs(int v, int p) {
    F[v] = true;
    in[v] = up[v] = ++T;
    for (int to : g[v]) {
        if (to == p) continue;
        if (F[to]) {
            up[v] = min(up[v], in[to]);
            cyc[v].pb (to);
            cyc[to].pb (v);
        } else {
            dfs(to, v);
            up[v] = min(up[v], up[to]);
            if (up[to] > in[v]){
                br[v].pb (to);
                br[to].pb (v);
            }
            else {
                cyc[v].pb (to);
                cyc[to].pb (v);
            }
        }
    }
}
 
void go (int k){
    for (int to : cyc[k]){
        if (P[to])
            continue;
        P[to] = P[k];
        go (to);
    }
}
 
ll W[MAXN];
 
ll S[MAXN];
 
ll DP[MAXN], dp[MAXN];
 
 
void DFS (int k, int p){
    ll sum = 0, val;
    for (int to : BR[k]){
        if (to == p)
            continue;
        DFS (to, k);
        if (F[to])
            F[k] = 1;
        sum += dp[to];
    }
    DP[k] = sum;
    dp[k] = sum;
    for (int to : BR[k]){
        if (to == p)
            continue;
        val = sum - dp[to] + DP[to];
        DP[k] = max (DP[k], val);
    }
    DP[k] += S[k];
    dp[k] += S[k];
    if (F[k] == 0 && sum == 0)
        dp[k] = 0;
}
 
 
main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    //ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        scanf ("%lld", &W[i]);
    while (m--){
        int u, v;
        scanf ("%d %d", &u, &v);
        g[u].pb (v);
        g[v].pb (u);
    }
    cin >> s;
    dfs (1, 0);
    for (int i = 1; i <= n; i++){
        if (P[i])
            continue;
        P[i] = i;
        go (i);
    }
    for (int i = 1; i <= n; i++)
        F[i] = 0;
    for (int i = 1; i <= n; i++)
        if (P[i] != i)
            F[P[i]] = 1;
    for (int i = 1; i <= n; i++)
        S[P[i]] += W[i];
    for (int u = 1; u <= n; u++)
    for (int v : br[u]){
        int x = P[u], y = P[v];
        if (M[{x, y}])
            continue;
        M[{x, y}] = 1;
        M[{y, x}] = 1;
        BR[x].pb (y);
        BR[y].pb (x);
    }
    s = P[s];
    DFS (s, 0);
    cout << DP[s] << endl;
    return 0;
}