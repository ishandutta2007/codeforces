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
//#define int long long

using namespace std;

const int N = 105;

int n;
int a[N];
int x[2];
int ans;

int dp[N][N][2];

main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        x[i % 2]++;
    }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            for (int k = 0; k < 2; k++)
                dp[i][j][k] = 1e9;
    dp[0][0][0] = 0;
    dp[0][0][1] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= i; j++){
            int p[2] = {j, i - j};
            for (int k = 0; k < 2; k++){
                if (a[i] && ((a[i] % 2) != k))
                    continue;
                if (p[k] == 0)
                    continue;
                p[k]--;
                dp[i][j][k] = min (dp[i - 1][p[0]][k], dp[i - 1][p[0]][1 - k] + 1);
                p[k]++;
            }
        }
    }
    cout << min (dp[n][x[0]][0], dp[n][x[0]][1]) << endl;
}