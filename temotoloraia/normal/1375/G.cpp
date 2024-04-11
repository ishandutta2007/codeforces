#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
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

const int N = 300005;

int n;
int a[N], b[N];
int A[N], B[N];
vector < int > g[N];

void dfs (int k, int p){
    a[k] = 1;
    for (int to : g[k]){
        if (to == p)
            continue;
        dfs (to, k);
        a[k] += b[to];
        b[k] += a[to];
    }
}


main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int u, v, i = 1; i < n; i++){
        cin >> u >> v;
        g[u].pb (v);
        g[v].pb (u);
    }
    dfs (1, 0);
    cout << min (a[1], b[1]) - 1 << endl;
}