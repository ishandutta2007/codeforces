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
/*
#pragma comment(linker, "/STACK: 20000000005")
*/

using namespace std;



const int N = 1000005, INF = 1e8;

int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n, m;
vector < char > A[N];
vector < int > D[N];
vector < int > dp[N];


queue < pair < int, int > > Q;

bool check (int T){
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            if (D[i][j] <= T)
                dp[i][j] = INF;
            else {
                dp[i][j] = 0;
                Q.push ({i, j});
            }
        }
    while (Q.size() > 0){
        int r = Q.front().F, c = Q.front().S;
        Q.pop();
        for (int i = 0; i < 8; i++){
            int newr = r + dr[i], newc = c + dc[i];
            if (newr < 1 || n < newr || newc < 1 || m < newc)
                continue;
            if (dp[newr][newc] > dp[r][c] + 1){
                dp[newr][newc] = dp[r][c] + 1;
                Q.push ({newr, newc});
            }
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (A[i][j] == 'X' && dp[i][j] > T)
                return 0;
    return 1;
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    //ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i <= m + 1; i++){
        A[0].pb ('.');
        A[n + 1].pb ('.');
    }
    for (int i = 1; i <= n; i++){
        A[i].pb ('.');
        char ch;
        for (int j = 1; j <= m; j++){
            ch = getchar();
            while (ch != '.' && ch != 'X')
                ch = getchar();
            A[i].pb (ch);
        }
        A[i].pb ('.');
    }
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++){
            D[i].pb (0);
            dp[i].pb (0);
            if (A[i][j] == 'X')
                D[i][j] = INF;
            else
                Q.push ({i, j});
        }
    while (Q.size() > 0){
        int r = Q.front().F, c = Q.front().S;
        Q.pop();
        for (int i = 0; i < 8; i++){
            int newr = r + dr[i], newc = c + dc[i];
            if (newr < 1 || n < newr || newc < 1 || m < newc)
                continue;
            if (D[newr][newc] > D[r][c] + 1){
                D[newr][newc] = D[r][c] + 1;
                Q.push ({newr, newc});
            }
        }
    }
    int L = 0, R = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            R = max (R, D[i][j] - 1);
    while (L < R){
        int mid = L + R + 1 >> 1;
        if (check (mid))
            L = mid;
        else
            R = mid - 1;
    }
    cout << L << endl;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++)
            if (D[i][j] > L)
                printf ("X");
            else
                printf (".");
        printf ("\n");
    }
    return 0;
}