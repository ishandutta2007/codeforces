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

const int N = 2005;

int n;
int a[N*2], mas[N*2];
int dp[N][N];
int mx[N];

void solve (){
    cin >> n;
    //n *= 2;
    mx[0] = -1;
    for (int i = 1; i <= n*2; i++){
        cin >> a[i];
        mx[i] = -1;
        mas[i] = 0;
        for (int j = i-1; j >= 1; j--)
            if (a[j] > a[i]){
                mas[i] = j;
                break;
            }
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++){
        dp[0][i] = -1;
        dp[i][0] = 1;
    }
    for (int sum = 2; sum <= n*2; sum++){
        for (int j, i = 1; i <= n; i++){
            j = sum - i;
            if (j < 1 || n < j)
                continue;
            dp[i][j] = dp[i-1][j];
            if (dp[j][i-1] > mas[sum])
                dp[i][j] = max (dp[i][j], i);
        }
    }
    if (dp[n][n] > 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--){
        solve ();
    }
}