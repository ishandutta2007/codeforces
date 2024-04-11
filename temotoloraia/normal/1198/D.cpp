#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long int
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
/*
#pragma GCC optimize ("O3")
#pragma comment(linker, "/STACK: 20000000005")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
*/
using namespace std;

const int N = 55, M = 5000;

int n;
char ch[N][N];
int dp[N][N][N][N];

vector < int > a1[M], a2[M], a3[M], a4[M];
int np[M];



main()
{
    //freopen ("in.txt", "r", stdin);freopen ("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    n = 50;
    cin >> n;
    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= n; y++)
            for (int X = x; X <= n; X++)
                for (int Y = y; Y <= n; Y++){
                    dp[x][y][X][Y] = max (X - x + 1, Y - y + 1);
                    int S = (Y - y + 1) * (X - x + 1);
                    if (S > 1){
                        np[S]++;
                        a1[S].pb (x);
                        a2[S].pb (y);
                        a3[S].pb (X);
                        a4[S].pb (Y);
                    }
                }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            ch[i][j] = '.';
            cin >> ch[i][j];
            if (ch[i][j] == '.')
                dp[i][j][i][j] = 0;
        }
    int pas;
    for (int S = 2; S <= n * n; S++)
    for (int I = 0; I < np[S]; I++){
        int x = a1[S][I], y = a2[S][I], X = a3[S][I], Y = a4[S][I];
        pas = dp[x][y][X][Y];
        if (pas == 0)
            continue;
        for (int t = x; t < X; t++)
            pas = min (pas, dp[x][y][t][Y] + dp[t + 1][y][X][Y]);
        for (int t = y; t < Y; t++)
            pas = min (pas, dp[x][y][X][t] + dp[x][t + 1][X][Y]);
        dp[x][y][X][Y] = pas;
    }
    cout << dp[1][1][n][n] << endl;
    return 0;
}