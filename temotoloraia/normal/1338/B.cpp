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

const int N = 1e5 + 5, MOD = 1e9 + 7;

int n;
vector < int > g[N];
int a[N];

void dfs (int k, int p){
    a[k] = 1 - a[p];
    for (int to : g[k])
        if (to != p)
            dfs (to, k);
}

main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int u, v, i = 1; i < n; i++){
        cin >> u >> v;
        g[u].pb (v);
        g[v].pb (u);
    }
    for (int i = 1; i <= n; i++){
        if ((int)g[i].size() == 1){
            int x = g[i][0];
            a[x]++;
        }
    }
    int B = n-1;
    for (int i = 1; i <= n; i++){
        if (a[i] > 1)
            B -= a[i]-1;
        a[i] = 0;
    }
    dfs (1, 0);
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++)
    if ((int)g[i].size() == 1){
        if (a[i] == 0)
            x = 1;
        else
            y = 1;
    }
    cout << 2 * (x + y) - 1 << " " << B << endl;
    return 0;
}