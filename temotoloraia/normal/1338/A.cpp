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
#define int long long

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

const int N = 1e5 + 5, MOD = 1e9 + 7;


int B[40];
int a[N];

void solve () {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] >= a[i-1] || i==1)
            continue;
        int D = a[i-1] - a[i];
        for (int j = 0; j <= 30; j++)
            if (B[j] <= D)
                ans = max (ans, j+1);
        a[i] = a[i-1];
    }
    cout << ans << endl;
}

main()
{
    //ios_base::sync_with_stdio(0);
    B[0] = 1;
    for (int i = 1; i <= 30; i++)
        B[i] = B[i-1] * 2;
    int T;
    cin >> T;
    while (T--){
        solve ();
    }
    return 0;
}