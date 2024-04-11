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

const int N = 1000005, MOD = 1e9+7;


void solve () {
    int n;
    cin >> n;
    vector < int > A, B;
    for (int i = 1; i <= n*2; i++){
        int x, y;
        scanf ("%lld%lld",&x,&y);
        x=x*x;
        y=y*y;
        if (x==0)
            B.pb (y);
        else
            A.pb (x);
    }
    sort (A.begin(), A.end());
    sort (B.begin(), B.end());
    double D = 0, d;
    for (int i = 0; i < n; i++){
        d = sqrt (A[i] + B[i]);
        D += d;
    }
    printf ("%.10f\n", D);
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    //ios_base::sync_with_stdio(0);
    int T=1;
    cin >> T;
    while (T--){
        solve ();
    }
}