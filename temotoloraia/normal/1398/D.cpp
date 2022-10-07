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


const int N = 205, INF = 1e12;

int n, m, k;
int a[N], b[N], c[N];
int dp[N][N][N];


void solve () {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    for (int i = 1; i <= k; i++)
        cin >> c[i];
    sort (a+1,a+n+1);reverse (a+1,a+n+1);
    sort (b+1,b+m+1);reverse (b+1,b+m+1);
    sort (c+1,c+k+1);reverse (c+1,c+k+1);
    for (int x = 0; x <= n; x++)
        for (int y = 0; y <= m; y++)
            for (int z = 0; z <= k; z++){
                if (x)
                    dp[x][y][z] = max (dp[x][y][z], dp[x-1][y][z]);
                if (y)
                    dp[x][y][z] = max (dp[x][y][z], dp[x][y-1][z]);
                if (z)
                    dp[x][y][z] = max (dp[x][y][z], dp[x][y][z-1]);
                if (y && z)
                dp[x][y][z] = max (dp[x][y][z], dp[x][y-1][z-1] + b[y]*c[z]);
                if (x && z)
                dp[x][y][z] = max (dp[x][y][z], dp[x-1][y][z-1] + a[x]*c[z]);
                if (x && y)
                dp[x][y][z] = max (dp[x][y][z], dp[x-1][y-1][z] + a[x]*b[y]);
            }
    cout << dp[n][m][k] << endl;
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int T=1;
    //cin >> T;
    while (T--)
        solve ();
}