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

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
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

const int N = 300005, INF = 1e18;


string S;
int n, x;

void solve () {
    cin >> S >> x;
    n = (int)S.size();
    string A = "", B = "";
    for (int i = 0; i < n; i++){
        A += "1";
        B += "0";
    }
    for (int i = 0; i < n; i++){
        if (S[i] == '1')
            continue;
        if (i + x < n)
            A[i+x] = '0';
        if (i >= x)
            A[i-x] = '0';
    }
    for (int i = 0; i < n; i++){
        if (A[i] == '0')
            continue;
        if (i >= x)
            B[i-x] = '1';
        if (i + x < n)
            B[i+x] = '1';
    }
    if (S != B)
        cout << -1 << endl;
    else
        cout << A << endl;
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    //freopen ("sequence.in", "r", stdin);freopen ("sequence.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int T=1;
    cin >> T;
    while (T--)
        solve ();
}