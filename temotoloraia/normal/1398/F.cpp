#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
//#define int long long
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


const int N = 1000005, INF = 1e12;

int n;
string S, A[2];
int a[2][N];

int D;

int cnt (int x, int id){
    while (x >= D){
        int y = x - D + 1;
        if (a[id][y] >= x)
            return y-1;
        x = a[id][y];
    }
    return -1;
}

void solve () {
    cin >> n >> S;
    S = "#" + S;
    A[0] = A[1] = S;
    for (int i = 1; i <= n; i++){
        if (S[i] == '?'){
            A[0][i] = '0';
            A[1][i] = '1';
        }
    }
    for (int I = 0; I < 2; I++){
        a[I][n] = n;
        for (int i = n-1; i >= 1; i--){
            if (A[I][i] == A[I][i+1])
                a[I][i] = a[I][i+1];
            else
                a[I][i] = i;
        }
    }
    for (D = 1; D <= n; D++){
        int x = n, ans = 0;
        while (x>0){
            int p[2] = {x, x}, pas = -1;
            while (1){
                int id = 1;
                if (p[0] >= p[1])
                    id = 0;
                if (p[id] < D)
                    break;
                int y = p[id] - D + 1;
                if (a[id][y] >= p[id]){
                    pas = y-1;
                    break;
                }
                p[id] = a[id][y];
            }
            x = pas;
            if (x == -1)
                break;
            ans++;
        }
        printf ("%d ", ans);
    }
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    //ios_base::sync_with_stdio(0);
    int T=1;
    //cin >> T;
    while (T--)
        solve ();
}