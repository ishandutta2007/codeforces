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


const int N = 100005, INF = 1e9;

int n, d, m, ans;
int a[N], b[N];

void solve () {
    cin >> n >> d >> m;
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++){
        int X;
        cin >> X;
        if (X > m)
            a[++x] = X;
        else
            b[++y] = X;
    }
    sort (a+1, a+x+1);
    reverse (a+1, a+x+1);
    sort (b+1, b+y+1);
    reverse (b+1, b+y+1);
    for (int i = 1; i <= n; i++)
        a[i] += a[i-1];
    for (int i = 1; i <= n; i++)
        b[i] += b[i-1];
    d++;
    ans = b[n];
    for (int i = 1; ((i-1)*d + 1) <= n; i++){
        int j = n - ((i-1)*d + 1);
        ans = max (ans, a[i] + b[j]);
    }
    cout << ans << endl;
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int T = 1;
    //cin >> T;
    while (T--)
        solve ();
}