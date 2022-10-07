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

const int N = 105, M = 105;

int n, m, nn;
int a[15][N];
int dp[N][M];
int mas[M];

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    //ios_base::sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--){
        cin >> n >> m;
        nn = (1 << n);
        for (int i = 0; i < n; i++)
            for (int j = 1; j <= m; j++)
                scanf ("%d", &a[i][j]);
        for (int j = 1; j <= m; j++){
            for (int i = 1; i < nn; i++)
                dp[j][i] = dp[j - 1][i];
            for (int I = 0; I < n; I++){
                for (int i = 0; i < nn; i++){
                    mas[i] = 0;
                    for (int l = 0; l < n; l++)
                        if ((i & (1 << l)) > 0)
                            mas[i] += a[l][j];
                }
                for (int i = 1; i < nn; i++){
                    for (int y = i; y > 0; y = ((y - 1) & i)){
                        int z = i - y;
                        dp[j][i] = max (dp[j][i], mas[y] + dp[j - 1][z]);
                    }
                }
                for (int i = 0; i < n - 1; i++)
                    swap (a[i][j], a[i + 1][j]);
            }
        }
        cout << dp[m][nn - 1] << endl;
    }
    return 0;
}