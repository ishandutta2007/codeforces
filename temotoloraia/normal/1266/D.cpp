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


#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
/*
#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/STACK: 20000000005")
*/

using namespace std;

const int N = 100005;

int n, m;

ll a[N];

vector < pair < ll, int > > A, B;

vector < int > U, V;
vector < ll > X;

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    //ios_base::sync_with_stdio(0);
    cin >> n >> m;
    while (m--){
        int u, v, x;
        scanf ("%d %d %d", &u, &v, &x);
        a[u] += x;
        a[v] -= x;
    }
    for (int i = 1; i <= n; i++){
        if (a[i] < 0)
            A.pb ({-a[i], i});
        else if (a[i] > 0)
            B.pb ({a[i], i});
    }
    sort (A.begin(), A.end());
    reverse (A.begin(), A.end());
    sort (B.begin(), B.end());
    reverse (B.begin(), B.end());
    int x = (int)A.size(), y = (int)B.size();
    while (x + y > 0){
        ll t = min (A[x - 1].F, B[y - 1].F);
        U.pb (A[x - 1].S);
        V.pb (B[y - 1].S);
        X.pb (t);
        A[x - 1].F -= t;
        B[y - 1].F -= t;
        if (A[x - 1].F == 0){
            x--;
            A.pop_back();
        }
        if (B[y - 1].F == 0){
            y--;
            B.pop_back();
        }
    }
    cout << (int)U.size() << endl;
    for (int i = 0; i < (int)U.size(); i++)
        printf ("%d %d %lld\n", V[i], U[i], X[i]);
    return 0;
}