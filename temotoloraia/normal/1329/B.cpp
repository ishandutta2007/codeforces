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

const int N = 100005;
int MOD = 1e9 + 7;

int B[40];

int dp[N], a[N];

main()
{
    ios_base::sync_with_stdio(0);
    B[0] = 1;
    for (int i = 1; i <= 30; i++)
        B[i] = B[i - 1] * 2;
    int tes;
    cin >> tes;
    while (tes--){
        int D;
        cin >> D >> MOD;
        int d = 30;
        while (B[d] > D)
            d--;
        for (int i = 0; i < d; i++)
            a[i] = B[i];
        a[d] = D - B[d] + 1;
        dp[0] = 1;
        int ans = 1;
        for (int i = 1; i <= d; i++){
            dp[i] = 1;
            for (int j = 0; j < i; j++)
                dp[i] += dp[j];
            dp[i] = dp[i] % MOD * a[i] % MOD;
            ans = (ans + dp[i]) % MOD;
        }
        cout << ans%MOD << endl;
    }
    return 0;
}