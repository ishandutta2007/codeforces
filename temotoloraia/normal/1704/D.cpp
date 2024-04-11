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

const int N = 300005, MOD = 1e9 + 7, INF = 1e11;

int n, m;
int a[N];

void solve () {
    cin >> n >> m;
    int mx = 0, mn = -1;
    for (int i = 1; i <= n; i++){
        a[i] = 0;
        for (int x, j = 1; j <= m; j++){
            cin >> x;
            a[i] += x * j;
        }
        mx = max (mx, a[i]);
        if (mn == -1)
            mn = a[i];
        else
            mn = min (mn, a[i]);
    }
    for (int i = 1; i <= n; i++)
        if (a[i] == mx){
            cout << i << " " << mx - mn << endl;
            return;
        }
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin >> T;
    for (int i = 1; i <= T; i++){
        solve ();
    }
}