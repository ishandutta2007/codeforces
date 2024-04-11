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

const int N = 1e6 + 5;

void solve (){
    int n, m, k;
    cin >> n >> m >> k;
    k = n / k;
    if (m <= k){
        cout << m << endl;
        return;
    }
    m -= k;
    m = (m - 1) / (n/k - 1) + 1;
    cout << k - m << endl;
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