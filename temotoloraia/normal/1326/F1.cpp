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

const int N = 1000005, MOD = 1e9 + 7;
//998244353;

int n;
int g[100][100];
int BI[N];
int dp[15][130][(1<<14)+5];
//int D1[15][130], D2[15][130];
int ans[N];
int rev[N];
int A, B;
vector < int > V[20];

int PO[100];

int REV (int x){
    vector < int > v (B - 1, 0);
    for (int i = 0; i < B - 1; i++){
        v[i] = x % 2;
        x /= 2;
    }
    x = 0;
    for (int i = 0; i < B - 1; i++)
        x = x * 2 + v[i];
    return x;
}

main()
{
    ios_base::sync_with_stdio(0);
    for (int i = 0; i <= 30; i++)
        PO[i] = (1 << i);
    cin >> n;
    for (int i = 1; i < PO[n]; i++){
        BI[i] = BI[(i & (i - 1))] + 1;
        V[BI[i]].pb (i);
    }
    for (int i = 0; i < n; i++)
        dp[i][0][PO[i]] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            char ch;
            cin >> ch;
            g[i][j] = ch - '0';
        }
    A = n / 2, B = (n + 1) / 2;
    for (int i = 0; i < PO[n]; i++)
        rev[i] = REV (i);
    for (int bit = 1; bit < PO[n]; bit++){
        int nn = BI[bit];
        if (nn >= B)
            continue;
        for (int x = 0; x < n; x++){
            if ((bit & PO[x]) == 0)
                continue;
            for (int y = 0; y < n; y++){
                if ((bit & PO[y]) > 0)
                    continue;
                for (int b = 0; b < PO[nn - 1]; b++){
                    int c = (bit | PO[y]);
                    int P = b * 2 + g[x][y];
                    dp[y][P][c] += dp[x][b][bit];
                }
            }
        }
    }
    for (int X : V[A]){
        int Y = PO[n] - 1 - X, P;
        for (int x = 0; x < n; x++){
            if ((PO[x] & X) == 0)
                continue;
            for (int y = 0; y < n; y++){
                if ((PO[y] & Y) == 0)
                    continue;
                for (int p = 0; p < PO[A - 1]; p++)
                    for (int q = 0; q < PO[B - 1]; q++){
                        P = p * PO[B] + g[x][y] * PO[B - 1] + rev[q];
                        ans[P] += dp[x][p][X] * dp[y][q][Y];
                    }
            }
        }
    }
    for (int i = 0; i < PO[n - 1]; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}