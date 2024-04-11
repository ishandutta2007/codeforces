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

int n, d;
int a[N];

main()
{
    ios_base::sync_with_stdio(0);
    int tes;
    cin >> tes;
    while (tes--){
        cin >> n >> d;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 1; i < n; i++){
            int nn = d / i;
            if (nn > a[i])
                nn = a[i];
            a[0] += nn;
            d -= nn * i;
        }
        cout << a[0] << endl;
    }
    return 0;
}