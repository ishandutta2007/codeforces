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

const int N = 1e5 + 5, MOD = 1e9 + 7;

int B[60];

void solve () {
    int n;
    cin >> n;
    int m = (n + 2) / 3 - 1;
    int p = (n + 2) % 3;
    int k = 0;
    for (; B[k] <= m; k++){
        m -= B[k];
    }
    int A[3];
    A[0] = m;
    A[1] = 0;
    A[2] = 0;
    vector < int > v;
    while (m){
        v.pb (m%4);
        m /= 4;
    }
    reverse (v.begin(), v.end());
    for (int x : v){
        A[1] *= 4;
        A[2] *= 4;
        if (x == 1){
            A[1] += 2;
            A[2] += 3;
        }
        if (x == 2){
            A[1] += 3;
            A[2] += 1;
        }
        if (x == 3){
            A[1] += 1;
            A[2] += 2;
        }
    }
    A[0] += B[k];
    A[1] += 2 * B[k];
    A[2] += 3 * B[k];
    cout << A[p] << endl;
}

main()
{
    //ios_base::sync_with_stdio(0);
    B[0] = 1;
    for (int i = 1; i <= 30; i++)
        B[i] = B[i-1] * 4;
    int T;
    cin >> T;
    while (T--){
        solve ();
    }
    return 0;
}