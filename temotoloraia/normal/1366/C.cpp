#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
#define int long long
//#define int __int128
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

const int N = 5005, MOD = 1e9 + 7;

int n, m;
int a[N], b[N];

void solve (){
    cin >> n >> m;
    int A = n + m - 1;
    for (int i = 1; i <= n+m; i ++)
        a[i] = b[i] = 0;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++){
        int x;
        cin >> x;
        if (x == 0)
            a[i+j-1]++;
        else
            b[i+j-1]++;
    }
    int ans = 0;
    for (int i = 1; i*2 < A+1; i++)
        ans += min (a[i] + a[A - i + 1], b[i] + b[A + 1 - i]);
    cout << ans << endl;
}


main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--)
        solve();
}