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

const int N = 505;
//const int MOD = 1e9+7;
//const int MOD = 998244353;

int n, k;
int dp[N][N];
int a[N], b[N];


void solve () {
    cin >> n >> k;
    int A = 0, B = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
        A += a[i];
        B += b[i];
    }
    int ans = A / k + B / k;
    A %= k;
    B %= k;
    if (A+B < k){
        cout << ans << endl;
        return;
    }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
            dp[i][j] = -1;
    dp[0][0] = 0;
    B = k - B;
    swap (A, B);
    for (int i = 1; i <= n; i++){
        int x = k - b[i], y = a[i];
        if (x < 0)
            x = 0;
        if (y > k)
            y = k;
        y -= x;
        if (y >= 0) {
            for (int j = 0; j < k; j++){
                if (dp[i-1][j] < 0)
                    continue;
                int l = (j + x) % k;
                dp[i][l] = max (dp[i][l], dp[i-1][j] + y);
            }
        }
        for (int j = 0; j < k; j++){
            dp[i][j] = max (dp[i][j], dp[i-1][j]);
            if (dp[i][j] >= k)
                dp[i][j] = k;
        }
    }
    for (int i = 0; i < k; i++){
        int d = (A - i + k) % k;
        if (A <= i && i <= B)
            d = 0;
        if (dp[n][i] >= d){
            cout << ans+1 << endl;
            return;
        }
    }
    cout << ans << endl;
}

main()
{
    ios_base::sync_with_stdio(0);
    int T=1;
    //cin >> T;
    while (T--)
        solve();
}