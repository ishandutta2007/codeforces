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

const int N = 300005;

int a[30], B[30];

void solve () {
    int n, x;
    cin >> n;
    B[0] = 1;
    for (int i = 1; i <= 20; i++)
        B[i] = B[i-1] * 2;
    for (int i = 1; i <= n; i++){
        cin >> x;
        for (int j = 0; j < 20; j++){
            a[j] += x&1;
            x >>= 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        x = 0;
        for (int j = 0; j < 20; j++){
            if (a[j]){
                x += B[j];
                a[j]--;
            }
        }
        ans += x*x;
    }
    cout << ans << endl;
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int T=1;
    //cin >> T;
    while (T--)
        solve ();
}