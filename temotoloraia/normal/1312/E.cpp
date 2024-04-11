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

//#define int long long

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

const int N = 2005, MOD = 998244353;

int n;
int a[N], b[N];
int dp[N][N], D[N][N];

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = MOD;
    for (int l = 1; l <= n; l++){
        dp[l][l] = 1;
        D[l][l] = a[l];
    }
    for (int l = n; l >= 1; l--)
        for (int r = l + 1; r <= n; r++)
            for (int i = l; i < r; i++){
                dp[l][r] = min (dp[l][r], dp[l][i] + dp[i + 1][r]);
                if (dp[l][i] + dp[i + 1][r] == 2 && D[l][i] == D[i + 1][r]){
                    dp[l][r] = 1;
                    D[l][r] = D[l][i] + 1;
                }
            }
    cout << dp[1][n] << endl;
}