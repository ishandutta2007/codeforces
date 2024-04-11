#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
#define int long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define y1 y122

/*
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")

#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")

#pragma comment(linker, "/STACK: 20000000005")
*/

using namespace std;


const int N = 200005, INF = 1e12;

int n;
int cost[N], H[N];
vector < int > g[N];

int dp[N][3];

void dfs (int k, int p){
    vector < pair < int, pair < int, int > > > V;
    for (int to : g[k]){
        if (to == p)
            continue;
        dfs (to, k);
        int x = dp[to][1], y = dp[to][2];
        if (H[k] < H[to])
            x = INF;
        if (H[k] > H[to])
            y = INF;
        V.pb ({x-y, {x, y}});
    }
    sort (V.begin(), V.end());
    int m = (int)V.size();
    if (m == 0){
        dp[k][0] = 0;
        dp[k][1] = cost[k];
        dp[k][2] = cost[k];
        return;
    }
    for (int i = 0; i < 3; i++)
        dp[k][i] = INF;
    vector < int > A (m+1, 0), B(m+1, 0);
    for (int i = 1; i <= m; i++)
        A[i] = A[i-1] + V[i-1].S.F;
    for (int i = 1; i <= m; i++)
        B[i] = B[i-1] + V[m - i].S.S;
    for (int a = 0; a <= m; a++){
        int b = m - a;
        int sum = A[a] + B[b];
        int rad = max (a, b);
        dp[k][0] = min (dp[k][0], sum + rad * cost[k]);
        if (a >= 1){
            rad = 1 + max (a-1, b);
            dp[k][1] = min (dp[k][1], sum + rad * cost[k]);
        }
        if (b >= 1){
            rad = 1 + max (a, b-1);
            dp[k][2] = min (dp[k][2], sum + rad * cost[k]);
        }
    }
    dp[k][1] = min (dp[k][1], dp[k][0] + cost[k]);
    dp[k][2] = min (dp[k][2], dp[k][0] + cost[k]);
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    //ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf ("%lld", &cost[i]);
    for (int i = 1; i <= n; i++)
        scanf ("%lld", &H[i]);
    for (int u, v, i = 1; i < n; i++){
        scanf ("%lld%lld", &u, &v);
        g[u].pb (v);
        g[v].pb (u);
    }
    dfs (1, 0);
    cout << dp[1][0] << endl;
}