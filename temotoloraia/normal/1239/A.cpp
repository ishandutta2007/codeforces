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

const ll N = 1000005, MOD = 1e9 + 7;

ll dp[N], DP[N];

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    dp[1] = 1;
    for (int i = 2; i <= max (n, m); i++){
        DP[i] = dp[i - 1];
        dp[i] = (dp[i - 1] + DP[i - 1]) % MOD;
    }
    cout << ((DP[n] + dp[n] + DP[m] + dp[m]) * 2 + MOD - 2) % MOD << endl;
    return 0;
}