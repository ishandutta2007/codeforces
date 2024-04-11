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

const int N = 300005;

int a[4];
pair < int, int > P[4];


main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> a[1] >> a[2] >> a[3];
    cout << "First" << endl;
    int last = 0;
    while (1){
        for (int i = 1; i <= 3; i++)
            P[i] = {a[i], i};
        sort (P+1, P+4);
        int x = P[2].F - P[1].F;
        int y = P[3].F - P[2].F;
        int d = x + y + y;
        cout << d << endl;
        int p;
        cin >> p;
        a[p] += d;
        if (p == P[3].S)
            continue;
        for (int i = 1; i <= 3; i++)
            P[i] = {a[i], i};
        sort (P+1, P+4);
        x = P[2].F - P[1].F;
        cout << x << endl;
        cin >> p;
        break;
    }
}