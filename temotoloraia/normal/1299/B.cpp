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

const int N = 300005, MOD = 1e9 + 7;

int n;
int x[N], y[N];
int A, B;

main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    if (n % 2 == 1){
        cout << "NO" << endl;
        return 0;
    }
    int X = x[1] + x[n / 2 + 1];
    int Y = y[1] + y[n / 2 + 1];
    for (int i = 1; i <= n / 2; i++)
    if (x[i] + x[i + n/2] != X || y[i] + y[i + n/2] != Y){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}