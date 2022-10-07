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

const int N = 1000005, MOD = 1e9 + 7;

int n, x;
int a[N];

main()
{
    ios_base::sync_with_stdio(0);
    int tes;
    cin >> tes;
    while (tes--){
        cin >> n >> x;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort (a + 1, a + n + 1);
        int ans = (x + a[n] - 1) / a[n];
        if (ans <= 1)
            ans = 2;
        for (int i = 1; i <= n; i++)
            if (a[i] == x)
                ans = 1;
        cout << ans << endl;
    }
    return 0;
}