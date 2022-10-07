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

const int N = 5005, MM = 100005;

map < ll, pair < int, int > > M;

ll V[20][N];

pair < int, int > g[20][N];

int n;
int nn[20];
ll SS[20];

ll S;
int B[100];
pair < int, int > P[MM];

int X, Y;

bool fix[20];

void go (int x, int y, int BB){
    if (fix[x] == 1){
        if (x == X && y == Y)
            P[BB] = {X, Y};
        return;
    }
    fix[x] = 1;
    BB += B[x - 1];
    go (g[x][y].F, g[x][y].S, BB);
}

int dp[MM], fr[MM];

ll C[100], D[100];

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n;
    B[0] = 1;
    for (int i = 1; i <= n; i++)
        B[i] = B[i - 1] * 2;
    for (int i = 1; i <= n; i++){
        cin >> nn[i];
        for (int j = 1; j <= nn[i]; j++){
            ll x;
            cin >> x;
            M[x] = {i, j};
            V[i][j] = x;
            SS[i] += x;
            S += x;
        }
    }
    if (S % n != 0){
        cout << "NO" << endl;
        return 0;
    }
    S /= n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= nn[i]; j++){
            ll s = S - SS[i] + V[i][j];
            g[i][j] = M[s];
        }
    }
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= nn[i]; j++){
        for (int l = 1; l <= n; l++)
            fix[l] = 0;
        fix[0] = 1;
        X = i;
        Y = j;
        go (i, j, 0);
    }
    dp[0] = 1;
    for (int b = 1; b < B[n]; b++){
        for (int c = b; c > 0; c = ((c - 1) & b)){
            if (P[c].F != 0 && dp[(b^c)] == 1){
                dp[b] = 1;
                fr[b] = (b^c);
                break;
            }
        }
    }
    if (dp[B[n] - 1] == 0){
        cout << "NO" << endl;
        return 0;
    }
    int b = B[n] - 1;
    while (b){
        int bb = (b ^ fr[b]);
        X = P[bb].F;
        Y = P[bb].S;
        int x = X, y = Y;
        while (1){
            int z = g[x][y].F, t = g[x][y].S;
            C[z] = S - SS[x] + V[x][y];
            D[z] = x;
            x = z;
            y = t;
            if (x == X && y == Y)
                break;
        }
        b = (b ^ bb);
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++)
        cout << C[i] << " " << D[i] << endl;
    return 0;
}