#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
//#define ll long long
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
/*
#pragma comment(linker, "/STACK: 20000000005")
*/


using namespace std;

const int N = 200005, MOD = 998244353;

int n, m, k;
int x[N], y[N];
int X[N], Y[N];

main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
        cin >> x[i] >> y[i];
    for (int i = 1; i <= k; i++)
        cin >> X[i] >> Y[i];
    cout << n - 1 + m - 1 + n*m - 1 << endl;
    for (int i = 1; i < n; i++)
        cout << "D";
    for (int i = 1; i < m; i++)
        cout << "L";
    for (int i = 1; i <= m; i++){
        string s = "U";
        if (i % 2 == 0)
            s = "D";
        for (int j = 1; j < n; j++)
            cout << s;
        if (i == m)
            break;
        cout << "R";
    }
    cout << endl;
    return 0;
}