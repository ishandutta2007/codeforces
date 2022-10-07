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
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
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

const int N = 505, MOD = 1e9+7;

int n, m;

char A[N][N];

void solve () {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n+1; i++)
        for (int j = 0; j <= m+1; j++)
            A[i][j] = '.';
    int t = 0;
    if (n%3 == 0)
        t = 2;
    else if (n%3 == 1)
        t = 1;
    else if (n%3 == 2)
        t = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            cin >> A[i][j];
            if (i%3 == t)
                A[i][j] = 'X';
        }
    for (int i = t; i+3 <= n; i += 3){
        for (int j = 1; j <= m; j++){
            if (A[i+1][j-1] == '.' && A[i+1][j+1] == '.' && A[i+2][j-1] == '.' && A[i+2][j+1] == '.'){
                A[i+1][j] = 'X';
                A[i+2][j] = 'X';
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++)
            cout << A[i][j];
        cout << endl;
    }
}

main()
{
  //  freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int T=1;
    cin >> T;
    while (T--){
        solve ();
    }
}