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

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
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

const int N = 5005, INF = 1e8;

int n, dp[N][N];

void solve () {
    cin >> n;
    for (int i = 0; i <= n+1; i++)
        dp[0][i] = i;
    for (int x, i = 1; i <= n; i++){
        for (int j = 0; j <= n+1; j++)
            dp[i][j] = INF;
        cin >> x;
        int ch = 0;
        if (x)
            ch++;
        dp[i][0] = dp[i-1][0] + ch;
        int pas = dp[i-1][0];
        int t = min (n, x);
        for (int j = 1; j <= t; j++){
            pas = min (pas + 1, dp[i-1][j]);
            dp[i][j] = pas;
            if (j < x)
                dp[i][j]++;
        }
        for (int j = n; j >= 0; j--)
            dp[i][j] = min (dp[i][j], dp[i][j+1]);
    }
    int ans = n;
    for (int j = 0; j <= n; j++)
        ans = min (ans, dp[n][j]);
    cout << ans << endl;
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    //freopen ("sequence.in", "r", stdin);freopen ("sequence.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int T=1;
    //cin >> T;
    while (T--)
        solve ();
}