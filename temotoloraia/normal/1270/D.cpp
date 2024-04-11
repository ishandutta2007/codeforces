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

#pragma GCC optimize ("O3")
/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/STACK: 20000000005")
*/

using namespace std;

const int N = 1000005;

int a[N];

main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        a[i] = i;
    cout << "? ";
    for (int i = 1; i <= k; i++)
        cout << a[i] << " ";
    cout << endl;
    int x, y;
    cin >> x >> y;
    swap (a[x], a[k + 1]);
    cout << "? ";
    for (int i = 1; i <= k; i++)
        cout << a[i] << " ";
    cout << endl;
    int z;
    cin >> z >> z;
    swap (a[x], a[k + 1]);
    int m, d;
    if (z < y){
        m = 1;
        d = 1;
    }
    else {
        m = k;
        d = -1;
    }
    for (int I = 1; I <= k; I++){
        if (I == x)
            continue;
        swap (a[I], a[k + 1]);
        cout << "? ";
        for (int i = 1; i <= k; i++)
            cout << a[i] << " ";
        cout << endl;
        int t;
        cin >> t >> t;
        if (t == y)
            m += d;
        swap (a[I], a[k + 1]);
    }
    cout << "! " << m << endl;
}