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

const int N = 5e5 + 5;

int n, K;
ll DP[N], dp[N];
vector < ll > g[N], G[N];

void dfs (int k, int p){
    ll sum = 0;
    vector < ll > V;
    int to;
    ll w, dif;
    for (int i = 0; i < (int)g[k].size(); i++){
        to = g[k][i];
        w = G[k][i];
        if (to == p)
            continue;
        dfs (to, k);
    }
    for (int i = 0; i < (int)g[k].size(); i++){
        to = g[k][i];
        w = G[k][i];
        if (to == p)
            continue;
        sum += DP[to];
        dif = w + dp[to] - DP[to];
        if (dif > 0)
            V.pb (dif);
    }
    DP[k] = sum;
    dp[k] = sum;
    sort (V.begin(), V.end());
    reverse (V.begin(), V.end());
    int nn = (int)V.size();
    for (int i = 0; i < K - 1 && i < nn; i++)
        dp[k] += V[i];
    for (int i = 0; i < K && i < nn; i++)
        DP[k] += V[i];
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    //ios_base::sync_with_stdio(0);
    int Q;
    cin >> Q;
    while (Q--){
        scanf ("%d %d", &n, &K);
        for (int i = 1; i <= n; i++){
            DP[i] = 0;
            dp[i] = 0;
            g[i].clear();
            G[i].clear();
        }
        for (int i = 1; i < n; i++){
            int u, v;
            ll w;
            scanf ("%d %d %lld", &u, &v, &w);
            g[u].pb (v);
            G[u].pb (w);
            g[v].pb (u);
            G[v].pb (w);
        }
        dfs (1, 0);
        printf ("%lld\n", DP[1]);
    }
    return 0;
}