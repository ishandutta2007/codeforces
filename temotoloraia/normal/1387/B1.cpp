#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll __int128
//#define ll long long
#define int long long
//#define int __int128
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


const int N = 200005, INF = 1e11;

int n;
vector < int > g[N];
vector < pair < int, int > > V[N];
int DP[N], dp[N];
int ans[N];

void dfs (int k, int p){
    int sum = 0;
    DP[k] = dp[k] = INF;
    for (int to : g[k]){
        if (to == p)
            continue;
        dfs (to, k);
        sum += dp[to];
        V[k].pb ({DP[to] - dp[to], to});
    }
    sort (V[k].begin(), V[k].end());
    DP[k] = min (DP[k], sum);
    for (int i = 0; i < V[k].size(); i++){
        sum += V[k][i].F;
        //if (i % 2 == 0 || i >= 3)
            dp[k] = min (dp[k], i*2 + 2 + sum);
        if (i % 2 == 1 || i >= 2)
            DP[k] = min (DP[k], i*2 + 2 + sum);
    }
    DP[k] = min (DP[k], dp[k]);
}

void go (int k, int p, int T){
    int sum = 0;
    for (int to : g[k])
        if (to != p)
            sum += dp[to];
    if (T == 1 && DP[k] == dp[k])
        T = 0;
    if (T == 0){
        for (int i = 0; i < V[k].size(); i++){
            sum += V[k][i].F;
            if (dp[k] != i*2 + 2 + sum)
                continue;
            for (int j = 0; j < V[k].size(); j++){
                if (j <= i)
                    go (V[k][j].S, k, 1);
                else
                    go (V[k][j].S, k, 0);
            }
            ans[k] = ans[V[k][0].S];
            for (int j = 0; j < i; j++)
                ans[V[k][j].S] = ans[V[k][j+1].S];
            ans[V[k][i].S] = k;
            return;
        }
    }
    else {
        if (DP[k] == sum){
            for (int to : g[k])
                if (to != p)
                    go (to, k, 0);
            return;
        }
        for (int i = 0; i < V[k].size(); i++){
            sum += V[k][i].F;
            if (i == 0)
                continue;
            if (DP[k] != i*2 + 2 + sum)
                continue;
            for (int j = 0; j < V[k].size(); j++){
                if (j <= i)
                    go (V[k][j].S, k, 1);
                else
                    go (V[k][j].S, k, 0);
            }
            int las = ans[V[k][0].S];
            for (int j = 0; j < i; j++){
                ans[V[k][j].S] = ans[V[k][j+1].S];
            }
            ans[V[k][i].S] = las;
            return;
        }
    }
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        ans[i] = i;
    for (int u, v, i = 1; i < n; i++){
        cin >> u >> v;
        g[u].pb (v);
        g[v].pb (u);
    }
    dfs (1, 0);
    cout << dp[1] << endl;
    go (1, 0, 0);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}