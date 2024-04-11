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

const int N = 10005, INF = 1e13;

int n, m;
int G, R;
int a[N];
int dp[N][1005];
//bool F[N][1005];

queue < pair < int, int > > A, B;

main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    cin >> G >> R;
    sort (a + 1, a + m + 1);
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < G; j++)
            dp[i][j] = INF;
    dp[1][0] = 0;
    A.push ({1, 0});
    while (A.size() > 0){
        while (A.size() > 0){
            int k = A.front().F, p = A.front().S;
            A.pop();
            if (k < m){
                int q = p + a[k + 1] - a[k];
                if (q <= G){
                int D = dp[k][p];
                if (q == G){
                    D++;
                    q = 0;
                }
                if (dp[k+1][q] > D){
                dp[k+1][q] = D;
                if (q)
                    A.push ({k+1, q});
                else
                    B.push ({k+1, q});
                }}
            }
            if (k > 1){
                int q = p + a[k] - a[k-1];
                if (q > G)
                    continue;
                int D = dp[k][p];
                if (q == G){
                    D++;
                    q = 0;
                }
                if (dp[k-1][q] <= D)
                    continue;
                dp[k-1][q] = D;
                if (q)
                    A.push ({k-1, q});
                else
                    B.push ({k-1, q});
            }
        }
        A = B;
        while (B.size() > 0)
            B.pop();
    }
    int ans = INF;
    for (int i = 0; i < G; i++){
        int pas = dp[m][i] * (G + R) + i;
        if (i == 0 && dp[m][i] > 0)
            pas -= R;
        if (pas < ans)
            ans = pas;
    }
    if (ans == INF)
        ans = -1;
    cout << ans << endl;
}