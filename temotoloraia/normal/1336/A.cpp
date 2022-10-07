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
#define int long long

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

const int N = 200005, MOD = 1e9 + 7;

int n;
vector < int > g[N];
int S[N], D[N];

void dfs (int k, int p){
    S[k] = 1;
    D[k] = D[p] + 1;
    for (int to : g[k]){
        if (to == p)
            continue;
        dfs (to, k);
        S[k] += S[to];
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    int k;
    cin >> n >> k;
    for (int u, v, i = 1; i < n; i++){
        cin >> u >> v;
        g[u].pb (v);
        g[v].pb (u);
    }
    dfs (1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++){
        S[i] -= D[i];
    }
    sort (S + 1, S + n + 1);
    for (int i = k + 1; i <= n; i++)
        ans += S[i];
    cout << ans << endl;
    return 0;
}