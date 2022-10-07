#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long int
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

const int N = 1005;

int n;

pair < ll, int > P[N];

vector < int > a, b;

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n;
    int k = 2;
    for (int i = 3; i <= n; i++){
        cout << "2 1 " << k << " " << i << endl;
        fflush (stdout);
        int x;
        cin >> x;
        if (x == -1)
            k = i;
    }
    for (int i = 2; i <= n; i++){
        if (i == k)
            continue;
        cout << "1 1 " << k << " " << i << endl;
        fflush (stdout);
        cin >> P[i].F;
        P[i].S = i;
    }
    sort (P + 1, P + n + 1);
    a.pb (1);
    a.pb (k);
    int t = P[n].S;
    for (int i = 3; i < n; i++){
        int ind = P[i].S;
        cout << "2 1 " << t << " " << ind << endl;
        fflush (stdout);
        int x;
        cin >> x;
        if (x == -1)
            a.pb (ind);
        else
            b.pb (ind);
    }
    a.pb (t);
    reverse (b.begin(), b.end());
    cout << 0 << " ";
    for (int x : a)
        cout << x << " ";
    for (int x : b)
        cout << x << " ";
    cout << endl;
    fflush (stdout);
    return 0;
}