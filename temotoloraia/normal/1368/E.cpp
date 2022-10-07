#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
//#define int long long
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

const int N = 200005;

int n, m;
vector < int > g[N];
int F[N];


void solve () {
    scanf ("%d %d", &n, &m);
    while (m--){
        int u, v;
        scanf ("%d %d", &u, &v);
        g[u].pb (v);
    }
    for (int i = 1; i <= n; i++){
        if (F[i] == 0)
            F[i] = 1;
        if (F[i] < 3)
            for (int x : g[i])
                F[x] = max (F[x], F[i]+1);
    }
    int num = 0;
    for (int i = 1; i <= n; i++)
        if (F[i] == 3)
            num++;
    //assert (num <= n*4/7);
    printf ("%d\n", num);
    for (int i = 1; i <= n; i++)
        if (F[i] == 3)
            printf ("%d ", i);
    printf ("\n");
    for (int i = 1; i <= n; i++){
        F[i] = 0;
        g[i].clear();
    }
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    //ios_base::sync_with_stdio(0);
    int T=1;
    cin >> T;
    while (T--)
        solve ();
}