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

const int N = 3005, MOD = 998244353;

string S, T;
int n, m;
int ans;
int dp[N][N];
int DP[N][N];

main()
{
    ios_base::sync_with_stdio(0);
    cin >> S >> T;
    n = (int)S.size();
    m = (int)T.size();
    S = "#" + S;
    T = "#" + T;
    for (int i = 1; i <= m + 1; i++)
        dp[i][i-1] = 1;
    for (int i = 1; i <= m; i++)
        if (S[1] == T[i])
            dp[i][i] = 1;
    for (int l = m; l >= 1; l--)
        for (int r = l + 1; r <= m; r++){
            int d = r - l + 1;
            if (S[d] == T[l])
                dp[l][r] += dp[l + 1][r];
            if (S[d] == T[r])
                dp[l][r] += dp[l][r - 1];
            dp[l][r] %= MOD;
        }
    DP[n + 1][0] = 1;
    for (int i = n; i >= 1; i--){
        DP[i][0] = n - i + 2;
        for (int j = 1; j <= m; j++){
            DP[i][j] = DP[i + 1][j];
            if (j == m)
                DP[i][j] *= 2;
            if (S[i] == T[j]){
                DP[i][j] += DP[i + 1][j - 1];
            }
            DP[i][j] %= MOD;
        }
    }
    ans += dp[1][m] * (n - m + 1) % MOD;
    for (int L = 1; L <= m; L++){
        //cout << ans << endl;
        //cout << L << " " << dp[L+1][m] << " " << DP[m-L+2][L] << endl;
        ans += dp[L+1][m] * DP[m-L+2][L];
        ans %= MOD;
    }
    ans *= 2;
    ans %= MOD;
    cout << ans << endl;
    return 0;
}