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

const int N = 1e3 + 5;


void solve (){
    int a, b, t;
    cin >> a >> b >> t;
    if (a + b >= t*2){
        cout << 2 << endl;
        return;
    }
    b = a + b;
    a = a * 2;
    t *= 2;
    t -= b;
    a -= b;
    int n = ((a / t) - 1) / 2;
    n = n * 2 + 1;
    int m = n+2;
    //cout << n << " " << m << " " << a << " " << t << endl;
    if (a * (n + m) <= t * n * m * 2)
        cout << n << endl;
    else
        cout << m << endl;
}

main()
{
    ios_base::sync_with_stdio(0);
    int T=1;
    cin >> T;
    while (T--){
        solve ();
    }
}
/*
1
18 13 18
*/