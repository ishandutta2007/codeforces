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

#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")

#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")

//#pragma comment(linker, "/STACK: 20000000005")
*/

using namespace std;

const int N = 305, MOD = 1e9 + 7;

int F[N][N];
int n, m;
pair < int, int > P[N*N];
int X[N*N], Y[N*N];

void solve () {
    cin >> n >> m;
    for (int i = 1; i <= n*m; i++){
        cin >> P[i].F;
        P[i].S = -i;
    }
    sort (P+1, P+n*m+1);
    for (int i = 1; i <= n*m; i++){
        int ind = -P[i].S;
        int x = (i-1)/m + 1;
        int y = (i-1)%m + 1;
        X[ind] = x;
        Y[ind] = y;
    }
    int ans = 0;
    for (int I = 1; I <= n*m; I++){
        for (int i = 1; i < Y[I]; i++)
            ans += F[X[I]][i];
        F[X[I]][Y[I]]++;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            F[i][j] = 0;
    cout << ans << endl;
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++){
        solve ();
    }
}