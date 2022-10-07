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

const int N = 100005;
//const int MOD = 1e9+7;
const int MOD = 998244353;

int mas[26];

void solve () {
    int n;
    cin >> n;
    int x = 1;
    n--;
    vector < int > V;
    while (n){
        int y = 0;
        if (n <= x*2)
            y = n;
        else {
            y = min (n / 2, x*2);
        }
        n -= y;
        V.pb (y-x);
        x = y;
    }
    cout << (int)V.size() << endl;
    for (int x : V)
        cout << x << " ";
    cout << endl;
}

main()
{
    ios_base::sync_with_stdio(0);
    int T=1;
    cin >> T;
    while (T--)
        solve();
}