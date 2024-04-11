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

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int n, m;

vector < char > V[N];
queue < int > Qr, Qc;

vector < int > A[N], B[N], C[N], D[N];

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    //ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++){
        char ch;
        ch = getchar();
        while (ch != '.' && ch != '#')
            ch = getchar();
        //cin >> ch;
        V[i].pb (ch);
        A[i].pb (0);
        B[i].pb (0);
        C[i].pb (0);
        D[i].pb (0);
    }
    A[0][0] = 1;
    Qr.push (0);
    Qc.push (0);
    while (Qr.size() > 0){
        int r = Qr.front(), c = Qc.front();
        Qr.pop();
        Qc.pop();
        for (int i = 0; i < 2; i++){
            int newr = r + dr[i], newc = c + dc[i];
            if (newr < 0 || n <= newr || newc < 0 || m <= newc)
                continue;
            if (A[newr][newc] == 1 || V[newr][newc] == '#')
                continue;
            A[newr][newc] = 1;
            Qr.push (newr);
            Qc.push (newc);
        }
    }
    B[n - 1][m - 1] = 1;
    Qr.push (n - 1);
    Qc.push (m - 1);
    while (Qr.size() > 0){
        int r = Qr.front(), c = Qc.front();
        Qr.pop();
        Qc.pop();
        for (int i = 2; i < 4; i++){
            int newr = r + dr[i], newc = c + dc[i];
            if (newr < 0 || n <= newr || newc < 0 || m <= newc)
                continue;
            if (B[newr][newc] == 1 || V[newr][newc] == '#')
                continue;
            B[newr][newc] = 1;
            Qr.push (newr);
            Qc.push (newc);
        }
    }
    if (A[n - 1][m - 1] == 0){
        cout << 0 << endl;
        return 0;
    }
    for (int i = n - 1; i >= 0; i--)
    for (int j = 0; j < m; j++){
        if (A[i][j] == 1 && B[i][j] == 1)
            C[i][j] = 1;
        if (i < n - 1 && C[i + 1][j] == 1)
            C[i][j] = 1;
        if (j > 0 && C[i][j - 1] == 1)
            C[i][j] = 1;
    }
    for (int i = 0; i < n; i++)
    for (int j = m - 1; j >= 0; j--){
        if (A[i][j] == 1 && B[i][j] == 1)
            D[i][j] = 1;
        if (i > 0 && D[i - 1][j] == 1)
            D[i][j] = 1;
        if (j < m - 1 && D[i][j + 1] == 1)
            D[i][j] = 1;
    }
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++){
        if (i + j == 0 || i + j == n + m - 2)
            continue;
        bool ok = 1;
        if (i < n - 1 && j > 0 && C[i + 1][j - 1] == 1)
            ok = 0;
        if (i > 0 && j < m - 1 && D[i - 1][j + 1] == 1)
            ok = 0;
        if (ok){
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 2 << endl;
    return 0;
}