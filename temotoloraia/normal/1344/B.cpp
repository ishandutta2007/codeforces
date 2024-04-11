#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
#define int long long
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

const int N = 1005, INF = 1e17;

int n, m;
char A[N][N];
bool F[N][N];
int R[N], C[N];
int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

void dfs (int r, int c){
    F[r][c] = 1;
    for (int i = 0; i < 4; i++){
        int newr = r + dr[i];
        int newc = c + dc[i];
        if (A[newr][newc] != '#' || F[newr][newc] == 1)
            continue;
        dfs (newr, newc);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            cin >> A[i][j];
            if (A[i][j] == '#'){
                R[i] = 1;
                C[j] = 1;
            }
        }
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++)
        if (R[i] == 0)
            x = 1;
    for (int i = 1; i <= m; i++)
    if (C[i] == 0)
        y = 1;
    if (x != y){
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= n; i++){
        x = 0;
        for (int j = 1; j <= m; j++)
            if (A[i][j] == '#' && A[i][j-1] != '#')
                x++;
        if (x > 1){
            cout << -1 << endl;
            return;
        }
    }
    for (int j = 1; j <= m; j++){
        x = 0;
        for (int i = 1; i <= n; i++)
            if (A[i][j] == '#' && A[i-1][j] != '#')
                x++;
        if (x > 1){
            cout << -1 << endl;
            return;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++){
        if (F[i][j] == 0 && A[i][j] == '#'){
            dfs (i, j);
            ans++;
        }
    }
    cout << ans << endl;
}

main()
{
    ios_base::sync_with_stdio(0);
    int T=1;
    //cin >> T;
    while (T--)
        solve();
}