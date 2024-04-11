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
 
const int N = 2005, M = 4105;
 
int n, m, nn;
int a[15][N];
int dp[M];
int mas[M];
 
int par[15][M];
 
int PO[N];
 
main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    //ios_base::sync_with_stdio(0);
    PO[0] = 1;
    for (int i = 1; i <= 30; i++)
        PO[i] = PO[i - 1] * 2;
    for (n = 1; n <= 12; n++){
        nn = (1 << n);
        for (int i = 0; i < nn; i++){
            par[n][i] = i;
            int x = i;
            for (int j = 0; j < n; j++){
                x <<= 1;
                if (x >= nn){
                    x -= nn;
                    x++;
                }
                par[n][i] = min (par[n][i], x);
            }
        }
    }
    int test;
    cin >> test;
    while (test--){
        cin >> n >> m;
        nn = (1 << n);
        for (int i = 0; i < nn; i++)
            dp[i] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 1; j <= m; j++)
                scanf ("%d", &a[i][j]);
        int x, y, mask;
        for (int j = 1; j <= m; j++){
            for (int i = 0; i < n; i++){
                mask = nn - 1 - PO[i];
                for (x = mask; x ; x = (x - 1) & mask){
                    if ((x & PO[i]) > 0)
                        continue;
                    y = x + PO[i];
                    dp[y] = max (dp[y], dp[x] + a[i][j]);
                }
                x = 0;
                y = x + PO[i];
                dp[y] = max (dp[y], dp[x] + a[i][j]);
            }
            for (int i = 0; i < nn; i++)
                dp[par[n][i]] = max (dp[par[n][i]], dp[i]);
            for (int i = 0; i < nn; i++)
                dp[i] = max (dp[par[n][i]], dp[i]);
        }
        cout << dp[nn - 1] << endl;
    }
    return 0;
}