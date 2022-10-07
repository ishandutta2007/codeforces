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
//#define int long long

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

int n, m, k;
int a[N];
int b[N];

main()
{
    ios_base::sync_with_stdio(0);
    int tes;
    cin >> tes;
    while (tes--){
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= m; i++){
            b[i] = max (a[i], a[i + n - m]);
        }
        int ans = 0;
        k = m - k;
        if (k <= 0)
            k = 1;
        for (int i = 1; i + k <= m + 1; i++){
            int t = b[i];
            for (int j = i + 1; j < i + k; j++)
                t = min (t, b[j]);
            ans = max (ans, t);
        }
        cout << ans << endl;
    }
    return 0;
}