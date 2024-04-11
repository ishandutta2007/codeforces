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

const int N = 105, MOD = 1e9 + 7;

int dr[6] = {-2, -1, 0, 0, 1, 2};
int dc[6] = {0, -1, -2, 2, 1, 0};

int n;

int a[N][N];

void dfs (int r, int c){
    for (int i = 0; i < 6; i++){
        int newr = r + dr[i], newc = c + dc[i];
        if (newr < 1 || n < newr || newc < 1 || n < newc)
            continue;
        if (a[newr][newc] != -1)
            continue;
        cout << "? " << min (r, newr) << " " << min (c, newc) << " " << max (r, newr) << " " << max (c, newc) << endl;
        fflush (stdout);
        int x;
        cin >> x;
        if (x == 1)
            a[newr][newc] = a[r][c];
        else
            a[newr][newc] = 1 - a[r][c];
        dfs (newr, newc);
    }
}


main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = -1;
    a[1][1] = 1;
    a[n][n] = 0;
    dfs (1, 1);
    for (int i = 1; i <= n - 2; i += 2){
        if (a[i][i] == a[i + 2][i + 2])
            continue;
        int j = i;
        int x, y;
        cout << "? " << i << " " << j << " " << i + 2 << " " << j + 1 << endl;
        cin >> x;
        if (x){
            a[i + 2][j + 1] = a[i][j];
            dfs (i + 2, j + 1);
            break;
        }
        cout << "? " << i << " " << j + 1 << " " << i + 2 << " " << j + 2 << endl;
        cin >> y;
        if (y){
            a[i][j + 1] = a[i + 2][j + 2];
            dfs (i, j + 1);
            break;
        }
        if (a[i + 1][j + 1] == 1){
            a[i + 2][j + 1] = 0;
            dfs (i + 2, j + 1);
            break;
        }
        if (a[i + 1][j + 1] == 0){
            a[i][j + 1] = 1;
            dfs (i, j + 1);
            break;
        }
        break;
    }
    cout << "!" << endl;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            cout << a[i][j];
        cout << endl;
    }
    return 0;
}